#include "POW_InvincibilityData.h"
#include "Character83.h"

UPOW_InvincibilityData::UPOW_InvincibilityData()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> BlueMat(TEXT("Material'/Game/LevelPrototyping/Materials/M_Solid.M_Solid'"));
	InvincibilityMaterial = BlueMat.Object;

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> DefaultMat0(TEXT("Material'/Game/Characters/Mannequins/Materials/M_Mannequin.M_Mannequin'"));
	StandardMaterial0 = DefaultMat0.Object;

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> DefaultMat1(TEXT("Material'/Game/Characters/Mannequins/Materials/Instances/Quinn/MI_Quinn_01.MI_Quinn_01'"));
	StandardMaterial1 = DefaultMat1.Object;
}

void UPOW_InvincibilityData::UsePowerUp(ACharacter83* Character)
{
	Character->PowerUpInvincibility = true;
}

void UPOW_InvincibilityData::CleanupPowerUp(ACharacter83* Character)
{
	Character->PowerUpInvincibility = false;
}
