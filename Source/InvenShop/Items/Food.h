// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Food.generated.h"

class AInvenShopCharacter;

UCLASS()
class INVENSHOP_API AFood : public AItem
{
	GENERATED_BODY()
public:
	AFood();
	
protected:
	UPROPERTY(EditAnywhere)
	float RemoveFoodValue;
	
public:
	
	virtual void Use(AInvenShopCharacter* Character) override;
};
