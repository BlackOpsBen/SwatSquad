// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSquadPawn.h"
#include "SoldierCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "SquadMovement.h"

// Sets default values
APlayerSquadPawn::APlayerSquadPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	squadMovementComponent = CreateDefaultSubobject<USquadMovement>(TEXT("Squad Movement Component"));
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

FVector APlayerSquadPawn::GetInputMoveVector() const
{
	return inputMoveVector;
}

TArray<AActor*> APlayerSquadPawn::GetSoldiers()
{
	return soldiers;
}

void APlayerSquadPawn::CenterOnAllSoldiers()
{
	FVector center{};
	FVector extent{};
	UGameplayStatics::GetActorArrayBounds(soldiers, false, center, extent);
	SetActorLocation(center);
}

