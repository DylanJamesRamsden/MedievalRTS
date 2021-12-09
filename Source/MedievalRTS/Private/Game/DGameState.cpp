// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DGameState.h"

#include "Kismet/GameplayStatics.h"
#include "Player/DPlayerController.h"
#include "Player/DPlayerState.h"

EDTeam ADGameState::GetAvailableTeam()
{
	bool bTeam1Available = true;

	for (auto PS : PlayerArray)
	{
		ADPlayerState* DPS = Cast<ADPlayerState>(PS);

		if (DPS->GetTeam() == Team1)
		{
			bTeam1Available = false;
			break;
		}
	}

	return bTeam1Available ? Team1 : Team2;
}

void ADGameState::UpdateLevelState(EDLevelState NewState)
{
	if (LevelState == NewState)
		return;
	
	switch (NewState)
	{
		case PlayersJoining:
			break;
		case Initializing:
			InitializePlayers();
			break;
		case Active:
			break;
		case End:
			break;
		case Paused:
			break;
	}
}

void ADGameState::InitializePlayers()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADPlayerController::StaticClass(), FoundActors);

	for (auto FoundActor : FoundActors)
	{
		ADPlayerController* PlayerController = Cast<ADPlayerController>(FoundActor);
		PlayerController->InitializeSelf();
	}
}


