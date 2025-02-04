
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PrettyName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	PowerUpType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPowerDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PowerUpDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PickProbability;

	UFUNCTION()
	virtual void UsePowerUp(ACharacter83* Character);

	UFUNCTION()
	virtual void CleanupPowerUp(ACharacter83* Character);
};
