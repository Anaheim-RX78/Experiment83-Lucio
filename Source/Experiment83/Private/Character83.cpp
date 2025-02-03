// Fill out your copyright notice in the Description page of Project Settings.


#include "Character83.h"

#include "LevelTeleporter.h"
#include "MainInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

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

	// Start with disabled barrier
	Barrier->SetHiddenInGame(true);
	Barrier->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	UMainInstance* Instance = Cast<UMainInstance>(GetGameInstance());
	if (!Instance) return;

	// Find all teleporters
	ALevelTeleporter* CurrentTeleporter = nullptr;
	TArray<AActor*> Teleporters;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALevelTeleporter::StaticClass(), Teleporters);

	// Check if the GameInstance has the ID of a present teleporter
	for (AActor* Actor : Teleporters)
	{
		ALevelTeleporter* Teleporter = Cast<ALevelTeleporter>(Actor);
		if (Teleporter && Teleporter->LevelId == Instance->CurrentLevelId)
		{
			CurrentTeleporter = Teleporter;
		}
	}

	// If so, teleport character to the exit point
	if (CurrentTeleporter != nullptr)
	{
		SetActorLocation(CurrentTeleporter->ExitPoint);
	}
}

void ACharacter83::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float CurrentFallSpeed = HasSlowedDown ? SlowerFallSpeed : FallSpeed;
	SetActorLocation(GetActorLocation() + (FVector(0, 0, -1) * (CurrentFallSpeed) * DeltaTime));

	// Bounce logic
	if (BounceVelocity > 0.f)
	{
		// Move the character according to the bounce velocity
		SetActorLocation(GetActorLocation() + (BounceDirection * BounceVelocity * DeltaTime));

		// Diminish the velocity until it becomes so small it's not worth calculating
		BounceVelocity = BounceVelocity * (1.f - (BounceDecayRate * DeltaTime));
		if (BounceVelocity < 10)
		{
			BounceVelocity = 0;
		}
	}
}

void ACharacter83::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACharacter83::SetMovementInput(const FVector2D& MovementVector)
{
	// Move Character by linear input, with zero friction and acceleration
	SetActorLocation(GetActorLocation() + (MovementSpeed * (GetActorForwardVector() * MovementVector.Y) + (MovementSpeed * (GetActorRightVector() * MovementVector.X))));
}

void ACharacter83::TurnOnBarrier()
{
	// Make Barrier visible and enable collisions
	Barrier->SetHiddenInGame(false);
	Barrier->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	IsBarrierUp = true;
}

void ACharacter83::TurnOffBarrier()
{
	// The opposite
	Barrier->SetHiddenInGame(true);
	Barrier->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	IsBarrierUp = false;
}

void ACharacter83::StartBounce(FVector BounceDir)
{
	BounceDirection = BounceDir;
	BounceVelocity = BounceInitialVelocity;
}
