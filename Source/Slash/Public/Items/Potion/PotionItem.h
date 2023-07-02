// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "PotionItem.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API APotionItem : public AItem
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere, Category = Potion)
	float HealAmount;


	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;

public:

	FORCEINLINE float GetHealAmount() const { return HealAmount; }

};
