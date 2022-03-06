// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerComponent/HealthSystemComponent.h"
#include "PlayerHealthSystem.generated.h"

/**
 * 
 */
UCLASS()
class TGJAM_API UPlayerHealthSystem : public UHealthSystemComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
};
