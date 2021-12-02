// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DUnitState.generated.h"

UENUM(Blueprintable)
enum EDUnitState
{
	Idle,
	Walking,
	Attacking,
	Dying,
	Scouting
};
