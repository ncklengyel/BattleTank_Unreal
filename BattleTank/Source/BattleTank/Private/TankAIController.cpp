// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{

		Super::BeginPlay();

		auto PlayerTank = GetPlayerTank();

		if (PlayerTank == nullptr) {
			UE_LOG(LogTemp, Warning, TEXT("TankAIController can't find player tank (nullptr)"));

		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("TankAIController found player: %s"), *(PlayerTank->GetName()));
		}

	}

ATank* ATankAIController::GetControlledTank() const
{
		return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PlayerPawn)
	{

		return Cast<ATank>(PlayerPawn);

	}

	return nullptr;


}




