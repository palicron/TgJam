// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreActors/PickUpItemActor.h"

// Sets default values
APickUpItemActor::APickUpItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickUpItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

