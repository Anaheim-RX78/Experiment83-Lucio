#include "POW_SlowDownData.h"

#include "Character83.h"

void UPOW_SlowDownData::UsePowerUp(ACharacter83* Character)
{
	Character->CanSlowDown = true;
}

void UPOW_SlowDownData::CleanupPowerUp(ACharacter83* Character)
{
	Character->CanSlowDown = false;
	Character->HasSlowedDown = false; // Also remove possible current enabled slowdown effect
}
