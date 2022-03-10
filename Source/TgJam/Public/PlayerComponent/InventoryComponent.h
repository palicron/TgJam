// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

UENUM(BlueprintType)
enum class EItemType:uint8 
{
	HealthPotion UMETA(DisplayName = "Health potion"),
	ArmorPlate UMETA(DisplayName = "Armor"),
	Weapon UMETA(DisplayName = "Weapon"),
	MagicWeapone UMETA(DisplayName = "MagicWeapone")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPotionChange,const bool,Increse);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TGJAM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FPotionChange FOnPotionChangeEvent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Recovery Items")
	int HealthPotion;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Recovery Items")
	int MaxPotionCarry = 10;
    UFUNCTION(BlueprintCallable,Category="Recovery Items")
	bool UseHealthPotion();
	UFUNCTION(BlueprintCallable,Category="Recovery Items")
	void AddHealthPotion();
	UFUNCTION(BlueprintCallable,Category="Weapone Items")
	void EquipiNewWepaone();
	UFUNCTION(BlueprintCallable,Category="Weapone Items")
	void UnEquipOldWeapone();


	

		
};
