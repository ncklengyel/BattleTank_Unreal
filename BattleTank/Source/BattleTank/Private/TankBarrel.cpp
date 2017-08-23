// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//RlativeSpeed needs to be between -1 and 1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1,1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSeconde * GetWorld()->GetDeltaSeconds();
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinDegreeElevation, MaxDegreeElevation);

	SetRelativeRotation(FRotator(Elevation,0,0));

	//UE_LOG(LogTemp, Warning, TEXT("Time: %f speedElevate: %f"), Time, RelativeSpeed);


}
