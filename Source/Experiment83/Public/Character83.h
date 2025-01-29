// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory.h"
#include "LifeComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Character83.generated.h"

UCLASS()
class EXPERIMENT83_API ACharacter83 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacter83();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed = 500.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float FallSpeed = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Barrier")
	UStaticMeshComponent* Barrier;

public:
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetMovementInput(const FVector2D& MovementVector);
	void TurnOnBarrier();
	void TurnOffBarrier();

	UPROPERTY(EditAnywhere, Category = "Life")
	ULifeComponent* LifeHandler;

	UPROPERTY(EditAnywhere, Category = "Items")
	UInventory* Inventory;
	
	UPROPERTY(EditAnywhere, Category = "Barrier")
	bool IsBarrierUp = false;

};

