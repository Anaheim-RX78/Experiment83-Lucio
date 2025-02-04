#include "LifeComponent.h"
#include "Character83.h"
#include "MainInstance.h"

ULifeComponent::ULifeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void ULifeComponent::BeginPlay()
{
	Super::BeginPlay();
}


void ULifeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ACharacter83* Character = Cast<ACharacter83>(GetOwner());

	// If damaged, set the danger state
	if (!IsDamaged) return;
	if (DangerTimer < DangerInMilliseconds)
	{
		DangerTimer += DeltaTime;
	}
	else
	{
		// After a delay has passed, we remove the invincibility, the slowed down velocity, and the danger state 
		IsDamaged = false;
		Character->HasSlowedDown = false;
		IsInvincible = false;
		DangerTimer = 0;
		InvincibilityFlashTimer = 0;
		InvincibilityTimer = 0;
	}

	// Toggling visibility on and off to show invincibility
	if (!IsInvincible) return;
	InvincibilityFlashTimer += DeltaTime;
	if (InvincibilityFlashTimer >= InvincibilityFlashInterval)
	{
		InvincibilityFlashTimer = 0;
		ToggleVisibility();
	}
	
	if (InvincibilityTimer < InvincibilityInMilliseconds)
	{
		InvincibilityTimer += DeltaTime;
	}
	else
	{
		IsInvincible = false;
		InvincibilityTimer = 0;
		InvincibilityFlashTimer = 0;
		GetOwner()->SetActorHiddenInGame(false);
	}
}

void ULifeComponent::Damage()
{
	ACharacter83* Character = Cast<ACharacter83>(GetOwner());
	if (Character->PowerUpInvincibility) return; // Invincibility given by power-up
	if (Character && Character->IsBarrierUp)
	{
		// If barrier is up, remove it and cancel damage
		Character->TurnOffBarrier();
		return;
	}
	
	if (IsInvincible) return;
	if (!IsDamaged)
	{
		// The character becomes damaged, temporarily invincible, and slowed down
		IsDamaged = true;
		Character->HasSlowedDown = true;
		IsInvincible = true;
	}
	else
	{
		// If the character is already damaged, it dies and saves the score
		Character->OnDeath.Broadcast();
	}
}

void ULifeComponent::ToggleVisibility()
{
	GetOwner()->SetActorHiddenInGame(IsVisible);
	IsVisible = !IsVisible;
}


