// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "Enums/DResource.h"

#include "DEconomy.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FDEconomy : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TMap<TEnumAsByte<EDResource>, int> Resources;
};

