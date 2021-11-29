// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DUnitManagementComponent.h"

// Sets default values for this component's properties
UDUnitManagementComponent::UDUnitManagementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDUnitManagementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDUnitManagementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDUnitManagementComponent::AddUnit(ADUnit* NewUnit)
{
	Units.Add(NewUnit);
}

void UDUnitManagementComponent::RemoveUnit(ADUnit* UnitToRemove)
{
	Units.Remove(UnitToRemove);
}

void UDUnitManagementComponent::AddSelectedUnit(ADUnit* SelectedUnit)
{
	if (SelectedUnit->Implements<UDSelectable>())
	{
		IDSelectable::Execute_Selected(SelectedUnit);
	}
	
	SelectedUnits.Add(SelectedUnit);
}

void UDUnitManagementComponent::ClearSelectedUnits()
{
	for (auto Unit : SelectedUnits)
	{
		if (Unit->Implements<UDSelectable>())
		{
			IDSelectable::Execute_Deselected(Unit);
		}
	}
	
	SelectedUnits.Empty();
}

/*void UDUnitManagementComponent::RemoveSelectedUnit(ADUnit* UnitToRemove)
{
	SelectedUnits.Remove(UnitToRemove);
}*/

