// Copyright Epic Games, Inc. All Rights Reserved.

#include "Experiment83GameMode.h"
#include "Experiment83Character.h"
#include "UObject/ConstructorHelpers.h"

AExperiment83GameMode::AExperiment83GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
