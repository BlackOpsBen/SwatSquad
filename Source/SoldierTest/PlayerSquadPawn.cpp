// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSquadPawn.h"
#include "SoldierCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerSquadPawn::APlayerSquadPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerSquadPawn::BeginPlay()
{
	Super::BeginPlay();

	// Get All of the Soldiers already in the scene
	UGameplayStatics::GetAllActorsOfClass(this, ASoldierCharacter::StaticClass(), soldiers);
}

// Called every frame
void APlayerSquadPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FlattenAndNormalizeRelatives();
	MoveSoldiers();
	CenterOnAllSoldiers();
}

// Called to bind functionality to input
void APlayerSquadPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerSquadPawn::InputMoveForward);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerSquadPawn::InputMoveRight);
}

void APlayerSquadPawn::InputMoveForward(float direction)
{
	inputMoveVector.X = direction;
}

void APlayerSquadPawn::InputMoveRight(float direction)
{
	inputMoveVector.Y = direction;
}

void APlayerSquadPawn::FlattenAndNormalizeRelatives()
{
	relativeForward = GetActorForwardVector();
	relativeForward.Z = 0.0f;
	relativeForward.Normalize();
	relativeRight = GetActorRightVector();
	relativeRight.Z = 0.0f;
	relativeRight.Normalize();

}

void APlayerSquadPawn::MoveSoldiers()
{
	FVector relativeMoveVector = relativeForward * inputMoveVector.X + relativeRight * inputMoveVector.Y;
	for (AActor* soldier : soldiers)
	{
		Cast<ASoldierCharacter>(soldier)->AddMovementInput(relativeMoveVector);
	}
}

void APlayerSquadPawn::CenterOnAllSoldiers()
{
	FVector center{};
	FVector extent{};
	UGameplayStatics::GetActorArrayBounds(soldiers, false, center, extent);
	SetActorLocation(center);
}

