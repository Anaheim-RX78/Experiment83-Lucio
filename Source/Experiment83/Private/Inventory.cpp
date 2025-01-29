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
			TEXT("Both full")
		);
		return;
	}
	
	if (PrimarySlot)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Red,
			TEXT("Primary is full")
		);
		SecondarySlot = ItemData;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Red,
			TEXT("Filling first slot")
		);
		PrimarySlot = ItemData;	
	}
}

void UInventory::UseItem()
{
	if (!PrimarySlot) return;

	PrimarySlot->UsePowerUp(CharacterRef);
	IsOnHold = true;
	OnHoldTimer = PrimarySlot->PowerUpDuration;
}

