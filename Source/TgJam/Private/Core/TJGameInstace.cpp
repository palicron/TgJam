// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/TJGameInstace.h"

#include "Kismet/GameplayStatics.h"
#include "TgJam/TgJamCharacter.h"

FItemsStruct UTJGameInstace::GetItemById(const int32 Itemid)
{
	if(Items.Contains(Itemid))
	{
		return Items[Itemid];
	}
	else
	{
		return Items[-1];
	}
}

void UTJGameInstace::Init()
{
	Super::Init();
	PlayerRef =  Cast<ATgJamCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
	
}