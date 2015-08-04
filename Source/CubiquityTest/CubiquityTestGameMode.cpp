// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "CubiquityTest.h"
#include "CubiquityTestGameMode.h"
#include "CubiquityTestPlayerController.h"
#include "CubiquityTestCharacter.h"

ACubiquityTestGameMode::ACubiquityTestGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ACubiquityTestPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}