// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreActors/PickUpItemActor.h"
#include "PlayerComponent/InventoryComponent.h"
#include "Core/TJGameInstace.h"
#include "Kismet/GameplayStatics.h"
#include "TgJam/TgJamCharacter.h"

// Sets default values
APickUpItemActor::APickUpItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereCol = CreateDefaultSubobject<USphereComponent>(TEXT("PickUpTrigger"));
	SphereCol->OnComponentBeginOverlap.AddDynamic(this,&APickUpItemActor::OnOverlapBegin);
	SphereCol->SetSphereRadius(CollisionRadius);

	RootComponent = SphereCol;
	ShowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUpStaticMesh"));
	ShowMesh->SetupAttachment(RootComponent);

	

}

// Called when the game starts or when spawned
void APickUpItemActor::BeginPlay()
{
	Super::BeginPlay();
	GameInstanceRef = Cast<UTJGameInstace>(GetGameInstance());
	PlayerRef = Cast<ATgJamCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));;
	InitPickUp();
}



// Called every frame
void APickUpItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
  

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
	//@TODO  Posible cambio ya que no funcinaria en multijugador
	const ATgJamCharacter* Player = Cast<ATgJamCharacter>(OtherActor);
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
	if(IsValid(PlayerRef))
	{
		switch (PickUpType)
		{
		case EItemType::HealthPotion:
			PlayerRef->AddPotionToPlayer();
			break;
		case EItemType::ArmorPlate:
			PlayerRef->AddArmorToPlayer(10);
			break;
		case EItemType::Weapon: break;
		case EItemType::MagicWeapone: break;
		default: ;
		}

		DetroidPickUp();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Bad Player set") );
	}

}
void APickUpItemActor::DetroidPickUp()
{

	Destroy();
}
