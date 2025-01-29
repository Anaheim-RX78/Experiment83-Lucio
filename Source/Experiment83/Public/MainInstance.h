// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerUpData.h"
#include "Engine/GameInstance.h"
#include "MainInstance.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENT83_API UMainInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = Score)
	float Score = 0;

	UPROPERTY(EditAnywhere, Category = Score)
	int Attempts = 0;

	UPROPERTY(EditAnywhere, Category = Level)
	FString CurrentLevelIdentifier = "Level_01";

	UPROPERTY(EditAnywhere)
	TArray<UPowerUpData*> PowerUps;

	UPROPERTY(EditAnywhere)
	PowerUpType LatestPowerUp;
	
};
