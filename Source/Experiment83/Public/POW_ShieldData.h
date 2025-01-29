// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerUpData.h"
#include "POW_ShieldData.generated.h"


UCLASS()
class EXPERIMENT83_API UPOW_ShieldData : public UPowerUpData
{
	GENERATED_BODY()

public:
	virtual void UsePowerUp(ACharacter83* Character) override;
	virtual void CleanupPowerUp(ACharacter83* Character) override;
};
