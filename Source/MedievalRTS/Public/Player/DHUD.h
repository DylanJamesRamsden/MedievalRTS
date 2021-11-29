// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DPlayerPawn.h"
#include "GameFramework/HUD.h"
#include "DHUD.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALRTS_API ADHUD : public AHUD
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	ADPlayerPawn* OwningPawn;
	
	UPROPERTY()
	FVector2D MouseStartPosition;

	UPROPERTY()
	FVector2D MouseCurrentPosition;

	UPROPERTY()
	bool bIsDragging;

	virtual void BeginPlay() override;

	virtual void DrawHUD() override;

	UFUNCTION()
	void SelectUnits();

public:
	
	UFUNCTION()
	void StartSelection();

	UFUNCTION()
	void EndSelection();
};
