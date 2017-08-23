// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Turret.h"

void UTurret::Rotate(float RelativeSpeed)
{


	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));

	//int32 test = 8;

	//UE_LOG(LogTemp, Warning, TEXT("%f No aim solve found"), Rotation);
}
