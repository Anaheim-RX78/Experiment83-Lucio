// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelTeleporter.h"

#include "Character83.h"
#include "MainInstance.h"

// Sets default values
ALevelTeleporter::ALevelTeleporter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EntryCollider = CreateDefaultSubobject<UBoxComponent>("EntryBox");
	RootComponent = EntryCollider;

	EntryMesh = CreateDefaultSubobject<UStaticMeshComponent>("EntryMesh");
	EntryMesh->SetupAttachment(EntryCollider);

	ExitMesh = CreateDefaultSubobject<UStaticMeshComponent>("ExitMesh");
}

// Called when the game starts or when spawned
void ALevelTeleporter::BeginPlay()
{
	Super::BeginPlay();
	ExitPoint = ExitMesh->GetComponentLocation();
	EntryCollider->OnComponentBeginOverlap.AddDynamic(this, &ALevelTeleporter::OnOverlap);
}

// Called every frame
void ALevelTeleporter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelTeleporter::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// If the character passes the teleport, the LevelId is saved, to act as a checkpoint
	ACharacter83* Character = Cast<ACharacter83>(OtherActor);
	UMainInstance* Instance = Cast<UMainInstance>(GetGameInstance());
	if (Character && Instance)
	{
		// Teleport the character and save LevelId
		Character->SetActorLocation(ExitPoint);
		Instance->CurrentLevelId = LevelId;
	}
}

