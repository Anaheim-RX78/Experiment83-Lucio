// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Experiment83/Experiment83Character.h"
#include "InputMap.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENT83_API UInputMap : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	TMap<FString, UInputAction*> Actions;
	
};
