// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DGameTimerWidget.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALRTS_API UDGameTimerWidget : public UUserWidget
{
	GENERATED_BODY()

	public:

	UFUNCTION(BlueprintCallable)
	FString GetGameTimeAsString() const;
};
