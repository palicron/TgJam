// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/TJGameInstace.h"

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
