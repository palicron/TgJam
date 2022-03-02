// Copyright Epic Games, Inc. All Rights Reserved.

#include "TgJamGameMode.h"
#include "TgJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATgJamGameMode::ATgJamGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
