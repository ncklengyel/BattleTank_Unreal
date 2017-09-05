// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	//-1 max downward speed, +1 max up monvement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSeconde = 10;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreeElevation = 40;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinDegreeElevation = 0;
	
};
