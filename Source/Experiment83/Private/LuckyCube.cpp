#include "LuckyCube.h"
#include "MainInstance.h"

ALuckyCube::ALuckyCube()
{
	PrimaryActorTick.bCanEverTick = true;

	ColliderComponent = CreateDefaultSubobject<UBoxComponent>("Box");
	RootComponent = ColliderComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	MeshComponent->SetupAttachment(ColliderComponent);
	ColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ALuckyCube::OnOverlap);
}

void ALuckyCube::BeginPlay()
{
	Super::BeginPlay();
}

void ALuckyCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<UPowerUpData*> ALuckyCube::GetExtendedPowerUps()
{
	// Retrieving the powerups' data from the gameinstance
	TArray<UPowerUpData*> ExtendedPowerUps = {};
	UMainInstance* Instance = Cast<UMainInstance>(GetGameInstance());

	// We create an array of powerups, every powerup appears for the number of its PickProbability
	for (UPowerUpData* PowerUp : Instance->PowerUps)
	{
		// The latest powerup has a probability dimished by 1 to avoid picking too many of the same powerup
		int Probability = PowerUp->PickProbability + (Instance->LatestPowerUp == PowerUp->Type ? 0 : -1);
		for (int i = 0; i < Probability; i++)
		{
			ExtendedPowerUps.Add(PowerUp);
		}
	}

	return ExtendedPowerUps;
}



void ALuckyCube::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACharacter83* Character = Cast<ACharacter83>(OtherActor))
	{
		// Retrieving powerups
		TArray<UPowerUpData*> ExtendedPowerUps = GetExtendedPowerUps();
		// Picking one at random
		int RandomIndex = UKismetMathLibrary::RandomIntegerInRange(0, ExtendedPowerUps.Num() - 1);

		if (!ExtendedPowerUps[RandomIndex]) return;

		// Adding the powerup to the inventory
		Character->Inventory->AddItem(ExtendedPowerUps[RandomIndex]);
		UMainInstance* Instance = Cast<UMainInstance>(GetGameInstance());

		if (!Instance) return;
		// Setting the picked powerup as the latest one in the game instance
		Instance->LatestPowerUp = ExtendedPowerUps[RandomIndex]->Type;
		
		Destroy();
	}
}