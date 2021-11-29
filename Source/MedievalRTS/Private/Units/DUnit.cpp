// Fill out your copyright notice in the Description page of Project Settings.


#include "Units/DUnit.h"

#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADUnit::ADUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SelectionDecal = CreateDefaultSubobject<UDecalComponent>("SelectionDecal");
	SelectionDecal->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADUnit::BeginPlay()
{
	Super::BeginPlay();

	SelectionDecal->SetVisibility(false);
}

void ADUnit::Selected_Implementation()
{
	if (SelectionDecal)
	{
		SelectionDecal->SetVisibility(true);
	}
}

void ADUnit::Deselected_Implementation()
{
	if (SelectionDecal)
	{
		SelectionDecal->SetVisibility(false);
	}
}

// Called every frame
void ADUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

