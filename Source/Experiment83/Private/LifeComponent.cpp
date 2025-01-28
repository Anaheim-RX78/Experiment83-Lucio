#include "LifeComponent.h"

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

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Format(TEXT("IsInvincible, IsVisible, IsDamaged: {0}, {1}, {2}"), {IsInvincible, IsVisible, IsDamaged}));

	if (!IsDamaged) return;
	if (DangerTimer < DangerInMilliseconds)
	{
		DangerTimer += DeltaTime;
	}
	else
	{
		IsDamaged = false;
		IsInvincible = false;
		DangerTimer = 0;
		InvincibilityFlashTimer = 0;
		InvincibilityTimer = 0;
	}

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
	if (IsInvincible) return;
	if (!IsDamaged)
	{
		IsDamaged = true;
		IsInvincible = true;
	}
	else
	{
		GetOwner()->Destroy();
	}
}

void ULifeComponent::ToggleVisibility()
{
	GetOwner()->SetActorHiddenInGame(IsVisible);
	IsVisible = !IsVisible;
}


