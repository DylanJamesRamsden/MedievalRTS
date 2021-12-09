// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DPlayerState.h"

#include "Net/UnrealNetwork.h"

void ADPlayerState::BeginPlay()
{
	Super::BeginPlay();

	InitializePlayerEconomy();
}

void ADPlayerState::SetTeam(TEnumAsByte<EDTeam> NewTeam)
{
	Team = NewTeam;
}

TEnumAsByte<EDTeam> ADPlayerState::GetTeam() const
{
	return Team;
}

int ADPlayerState::GetGold() const
{
	return *Economy.Resources.Find(Gold);
}

int ADPlayerState::GetWood() const
{
	return *Economy.Resources.Find(Wood);
}

int ADPlayerState::GetFood() const
{
	return *Economy.Resources.Find(Food);
}

int ADPlayerState::GetStone() const
{
	return *Economy.Resources.Find(Stone);
}

void ADPlayerState::AddResource(TEnumAsByte<EDResource> ResourceType, int Amount)
{
	Economy.Resources.Emplace(ResourceType, *Economy.Resources.Find(ResourceType) + Amount);
	
	OnResourceChanged.Broadcast(ResourceType, *Economy.Resources.Find(ResourceType));
}

void ADPlayerState::InitializePlayerEconomy()
{
	FDEconomy* StartingPlayerEconomy = StartingPlayerEconomyRow.GetRow<FDEconomy>("Player starting economy");
	
	if (StartingPlayerEconomy)
	{
		Economy = *StartingPlayerEconomy;
	}
	else UE_LOG(LogTemp, Error, TEXT("Player starting economy not set. Please set in BP_PlayerState."));
}

void ADPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADPlayerState, Team);
}
