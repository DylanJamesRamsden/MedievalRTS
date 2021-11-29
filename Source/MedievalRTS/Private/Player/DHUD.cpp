// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DHUD.h"

#include "Interfaces/DSelectable.h"
#include "Kismet/GameplayStatics.h"
#include "Player/DUnitManagementComponent.h"

void ADHUD::BeginPlay()
{
	Super::BeginPlay();

	OwningPawn = Cast<ADPlayerPawn>(GetOwningPawn());
}

void ADHUD::StartSelection()
{
	UGameplayStatics::GetPlayerController(GetWorld(), GetOwningPlayerController()->NetPlayerIndex)->GetMousePosition(MouseStartPosition.X, MouseStartPosition.Y);

	bIsDragging = true;
}

void ADHUD::EndSelection()
{
	bIsDragging = false;
}

void ADHUD::DrawHUD()
{
	if (bIsDragging)
	{
		OwningPawn->GetUnitManagmentComponent()->ClearSelectedUnits();
		
		FVector2D(UGameplayStatics::GetPlayerController(this, 0)->GetMousePosition(MouseCurrentPosition.X, MouseCurrentPosition.Y));

		const float ScreenX = MouseStartPosition.X;
		const float ScreenY = MouseStartPosition.Y;

		const float ScreenW = MouseCurrentPosition.X - ScreenX;
		const float ScreenH = MouseCurrentPosition.Y - ScreenY;
		
		DrawRect(FLinearColor(0, 0, 1, .15f), ScreenX, ScreenY, ScreenW, ScreenH);

		SelectUnits();
	}
}

void ADHUD::SelectUnits()
{
	TArray<AActor*> ActorsFound;
	GetActorsInSelectionRectangle(FVector2D(MouseStartPosition.X, MouseStartPosition.Y), FVector2D(MouseCurrentPosition.X, MouseCurrentPosition.Y), ActorsFound);

	for (auto OutActor : ActorsFound)
	{
		ADUnit* Unit = Cast<ADUnit>(OutActor);
		if (Unit)
		{
			OwningPawn->GetUnitManagmentComponent()->AddSelectedUnit(Unit);	
		}
	}
}
