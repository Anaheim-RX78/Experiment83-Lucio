// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "FinishLine.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFinishHandler);

UCLASS()
class EXPERIMENT83_API AFinishLine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFinishLine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category="Components")
	UBoxComponent* BoxComponent;
	
	UPROPERTY(BlueprintAssignable)
	FFinishHandler OnFinish;
};