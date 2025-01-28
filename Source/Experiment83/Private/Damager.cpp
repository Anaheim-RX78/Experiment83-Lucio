// Fill out your copyright notice in the Description page of Project Settings.


#include "Damager.h"

// Sets default values
ADamager::ADamager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = CapsuleComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	MeshComponent->SetupAttachment(CapsuleComponent);

}

// Called when the game starts or when spawned
void ADamager::BeginPlay()
{
	Super::BeginPlay();
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ADamager::OnOverlap);
}

// Called every frame
void ADamager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADamager::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACharacter83* Character = Cast<ACharacter83>(OtherActor))
	{
		Character->LifeHandler->Damage();
	}
}