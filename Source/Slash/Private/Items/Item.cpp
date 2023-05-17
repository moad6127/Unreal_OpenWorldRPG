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
	
	UE_LOG(LogTemp, Warning, TEXT("BeginPlayCalled"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Red, FString("Item OnScreen Message!"));
	}

	UWorld* World = GetWorld();

	FVector Location = GetActorLocation();
	DRAW_SPHERE(Location)
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("DeltaTime : %f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Red, Message);
	}
}

