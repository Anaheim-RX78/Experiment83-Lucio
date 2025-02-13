#pragma once

#include "CoreMinimal.h"
#include "PowerUpData.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateUI);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXPERIMENT83_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventory();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UPowerUpData* PrimarySlot = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPowerUpData* SecondarySlot = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsOnHold = false;

	UPROPERTY(VisibleAnywhere)
	float OnHoldTimeSeconds;
	
	UPROPERTY()
	float OnHoldTimer = 0;

	UPROPERTY()
	class ACharacter83* CharacterRef;

	UFUNCTION()
	void AddItem(UPowerUpData* ItemData);

	UFUNCTION()
	void UseItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Score;

	UPROPERTY(BlueprintAssignable)
	FUpdateUI OnUpdate;
};
