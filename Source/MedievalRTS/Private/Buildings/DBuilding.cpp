// Fill out your copyright notice in the Description page of Project Settings.


#include "Buildings/DBuilding.h"

#include "Components/DecalComponent.h"

// Sets default values
ADBuilding::ADBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	RootComponent = StaticMeshComp;
	
	SelectionDecal = CreateDefaultSubobject<UDecalComponent>("SelectionDecal");
	SelectionDecal->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADBuilding::BeginPlay()
{
	Super::BeginPlay();

	SelectionDecal->SetVisibility(false);
}

void ADBuilding::Selected_Implementation()
{
	if (SelectionDecal)
	{
		SelectionDecal->SetVisibility(true);
	}
}

void ADBuilding::Deselected_Implementation()
{
	if (SelectionDecal)
	{
		SelectionDecal->SetVisibility(false);
	}
}

// Called every frame
void ADBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

