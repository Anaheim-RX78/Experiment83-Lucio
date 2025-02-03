// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damager.h"
#include "RotatingDamager.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENT83_API ARotatingDamager : public ADamager
{
	GENERATED_BODY()

public:
	ARotatingDamager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector PivotLocation;

	UPROPERTY(EditAnywhere)
	float DegreesPerSecond = 90;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UBillboardComponent> PivotComponent;
};
