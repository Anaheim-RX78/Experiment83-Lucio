// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerUpData.h"
#include "POW_InvincibilityData.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENT83_API UPOW_InvincibilityData : public UPowerUpData
{
	GENERATED_BODY()

	UPOW_InvincibilityData();

public:
	virtual void UsePowerUp(ACharacter83* Character) override;
	virtual void CleanupPowerUp(ACharacter83* Character) override;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* InvincibilityMaterial;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* StandardMaterial0;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* StandardMaterial1;
};
