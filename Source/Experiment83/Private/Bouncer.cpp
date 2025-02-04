// Fill out your copyright notice in the Description page of Project Settings.


#include "Bouncer.h"

#include "Character83.h"

// Sets default values
ABouncer::ABouncer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BouncerCollider = CreateDefaultSubobject<USphereComponent>("SphereCollider");
	RootComponent = BouncerCollider;

	BouncerMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	BouncerMesh->SetupAttachment(BouncerCollider);

}

// Called when the game starts or when spawned
void ABouncer::BeginPlay()
{
	Super::BeginPlay();
	BouncerCollider->OnComponentBeginOverlap.AddDynamic(this, &ABouncer::OnOverlap);
}

void ABouncer::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter83* Character = Cast<ACharacter83>(OtherActor);

	if (!Character) return;

	// Calculating the bounce direction by normalizing the horizontal component of the distance between character and bouncer
	FVector CharacterDistance = (Character->GetActorLocation() - GetActorLocation());
	FVector BounceDirection = FVector(CharacterDistance.X, CharacterDistance.Y, 0).GetSafeNormal();
	Character->StartBounce(BounceDirection);
	
}

// Called every frame
void ABouncer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

