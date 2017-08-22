// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	
	PrimaryComponentTick.bCanEverTick = true;//Should this Tick???

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{

	//auto OurTankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT(" %s aiming at: %s from %s"), *OurTankName, *HitLocation.ToString(), *BarrelLocation);

	


	if (!Barrel) { 
		UE_LOG(LogTemp, Warning, TEXT("No Barrel found in TankAimingComponent"));
		return;
	}

	FVector OutLaunchVelocity;
	//OutLaunchVelocity.

	//StartLocation is the barrel tip
	FVector StartLocation = Barrel->GetSocketLocation(FName("BarrelTip"));

	
	bool bHaveAimingSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimingSolution)
	{

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();

		MoveBarrelTowards(AimDirection);

		UE_LOG(LogTemp, Warning, TEXT("aiming at %s"), *AimDirection.ToString());

	}
	else
	{

		auto Time = GetWorld()->GetTimeSeconds();

		UE_LOG(LogTemp, Warning, TEXT("%f No aim solve found"), Time);


	}


}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{

	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	auto DeltaRotator = AimRotator - BarrelRotation;

	Barrel->Elevate(5);


}

