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
	Inventory = CreateDefaultSubobject<UInventory>("Inventory");
	
	Barrier = CreateDefaultSubobject<UStaticMeshComponent>("Barrier");
	Barrier->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void ACharacter83::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->AirControl = 1.f;
	Barrier->SetHiddenInGame(true);
	Barrier->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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
	SetActorLocation(GetActorLocation() + (MovementSpeed * (GetActorForwardVector() * MovementVector.Y) +(MovementSpeed * (GetActorRightVector() * MovementVector.X) )));
	// AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	// AddMovementInput(GetActorRightVector(), MovementVector.X);
}

void ACharacter83::TurnOnBarrier()
{
	Barrier->SetHiddenInGame(false);
	Barrier->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	IsBarrierUp = true;
}

void ACharacter83::TurnOffBarrier()
{
	Barrier->SetHiddenInGame(true);
	Barrier->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	IsBarrierUp = false;
}