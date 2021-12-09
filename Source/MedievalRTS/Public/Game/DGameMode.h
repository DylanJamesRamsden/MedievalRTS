// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameMode.h"

#include "DGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALRTS_API ADGameMode : public AGameMode
{
	GENERATED_BODY()

	protected:

	virtual void PostLogin(APlayerController* NewPlayer) override;

	UPROPERTY(EditDefaultsOnly, Category = "Players")
	int NumberOfPlayers = 2;
};
