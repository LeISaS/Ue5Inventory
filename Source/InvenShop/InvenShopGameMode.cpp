// Copyright Epic Games, Inc. All Rights Reserved.

#include "InvenShopGameMode.h"
#include "InvenShopCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInvenShopGameMode::AInvenShopGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
