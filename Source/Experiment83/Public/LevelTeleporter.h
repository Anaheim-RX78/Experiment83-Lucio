// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "LevelTeleporter.generated.h"

UCLASS()
class EXPERIMENT83_API ALevelTeleporter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelTeleporter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Details")
	FString LevelId;

	UPROPERTY(EditAnywhere, Category="Details")
	FVector ExitPoint;

	UPROPERTY(EditAnywhere)
	UBoxComponent* EntryCollider;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* EntryMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ExitMesh;

	UFUNCTION()
	virtual void OnOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

};
