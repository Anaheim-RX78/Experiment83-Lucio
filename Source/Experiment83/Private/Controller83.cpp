// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller83.h"



void AController83::SetupInputComponent()
{
	Super::SetupInputComponent();

	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	Subsystem->ClearAllMappings();

	if (!InputMap)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("INPUT MAP MISSING IN CHARACTER CONTROLLER, OPEN THE CHARACTER CONTROLLER AND ASSIGN THE INPUT MAP!"));
		return;
	}

	Subsystem->AddMappingContext(InputMap->MappingContext, 0);
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(InputMap->Actions["AirMove"], ETriggerEvent::Triggered, this, &AController83::AirMove);
	EnhancedInputComponent->BindAction(InputMap->Actions["UseItem"], ETriggerEvent::Started, this, &AController83::UseItem);
}

void AController83::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (ACharacter83* Pawn83 = Cast<ACharacter83>(InPawn))
	{
		Character83 = Pawn83;
	}
}

void AController83::AirMove(const FInputActionValue& Value)
{
	Character83->SetMovementInput(Value.Get<FVector2D>());
}

void AController83::UseItem(const FInputActionValue& Value)
{
	Character83->Inventory->UseItem();
}