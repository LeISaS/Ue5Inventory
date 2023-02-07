// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InvenShop/InteractableInterface.h"
#include "InvenShop/Structs.h"
#include "ShopKeeper.generated.h"

UCLASS()
class INVENSHOP_API AShopKeeper : public AActor,public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	AShopKeeper();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	class USkeletalMeshComponent* ShopKeeperMesh;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(Replicated,EditAnywhere,BlueprintReadWrite,Category = "TUTORIAL")
	TArray<FItemData> Items;
public:
	virtual void Interact(class AInvenShopCharacter* Character) override;
};
