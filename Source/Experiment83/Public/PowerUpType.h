// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "PowerUpType.generated.h"

UENUM(BlueprintType)
enum class PowerUpType : uint8
{
	Invincibility,
	Shield,
	Break,
	StickDrift
};
