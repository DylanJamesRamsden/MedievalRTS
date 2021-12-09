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

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> PlayerResourcesWidget;

	UPROPERTY()
	UUserWidget* PlayerResourcesWidgetInstance;
	
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> UnitInformationWidget;

	UPROPERTY()
	UUserWidget* UnitInformationWidgetInstance;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> GameTimeWidget;

	UPROPERTY()
	UUserWidget* GameTimerWidgetInstance;
	
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

	void SelectSelectables();

	//Deselects all of the buildings that do not fall in the selection box anymore
	void ClearDeselectedBuildings(TArray<AActor*> ActorsFound) const;

	//Deselects all of the buildings that do not fall in the selection box anymore
	void ClearDeselectedUnits(TArray<AActor*> ActorsFound) const;

public:	
	void StartSelection();

	void EndSelection();

	void InitializePlayerWidgets();
};
