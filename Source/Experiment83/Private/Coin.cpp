#include "Coin.h"

#include "Character83.h"

ACoin::ACoin()
{
	PrimaryActorTick.bCanEverTick = true;

	CoinCollider = CreateDefaultSubobject<USphereComponent>("CoinCollider");
	RootComponent = CoinCollider;

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("CoinMesh");
	CoinMesh->SetupAttachment(CoinCollider);
}

void ACoin::BeginPlay()
{
	Super::BeginPlay();
	CoinCollider->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnOverlap);
}

void ACoin::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACharacter83* Character = Cast<ACharacter83>(OtherActor))
	{
		// Adds its own score amount to the player's score
		Character->Inventory->Score += Score;
		Destroy();
	}
}

void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

