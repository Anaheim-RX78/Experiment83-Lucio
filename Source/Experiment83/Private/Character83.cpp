// Fill out your copyright notice in the Description page of Project Settings.


#include "Character83.h"

#include "GameFramework/CharacterMovementComponent.h"

ACharacter83::ACharacter83()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.f;
	SpringArm->bUsePawnControlRotation = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	LifeHandler = CreateDefaultSubobject<ULifeComponent>("LifeHandler");
}

// Called when the game starts or when spawned
void ACharacter83::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->AirControl = 1.f;
}

void ACharacter83::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacter83::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACharacter83::SetMovementInput(const FVector2D& MovementVector)
{
	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	AddMovementInput(GetActorRightVector(), MovementVector.X);
}
