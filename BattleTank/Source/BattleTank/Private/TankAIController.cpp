// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/Tank.h"
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

void ATankAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	auto Tank = Cast<ATank>(GetPawn());
	
	if (GetPlayerTank())
	{

		//TODO Move to player 

		//Aim at player
		auto PlayerLocation = GetPlayerTank()->GetActorLocation();
		Tank->AimAt(PlayerLocation);

		//TODO Fire at player

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




