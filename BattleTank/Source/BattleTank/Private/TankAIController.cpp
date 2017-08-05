// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{

		Super::BeginPlay();

		auto ControlledTank = GetControlledTank();

		if (!ControlledTank) {
			UE_LOG(LogTemp, Warning, TEXT("TankAIController not possessing: %s"), *(ControlledTank->GetName()));

		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing: %s"), *(ControlledTank->GetName()));
		}

	}

ATank* ATankAIController::GetControlledTank() const
{
		return Cast<ATank>(GetPawn());
}





