// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Core/Enums/DLevelState.h"
#include "Core/Enums/DTeam.h"
#include "GameFramework/GameState.h"
#include "DGameState.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALRTS_API ADGameState : public AGameState
{
	GENERATED_BODY()
	
	protected:

	UPROPERTY()
	TEnumAsByte<EDLevelState> LevelState;

	public:

	EDTeam GetAvailableTeam();

	void UpdateLevelState(EDLevelState NewState);

	void InitializePlayers();
};
