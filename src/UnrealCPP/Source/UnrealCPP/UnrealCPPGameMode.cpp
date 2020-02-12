// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UnrealCPPGameMode.h"
#include "UnrealCPPBall.h"

AUnrealCPPGameMode::AUnrealCPPGameMode()
{
	// set default pawn class to our ball
	DefaultPawnClass = AUnrealCPPBall::StaticClass();
}
