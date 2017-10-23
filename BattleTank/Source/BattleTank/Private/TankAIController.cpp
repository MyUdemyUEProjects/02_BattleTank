// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(GetPlayerTank()) {
		if(GetControlledTank())
			GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("AIController-Tank dont exist"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController-Tank name: %s"), *ControlledTank->GetName())
	}
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("AIController-Player Tank dont exist"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController-Player Tank name: %s"), *PlayerTank->GetName())
	}

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

