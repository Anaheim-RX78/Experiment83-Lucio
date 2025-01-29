
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PowerUpType.h"
#include "PowerUpData.generated.h"

class ACharacter83;

UCLASS()
class EXPERIMENT83_API UPowerUpData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	FString PrettyName;

	UPROPERTY(EditAnywhere)
	PowerUpType Type;

	UPROPERTY(EditAnywhere)
	bool IsPowerDown;

	UPROPERTY(EditAnywhere)
	float PowerUpDuration;

	UPROPERTY(EditAnywhere)
	FString Image;

	UPROPERTY(EditAnywhere)
	int PickProbability;

	UFUNCTION()
	virtual void UsePowerUp(ACharacter83* Character);

	UFUNCTION()
	virtual void CleanupPowerUp(ACharacter83* Character);
};
