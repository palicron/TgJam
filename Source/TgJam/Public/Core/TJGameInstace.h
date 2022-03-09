// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TJGameInstace.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FItemsStruct
{	
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Items Description")
	UStaticMesh* RepresentMesh;
	
};
UCLASS()
class TGJAM_API UTJGameInstace : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Items Map")
    TMap<float,FItemsStruct> Items;
	UFUNCTION(BlueprintCallable)
	FItemsStruct GetItemById(const int32 Itemid);
	
	
};
