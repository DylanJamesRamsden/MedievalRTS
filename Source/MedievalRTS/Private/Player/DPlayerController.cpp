// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DPlayerController.h"

#include "Game/DGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Player/DHUD.h"
#include "Player/DPlayerState.h"

void ADPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ADPlayerController::InitializeSelf()
{
	ADPlayerState* PS = GetPlayerState<ADPlayerState>();
	if (PlayerState)
	{
		PS->SetTeam(Cast<ADGameState>(UGameplayStatics::GetGameState(GetWorld()))->GetAvailableTeam());
		PS->InitializePlayerEconomy();
	}
	
	C_InitializeHUD();
}

void ADPlayerController::C_InitializeHUD_Implementation()
{
	ADHUD* PHUD = GetHUD<ADHUD>();
	if (PHUD)
	{
		PHUD->InitializePlayerWidgets();
	}
}
