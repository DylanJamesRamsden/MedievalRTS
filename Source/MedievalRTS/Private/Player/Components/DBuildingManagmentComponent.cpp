// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Components/DBuildingManagementComponent.h"

// Sets default values for this component's properties
UDBuildingManagementComponent::UDBuildingManagementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDBuildingManagementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDBuildingManagementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDBuildingManagementComponent::AddBuilding(ADBuilding* NewBuilding)
{
		Buildings.Add(NewBuilding);
}

void UDBuildingManagementComponent::RemoveBuilding(ADBuilding* BuildingToRemove)
{
	Buildings.Remove(BuildingToRemove);
}

void UDBuildingManagementComponent::AddSelectedBuilding(ADBuilding* SelectedBuilding)
{
	if (SelectedBuilding->Implements<UDSelectable>())
	{
		IDSelectable::Execute_Selected(SelectedBuilding);
	}
	
	SelectedBuildings.Add(SelectedBuilding);
}

void UDBuildingManagementComponent::RemoveSelectedBuilding(ADBuilding* BuildingToRemove)
{
	if (BuildingToRemove->Implements<UDSelectable>())
	{
		IDSelectable::Execute_Deselected(BuildingToRemove);
	}
	
	SelectedBuildings.Remove(BuildingToRemove);
}

void UDBuildingManagementComponent::ClearSelectedBuildings()
{
	for (auto Building : SelectedBuildings)
	{
		if (Building->Implements<UDSelectable>())
		{
			IDSelectable::Execute_Deselected(Building);
		}
	}
	
	SelectedBuildings.Empty();
}

int UDBuildingManagementComponent::GetNumberOfSelectedBuildings() const
{
	return SelectedBuildings.Num();
}

TArray<ADBuilding*> UDBuildingManagementComponent::GetSelectedBuildings() const
{
	return SelectedBuildings;
}

