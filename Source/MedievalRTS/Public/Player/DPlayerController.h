// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALRTS_API ADPlayerController : public APlayerController
{
	GENERATED_BODY()

	protected:

	virtual void BeginPlay() override;

	public:
	
	void InitializeSelf();

	UFUNCTION(Client, Reliable)
	void C_InitializeHUD();
	
};
