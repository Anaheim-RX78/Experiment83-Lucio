// Fill out your copyright notice in the Description page of Project Settings.


#include "POW_StickDriftData.h"
#include "Character83.h"

void UPOW_StickDriftData::UsePowerUp(ACharacter83* Character)
{
	// Generating a random stickdrift direction
	FVector Direction =  FVector(
		FMath::RandRange(-100, 100),
		FMath::RandRange(-100, 100),
		0
	).GetSafeNormal();
	Character->StickDriftDirection = Direction;
}

void UPOW_StickDriftData::CleanupPowerUp(ACharacter83* Character)
{
	// Resetting stick drift direction to 0
	Character->StickDriftDirection = FVector::ZeroVector;
}
