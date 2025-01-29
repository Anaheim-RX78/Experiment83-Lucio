#include "POW_InvincibilityData.h"
#include "Character83.h"

void UPOW_InvincibilityData::UsePowerUp(ACharacter83* Character)
{
	Character->LifeHandler->IsInvincible = true;
}

void UPOW_InvincibilityData::CleanupPowerUp(ACharacter83* Character)
{
	Character->LifeHandler->IsInvincible = false;
}
