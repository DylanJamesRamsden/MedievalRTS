// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DPlayerPawn.h"

#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ADPlayerPawn::ADPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	RootComponent = SpringArmComp;

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	CameraMovementComp = CreateDefaultSubobject<UDCameraMovementComponent>("CameraMovementComp");
}

// Called when the game starts or when spawned
void ADPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADPlayerPawn::DrawCameraPositionDebug() const
{
	if (bDebugCamera)
	{
		FHitResult Hit;

		const FVector StartLocation = CameraComp->GetComponentLocation();
		const FVector EndLocation = CameraComp->GetComponentLocation() + (CameraComp->GetComponentRotation().Vector() * 10000);

		const bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECC_WorldDynamic);
		if (bHit)
		{
			DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 100, 32, FColor::Red);
		}
	}
}

// Called every frame
void ADPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawCameraPositionDebug();
}

// Called to bind functionality to input
void ADPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

