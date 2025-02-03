// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Character83.h"
#include "Kismet/KismetMathLibrary.h"
#include "PowerUpData.h"
#include "Components/BoxComponent.h"
#include "LuckyCube.generated.h"

UCLASS()
class EXPERIMENT83_API ALuckyCube : public AActor
{
	GENERATED_BODY()
	
public:
	ALuckyCube();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	TArray<UPowerUpData*> GetExtendedPowerUps();

	UFUNCTION()
	virtual void OnOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category="Components")
	UBoxComponent* ColliderComponent;
};
