// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InvenShop/InteractableInterface.h"
#include "InvenShop/Structs.h"

#include "Item.generated.h"

UCLASS()
class INVENSHOP_API AItem : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly,Category = "TUTORIAL")
	class UStaticMeshComponent* ItemMesh;
	UPROPERTY(EditDefaultsOnly,Category = "TUTORIAL")
	FItemData ItemData;
	
	virtual void Interact() override;
	
};
