// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DLevelState.generated.h"

UENUM(Blueprintable)
enum EDLevelState
{
	PlayersJoining,
	Initializing,
	Active,
	End,
	Paused
};
