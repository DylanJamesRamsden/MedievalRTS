// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DHUD.h"

#include "Blueprint/UserWidget.h"
#include "Buildings/DBuilding.h"
#include "Kismet/GameplayStatics.h"
#include "Player/DPlayerState.h"
#include "Player/Components/DBuildingManagementComponent.h"
#include "Player/COmponents/DUnitManagementComponent.h"

void ADHUD::BeginPlay()
{
	Super::BeginPlay();

	OwningPawn = Cast<ADPlayerPawn>(GetOwningPawn());
}

void ADHUD::StartSelection()
{
	OwningPawn->GetUnitManagementComponent()->ClearSelectedUnits();
	OwningPawn->GetBuildingManagementComponent()->ClearSelectedBuildings();
	
	UGameplayStatics::GetPlayerController(GetWorld(), GetOwningPlayerController()->NetPlayerIndex)->GetMousePosition(MouseStartPosition.X, MouseStartPosition.Y);

	bIsDragging = true;
}

void ADHUD::EndSelection()
{
	bIsDragging = false;
}

void ADHUD::InitializePlayerWidgets()
{
	if (PlayerResourcesWidget)
	{
		PlayerResourcesWidgetInstance = CreateWidget(GetOwningPlayerController(), PlayerResourcesWidget);
		PlayerResourcesWidgetInstance->AddToViewport();
	}

	if (UnitInformationWidget)
	{
		UnitInformationWidgetInstance = CreateWidget(GetOwningPlayerController(), UnitInformationWidget);
		UnitInformationWidgetInstance->AddToViewport();
	}

	if (GameTimeWidget)
	{
		GameTimerWidgetInstance = CreateWidget(GetOwningPlayerController(), GameTimeWidget);
		GameTimerWidgetInstance->AddToViewport();
	}
}

void ADHUD::DrawHUD()
{
	if (bIsDragging)
	{	
		FVector2D(UGameplayStatics::GetPlayerController(this, 0)->GetMousePosition(MouseCurrentPosition.X, MouseCurrentPosition.Y));

		const float ScreenX = MouseStartPosition.X;
		const float ScreenY = MouseStartPosition.Y;

		const float ScreenW = MouseCurrentPosition.X - ScreenX;
		const float ScreenH = MouseCurrentPosition.Y - ScreenY;
		
		DrawRect(FLinearColor(0, 0, 1, .15f), ScreenX, ScreenY, ScreenW, ScreenH);

		SelectSelectables();
	}
}

void ADHUD::SelectSelectables()
{
	TArray<AActor*> ActorsFound;
	GetActorsInSelectionRectangle(FVector2D(MouseStartPosition.X, MouseStartPosition.Y), FVector2D(MouseCurrentPosition.X, MouseCurrentPosition.Y), ActorsFound, true, true);

	ClearDeselectedBuildings(ActorsFound);
	ClearDeselectedUnits(ActorsFound);

	ADPlayerState* DPS = GetOwningPlayerController()->GetPlayerState<ADPlayerState>();
	
	for (auto OutActor : ActorsFound)
	{
		if (OutActor->Implements<UDSelectable>())
		{
			if (OutActor->IsA(ADUnit::StaticClass()))
			{
				if (OwningPawn->GetBuildingManagementComponent()->GetNumberOfSelectedBuildings() == 0)
				{
					ADUnit* Unit = Cast<ADUnit>(OutActor);
					if (Unit->GetTeam() == DPS->GetTeam())
					{
						OwningPawn->GetUnitManagementComponent()->AddSelectedUnit(Unit);		
					}
				}
			}
			else if (OutActor->IsA(ADBuilding::StaticClass()))
			{
				if (OwningPawn->GetUnitManagementComponent()->GetNumberOfSelectedUnits() == 0)
				{
					ADBuilding* Building = Cast<ADBuilding>(OutActor);
					if (Building->GetTeam() == DPS->GetTeam())
					{
						OwningPawn->GetBuildingManagementComponent()->AddSelectedBuilding(Building);	
					}	
				}
			}
		}
	}
}

void ADHUD::ClearDeselectedBuildings(TArray<AActor*> ActorsFound) const
{
	if (OwningPawn->GetBuildingManagementComponent()->GetNumberOfSelectedBuildings() > 0)
	{
		TArray<ADBuilding*> SelectedBuildingsToRemove;
		
		for (auto Building : OwningPawn->GetBuildingManagementComponent()->GetSelectedBuildings())
		{
			bool InSelection = false;
			for (auto Actor : ActorsFound)
			{
				if (Actor == Building)
				{
					InSelection = true;
					break;
				}
			}

			if (!InSelection)
			{
				SelectedBuildingsToRemove.Add(Building);
			}
		}

		if (SelectedBuildingsToRemove.Num() > 0)
		{
			for (auto BuildingToRemove : SelectedBuildingsToRemove)
			{
				OwningPawn->GetBuildingManagementComponent()->RemoveSelectedBuilding(BuildingToRemove);
			}
		}
	}
}

void ADHUD::ClearDeselectedUnits(TArray<AActor*> ActorsFound) const
{
	if (OwningPawn->GetUnitManagementComponent()->GetNumberOfSelectedUnits() > 0)
	{
		TArray<ADUnit*> SelectedUnitsToRemove;
		
		for (auto Unit : OwningPawn->GetUnitManagementComponent()->GetSelectedUnits())
		{
			bool InSelection = false;
			for (auto Actor : ActorsFound)
			{
				if (Actor == Unit)
				{
					InSelection = true;
					break;
				}
			}

			if (!InSelection)
			{
				SelectedUnitsToRemove.Add(Unit);
			}
		}

		if (SelectedUnitsToRemove.Num() > 0)
		{
			for (auto BuildingToRemove : SelectedUnitsToRemove)
			{
				OwningPawn->GetUnitManagementComponent()->RemoveSelectedUnit(BuildingToRemove);
			}
		}
	}
}
