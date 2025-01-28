// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LifeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXPERIMENT83_API ULifeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULifeComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void Damage();
	
	UPROPERTY(VisibleAnywhere, Category = Damage)
	bool IsDamaged = false;

	UPROPERTY(EditAnywhere, Category = Damage)
	float DangerInMilliseconds = 7000;

	UPROPERTY(VisibleAnywhere, Category = Damage)
	float DangerTimer = 0;

	UFUNCTION()
	void ToggleVisibility();
	
	UPROPERTY(VisibleAnywhere, Category = Invincibility)
	bool IsInvincible = false;

	UPROPERTY(EditAnywhere, Category = Invincibility)
	bool IsVisible = true;
	
	UPROPERTY(EditAnywhere, Category = Invincibility)
	float InvincibilityFlashInterval = 300;

	UPROPERTY(VisibleAnywhere, Category = Invincibility)
	float InvincibilityFlashTimer = 0;
	
	UPROPERTY(EditAnywhere, Category = Invincibility)
	float InvincibilityInMilliseconds = 2000;

	UPROPERTY(VisibleAnywhere, Category = Invincibility)
	float InvincibilityTimer = 0;
		
};
