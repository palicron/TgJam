// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Core/TJGameInstace.h"
#include "GameFramework/Actor.h"
#include "PickUpItemActor.generated.h"

enum class EItemType:uint8;
class UTJGameInstace;
UCLASS()
class TGJAM_API APickUpItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Pick Up representation")
	UStaticMeshComponent* ShowMesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Pick Up representation")
	USphereComponent* SphereCol;
	UPROPERTY()
	UTJGameInstace* GameInstanceRef;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Pick Up representation")
	EItemType PickUpType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Pick Up representation")
	float CollisionRadius=100.0f;
	UFUNCTION()
	void InitPickUp(int32 ItemId );
	UFUNCTION()
	virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnItemPickUp();

};
