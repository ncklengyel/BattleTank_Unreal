// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/Tank.h"
#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	auto Tank = Cast<ATank>(GetPawn());
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetControlledPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}

}



