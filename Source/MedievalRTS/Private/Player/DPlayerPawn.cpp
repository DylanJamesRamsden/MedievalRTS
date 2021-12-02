// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DPlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/DHUD.h"
#include "Player/Components/DBuildingManagementComponent.h"
#include "Player/Components/DUnitManagementComponent.h"

ADPlayerPawn::ADPlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bAddDefaultMovementBindings = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	UnitManagementComp = CreateDefaultSubobject<UDUnitManagementComponent>("UnitManagementComp");
	BuildingManagementComp = CreateDefaultSubobject<UDBuildingManagementComponent>("BuildingManagementComp");
}

void ADPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ADPlayerPawn::MouseMovement()
{
	float MouseX;
	float MouseY;

	int ViewportSizeX;
	int ViewportSizeY;

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		bool bMouseLocationFound = PlayerController->GetMousePosition(MouseX, MouseY);
		PlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);

		if (bMouseLocationFound)
		{
			if (MouseX <= 50)
			{
				MoveRight(-1);
			}

			if (MouseX >= ViewportSizeX - 50)
			{
				MoveRight(1);
			}

			if (MouseY <= 50)
			{
				MoveForward(1);
			}

			if (MouseY >= ViewportSizeY - 50)
			{
				MoveForward(-1);
			}
		}
	}
}

void ADPlayerPawn::Zoom(float Value)
{
	ZoomDirection = FMath::Clamp(Value, -1.0f, 1.0f);
}

void ADPlayerPawn::CameraSmoothZoom(float DeltaTime)
{
	if (ZoomDirection != 0)
	{
		float NewZoom = SpringArmComp->TargetArmLength + (ZoomDirection * DeltaTime * ZoomSpeed);

		NewZoom = FMath::Clamp(NewZoom, MinZoomDistance, MaxZoomDistance);
		
		SpringArmComp->TargetArmLength = FMath::FInterpTo(SpringArmComp->TargetArmLength, NewZoom, GetWorld()->DeltaTimeSeconds, ZoomSpeed);
	}
}

void ADPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MouseMovement();

	CameraSmoothZoom(DeltaTime);
}

void ADPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &ADPlayerPawn::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &ADPlayerPawn::MoveForward);

	PlayerInputComponent->BindAxis("Rotate", this, &ADPlayerPawn::AddControllerYawInput);

	PlayerInputComponent->BindAxis("Zoom", this, &ADPlayerPawn::Zoom);

	APlayerController* PController = Cast<APlayerController>(GetController());
	if (PController)
	{
		ADHUD* PHUD = Cast<ADHUD>(PController->GetHUD());
		if (PHUD)
		{
			PlayerInputComponent->BindAction("LeftMouse", IE_Pressed, PHUD,&ADHUD::StartSelection);
			PlayerInputComponent->BindAction("LeftMouse", IE_Released, PHUD, &ADHUD::EndSelection);	
		}
	}
}

UDBuildingManagementComponent* ADPlayerPawn::GetBuildingManagementComponent()
{
	return BuildingManagementComp;
}

UDUnitManagementComponent* ADPlayerPawn::GetUnitManagementComponent()
{
	return UnitManagementComp;
}
