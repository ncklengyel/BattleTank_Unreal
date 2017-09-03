// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/TankAimingComponent.h"
#include "Public/TankBarrel.h"
#include "Public/Projectile.h"
#include "Public/Tank.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create defauklt subobject
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));


}

void ATank::Fire()
{

	

	if (Barrel) 
	{
		FVector BarrelTipLocation = Barrel->GetSocketLocation("BarrelTip");
		FRotator BarrelTipRotator = Barrel->GetSocketRotation("BarrelTip");
		//Spawn Projectile
		GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, BarrelTipLocation, BarrelTipRotator);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("%s : nullptr on Barrel (Tank.cpp)"), *this->GetName());
	}

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{

	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;

}

void ATank::SetTurretReference(UTurret * TurretToSet)
{

	TankAimingComponent->SetTurretReference(TurretToSet);

}

void ATank::AimAt(FVector HitLocation)
{

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	
}

