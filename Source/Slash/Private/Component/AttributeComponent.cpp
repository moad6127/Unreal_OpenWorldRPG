// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/AttributeComponent.h"

UAttributeComponent::UAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UAttributeComponent::ReceiveDamage(float Damage)
{
	Health = FMath::Clamp(Health - Damage, 0.f, MaxHealth);

	if (Health == 0.f)
	{
		//TOOD Death
	}
}

float UAttributeComponent::GetHealthPercent() const
{
	return Health / MaxHealth;
}


void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

