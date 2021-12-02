// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Enums/DTeam.h"
#include "GameFramework/PlayerState.h"
#include "DPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALRTS_API ADPlayerState : public APlayerState
{
	GENERATED_BODY()

	protected:
	UPROPERTY()
	TEnumAsByte<EDTeam> Team;

	public:
	void SetTeam(TEnumAsByte<EDTeam> NewTeam);

	TEnumAsByte<EDTeam> GetTeam() const;
};
