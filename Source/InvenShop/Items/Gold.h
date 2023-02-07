// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Gold.generated.h"

class AInvenShopCharacter;

UCLASS()
class INVENSHOP_API AGold : public AItem
{
	GENERATED_BODY()

public:
	AGold();
	virtual void Use(AInvenShopCharacter* Character) override;
};
