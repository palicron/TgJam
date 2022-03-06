// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthSystemComponent.generated.h"

UENUM(BlueprintType)
enum DmgType
{
	Normal UMETA(DisplayName = "Normal"),
	Fire UMETA(DisplayName = "Fire"),
	Arcane UMETA(DisplayName = "Arcane"),
	Bloggerin UMETA(DisplayName = "bloggerin")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FhealChangeEvent,const float,NewHealth,const float,NewArmor);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TGJAM_API UHealthSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthSystemComponent();
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    FTimerHandle invulnerability_timeHandle;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HealthSystem")
	float MaxHealth;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HealthSystem")
	int MaxArmor;
  
	bool bPlayerCanBeDmg =true;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(BlueprintAssignable)
    FhealChangeEvent OnHealthChange;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HealthSystem")
	float CurrentHealth;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HealthSystem")
	int CurrentArmor;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HealthSystem")
	float  InvulnerabilityTime;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HealthSystem")
	float ArmorDmgAbsorptionPercentage;
	
	virtual void TakeDmg(float DamageAmount,DmgType DamageType=DmgType::Normal);
	
	virtual void RecoverDmg(float HealethAmount);
	
	virtual void AddArmor(int AddArmor);
	
	virtual void Death();

	void StarPlayerInvulnerability();

	void EndPlayerInvulnerability();
};
