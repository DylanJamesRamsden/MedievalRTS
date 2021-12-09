// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DGameMode.h"

#include "Game/DGameState.h"
#include "GameFramework/GameStateBase.h"
#include "Player/DPlayerController.h"

void ADGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	
	if (GetNumPlayers() == 2)
	{
		ADGameState* GS = Cast<ADGameState>(GameState);

		if (GS)
		{
			GS->UpdateLevelState(Initializing);	
		}
		else UE_LOG(LogTemp, Error, TEXT("Incorrect GameState set. Please ChangeGame state to subclass of DGameState in BP_GameMode."));
		
	}
}
