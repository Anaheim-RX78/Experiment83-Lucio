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
	TArray<UPowerUpData*> ExtendedPowerUps = {};
	UMainInstance* Instance = Cast<UMainInstance>(GetGameInstance());
	
	for (UPowerUpData* PowerUp : Instance->PowerUps)
	{
		for (int i = 0; i < PowerUp->PickProbability; i++)
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
		TArray<UPowerUpData*> ExtendedPowerUps = GetExtendedPowerUps();
		int RandomIndex = UKismetMathLibrary::RandomIntegerInRange(0, ExtendedPowerUps.Num() - 1);

		if (!ExtendedPowerUps[RandomIndex]) return;

		Character->Inventory->AddItem(ExtendedPowerUps[RandomIndex]);
	}
	Destroy();
}