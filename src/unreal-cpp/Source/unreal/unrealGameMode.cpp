// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "unrealGameMode.h"
#include "unrealBall.h"

AunrealGameMode::AunrealGameMode()
{
	// set default pawn class to our ball
	DefaultPawnClass = AunrealBall::StaticClass();
}
