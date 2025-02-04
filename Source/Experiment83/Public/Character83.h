// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory.h"
#include "LifeComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Character83.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeathHandler);

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

	UPROPERTY(EditAnywhere, Category = "Life", BlueprintReadWrite)
	ULifeComponent* LifeHandler;

	UPROPERTY(EditAnywhere, Category = "Items", BlueprintReadWrite)
	UInventory* Inventory;
	
	UPROPERTY(EditAnywhere, Category = "Barrier", BlueprintReadWrite)
	bool IsBarrierUp = false;

	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float MovementSpeed = 500.f;

	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float FallSpeed = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float SlowerFallSpeed = 800.f;

	UPROPERTY(EditAnywhere, Category = "Bounce", BlueprintReadWrite)
	float BounceInitialVelocity = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Bounce", BlueprintReadWrite)
	float BounceVelocity = 0.f;

	UPROPERTY(EditAnywhere, Category = "Bounce", BlueprintReadWrite)
	FVector BounceDirection;

	UPROPERTY(EditAnywhere, Category = "Bounce", BlueprintReadWrite)
	float BounceDecayRate = .5f;

	UFUNCTION()
	void StartBounce(FVector BounceDir);

	UPROPERTY(EditAnywhere, Category = "Powerups", BlueprintReadWrite)
	bool PowerUpInvincibility = false;

	UPROPERTY(EditAnywhere, Category = "Powerups", BlueprintReadWrite)
	bool CanSlowDown = false;

	UPROPERTY(EditAnywhere, Category = "Powerups", BlueprintReadWrite)
	bool HasSlowedDown = false;

	UPROPERTY(BlueprintAssignable)
	FDeathHandler OnDeath;

	UPROPERTY(EditAnywhere, Category = "Powerups", BlueprintReadWrite)
	FVector StickDriftDirection = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Powerups", BlueprintReadWrite)
	float StickDriftSpeed = 0.f;
	
};

