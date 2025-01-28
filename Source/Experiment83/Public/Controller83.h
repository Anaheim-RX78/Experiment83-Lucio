// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character83.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMap.h"
#include "GameFramework/PlayerController.h"
#include "Controller83.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENT83_API AController83 : public APlayerController
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, Category = "Input")
	ACharacter83* Character83;
	
	UPROPERTY(EditAnywhere, Category= "Input")
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputMap* InputMap;
	
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
	void AirMove(const FInputActionValue& Value);
};
