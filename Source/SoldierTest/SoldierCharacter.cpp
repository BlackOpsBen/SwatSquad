// Fill out your copyright notice in the Description page of Project Settings.


#include "SoldierCharacter.h"

// Sets default values
ASoldierCharacter::ASoldierCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASoldierCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASoldierCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ASoldierCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("Run"), this, &ASoldierCharacter::Run);

	PlayerInputComponent->BindAxis(TEXT("Strafe"), this, &ASoldierCharacter::Strafe);
}

void ASoldierCharacter::Run(float direction)
{
	AddMovementInput(FVector::ForwardVector, direction);
	UE_LOG(LogTemp, Warning, TEXT("Run direction: %f"), direction);
}

void ASoldierCharacter::Strafe(float direction)
{
	AddMovementInput(FVector::RightVector, direction);
	UE_LOG(LogTemp, Warning, TEXT("Strafe direction: %f"), direction);
}

