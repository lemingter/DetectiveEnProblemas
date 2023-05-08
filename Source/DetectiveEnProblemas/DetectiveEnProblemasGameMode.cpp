// Copyright Epic Games, Inc. All Rights Reserved.

#include "DetectiveEnProblemasGameMode.h"
#include "DetectiveEnProblemasCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADetectiveEnProblemasGameMode::ADetectiveEnProblemasGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
