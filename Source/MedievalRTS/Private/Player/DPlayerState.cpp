// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DPlayerState.h"

void ADPlayerState::SetTeam(TEnumAsByte<EDTeam> NewTeam)
{
	Team = NewTeam;
}

TEnumAsByte<EDTeam> ADPlayerState::GetTeam() const
{
	return Team;
}
