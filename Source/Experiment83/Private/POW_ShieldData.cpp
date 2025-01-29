// Fill out your copyright notice in the Description page of Project Settings.


#include "POW_ShieldData.h"

#include "Character83.h"

void UPOW_ShieldData::UsePowerUp(ACharacter83* Character)
{
	Character->TurnOnBarrier();
}

void UPOW_ShieldData::CleanupPowerUp(ACharacter83* Character)
{

}
