// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerComponent/HealthSystemComponent.h"

// Sets default values for this component's properties
UHealthSystemComponent::UHealthSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthSystemComponent::BeginPlay()
{
	Super::BeginPlay();
    CurrentHealth = MaxHealth;
	
}


// Called every frame
void UHealthSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthSystemComponent::TakeDmg(float DamageAmount, DmgType DamageType)
{
	
}

void UHealthSystemComponent::RecoverDmg(float HealethAmount)
{
	
}

void UHealthSystemComponent::AddArmor(int AddArmor)
{
}

void UHealthSystemComponent::Death()
{
}

void UHealthSystemComponent::StarPlayerInvulnerability()
{
	bPlayerCanBeDmg=false;

	GetWorld()->GetTimerManager().SetTimer(invulnerability_timeHandle,this,&UHealthSystemComponent::EndPlayerInvulnerability,InvulnerabilityTime);
}

void UHealthSystemComponent::EndPlayerInvulnerability()
{
	bPlayerCanBeDmg=true;
}

void UHealthSystemComponent::GetComponentPercentage(float& healthPer, float& ArmorPer)
{
	healthPer=(MaxHealth>0)?(CurrentHealth/MaxHealth):0.0f;
	ArmorPer=(MaxArmor>0)?(CurrentArmor/MaxArmor):0.0f;
}

