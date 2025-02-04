#include "Inventory.h"
#include "Character83.h"


UInventory::UInventory()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	if (ACharacter83* Character = Cast<ACharacter83>(GetOwner()))
	{
		// Saving character reference to run power-up functions
		CharacterRef = Character;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("INVENTORY MUST BE CHILD OF CHARACTER 83"));	
	}
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// If an item is active, the inventory is "OnHold" so no more items can be used
	if (!IsOnHold) return;
	OnHoldTimer += DeltaTime;
	if (OnHoldTimer >= OnHoldTimeSeconds)
	{
		OnHoldTimer = 0.0f;
		IsOnHold = false;
		// Running cleanup function and emptying primary slot 
		PrimarySlot->CleanupPowerUp(CharacterRef);
		PrimarySlot = SecondarySlot;
		SecondarySlot = nullptr;
		OnUpdate.Broadcast();
	}
}

void UInventory::AddItem(UPowerUpData* ItemData)
{
	if (PrimarySlot && SecondarySlot)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Red,
			TEXT("Slots are full")
		);
		// When slots are full, nothing gets added
		return;
	}
	
	if (PrimarySlot)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Red,
			FString::Printf(TEXT("Filling secondary slot with: %s"), *ItemData->PrettyName)
		);
		// Filling secondary slot
		SecondarySlot = ItemData;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Red,
			FString::Printf(TEXT("Filling first slot with: %s"), *ItemData->PrettyName)
		);
		// Filling primary slot
		PrimarySlot = ItemData;	
	}
	OnUpdate.Broadcast();
}

void UInventory::UseItem()
{
	if (!PrimarySlot || IsOnHold) return;

	GEngine->AddOnScreenDebugMessage(
		-1,
		5.f,
		FColor::Red,
		FString::Printf(TEXT("Using powerup: %s"), *PrimarySlot->PrettyName)
	);

	// Using power-up and setting up OnHold timer 
	PrimarySlot->UsePowerUp(CharacterRef);
	IsOnHold = true;
	OnHoldTimeSeconds = PrimarySlot->PowerUpDuration;
}

