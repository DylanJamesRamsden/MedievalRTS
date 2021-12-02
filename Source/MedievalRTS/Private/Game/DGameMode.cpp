// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DGameMode.h"

#include "Enums/DTeam.h"
#include "Player/DPlayerController.h"
#include "Player/DPlayerState.h"

void ADGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	ADPlayerController* PlayerController = Cast<ADPlayerController>(NewPlayer);
	if (PlayerController)
	{
		ADPlayerState* PlayerState = PlayerController->GetPlayerState<ADPlayerState>();
		if (PlayerState)
		{
			PlayerState->SetTeam(Team1);
			//Handle team setting here
			
			
		}
	}
}
