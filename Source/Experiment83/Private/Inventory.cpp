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

	if (!IsOnHold) return;
	OnHoldTimer += DeltaTime;
	if (OnHoldTimer >= OnHoldTimeSeconds)
	{
		OnHoldTimer = 0.0f;
		IsOnHold = false;
		PrimarySlot->CleanupPowerUp(CharacterRef);
		PrimarySlot = SecondarySlot;
		SecondarySlot = nullptr;
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
		PrimarySlot = ItemData;	
	}
}

void UInventory::UseItem()
{
	if (!PrimarySlot) return;

	GEngine->AddOnScreenDebugMessage(
		-1,
		5.f,
		FColor::Red,
		FString::Printf(TEXT("Using powerup: %s"), *PrimarySlot->PrettyName)
	);

	PrimarySlot->UsePowerUp(CharacterRef);
	IsOnHold = true;
	OnHoldTimeSeconds = PrimarySlot->PowerUpDuration;
}

