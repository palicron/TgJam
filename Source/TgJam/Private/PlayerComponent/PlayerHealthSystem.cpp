// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerComponent/PlayerHealthSystem.h"

void UPlayerHealthSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

void UPlayerHealthSystem::AddArmor(int Armor)
{
	Super::AddArmor(Armor);

	if(CurrentArmor<MaxArmor)
	{
		CurrentArmor+=Armor;
		OnHealthChange.Broadcast(CurrentHealth,CurrentArmor);
	}
	
}
