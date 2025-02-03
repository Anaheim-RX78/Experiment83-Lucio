#include "RotatingDamager.h"

#include "Components/BillboardComponent.h"

ARotatingDamager::ARotatingDamager()
{
	PivotComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("PlatformTarget"));
	PivotComponent->SetupAttachment(RootComponent);
	PivotComponent->SetRelativeLocation(FVector(0, 100, 0));
	PivotComponent->bIsEditorOnly = true;

	// Set default sprite for the billboard
	static ConstructorHelpers::FObjectFinder<UTexture2D> BillboardSprite(TEXT("/Engine/EditorResources/S_TargetPoint.S_TargetPoint"));
	if (BillboardSprite.Succeeded())
	{
		PivotComponent->Sprite = BillboardSprite.Object;
		PivotComponent->SetRelativeScale3D(FVector(0.3f, 0.3f, 0.3f));
	}
}

void ARotatingDamager::BeginPlay()
{
	Super::BeginPlay();
	
	PivotLocation = PivotComponent->GetComponentLocation();
}

void ARotatingDamager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float AngleRotation = DegreesPerSecond * DeltaTime;
    
	FVector Offset = GetActorLocation() - PivotLocation;
	FVector RotatedOffset = Offset.RotateAngleAxis(AngleRotation, FVector::UpVector);
    
	SetActorLocation(PivotLocation + RotatedOffset);
	AddActorWorldRotation(FRotator(0, AngleRotation, 0));
}
