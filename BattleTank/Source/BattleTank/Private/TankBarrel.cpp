// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{

	auto Time = GetWorld()->GetTimeSeconds();

	//UE_LOG(LogTemp, Warning, TEXT("Time: %f speedElevate: %f"), Time, RelativeSpeed);


}
