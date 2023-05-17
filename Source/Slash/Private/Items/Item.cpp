// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "DrawDebugHelpers.h"
#include "Slash/Slash.h"


#define THIRTY 30


// Sets default values
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();

	DRAW_SPHERE(Location)
	DRAW_LINE(Location, Location + Forward * 100.f)
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

