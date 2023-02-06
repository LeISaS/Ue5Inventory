// Fill out your copyright notice in the Description page of Project Settings.


#include "Medpack.h"
#include "InvenShop/InvenShopCharacter.h"

AMedpack::AMedpack()
{
	HealthValue = 10.0f;
	ItemData.ItemClass = StaticClass();
}

void AMedpack::Use(AInvenShopCharacter* Character)
{
	if(Character)
	{
		Character->AddHealth(HealthValue);
	}
}
