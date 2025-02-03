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
	EnhancedInputComponent->BindAction(InputMap->Actions["SlowDown"], ETriggerEvent::Started, this, &AController83::SlowDown);
	EnhancedInputComponent->BindAction(InputMap->Actions["SlowDown"], ETriggerEvent::Completed, this, &AController83::SpeedUp);
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

void AController83::SlowDown(const FInputActionValue& Value)
{
	if (!Character83->CanSlowDown) return;
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("SLOW DOWN"));
	Character83->HasSlowedDown = true;
}

void AController83::SpeedUp(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("SPEED UP"));
	Character83->HasSlowedDown = false;
}
