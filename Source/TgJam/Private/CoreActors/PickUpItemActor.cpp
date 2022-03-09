// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreActors/PickUpItemActor.h"
#include "PlayerComponent/InventoryComponent.h"
#include "Core/TJGameInstace.h"
#include "TgJam/TgJamCharacter.h"

// Sets default values
APickUpItemActor::APickUpItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	SphereCol = CreateDefaultSubobject<USphereComponent>(TEXT("PickUpTrigger"));
	SphereCol->SetSphereRadius(CollisionRadius);
	SphereCol->OnComponentBeginOverlap.AddDynamic(this,&APickUpItemActor::OnOverlapBegin);
	RootComponent = SphereCol;
	ShowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUpStaticMesh"));
	ShowMesh->SetupAttachment(RootComponent);

	

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
   	GameInstanceRef = Cast<UTJGameInstace>(GetGameInstance());

}

void APickUpItemActor::InitPickUp(int32 ItemId)
{
	if(IsValid(GameInstanceRef))
	{   FItemsStruct ItemRep; 
		switch (PickUpType) {
		case EItemType::HealthPotion:
			ItemRep = GameInstanceRef->GetItemById(1);
			if(IsValid(ItemRep.RepresentMesh))
			{
				ShowMesh->SetStaticMesh(ItemRep.RepresentMesh);
			}
			break;
		case EItemType::ArmorPlate:
			 ItemRep = GameInstanceRef->GetItemById(2);
			if(IsValid(ItemRep.RepresentMesh))
			{
				ShowMesh->SetStaticMesh(ItemRep.RepresentMesh);
			}
			break;
			
		case EItemType::Weapon: break;
		case EItemType::MagicWeapone: break;
		default: ;
		}
	}
}

void APickUpItemActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATgJamCharacter* Player = Cast<ATgJamCharacter>(OtherActor);
	if(IsValid(Player))
	{
		OnItemPickUp();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("There no Player to Pick Up ") );
	}
}

void APickUpItemActor::OnItemPickUp()
{
	UE_LOG(LogTemp, Warning, TEXT("Player Pick up ") );
}

