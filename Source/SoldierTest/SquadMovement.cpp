// Fill out your copyright notice in the Description page of Project Settings.


#include "SquadMovement.h"
#include "SoldierCharacter.h"
#include "PlayerSquadPawn.h"

// Sets default values for this component's properties
USquadMovement::USquadMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void USquadMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void USquadMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FlattenAndNormalizeRelatives();
	//MoveSoldiers();
}

void USquadMovement::FlattenAndNormalizeRelatives()
{
	relativeForward = GetOwner()->GetActorForwardVector();
	relativeForward.Z = 0.0f;
	relativeForward.Normalize();
	relativeRight = GetOwner()->GetActorRightVector();
	relativeRight.Z = 0.0f;
	relativeRight.Normalize();

}

//void USquadMovement::MoveSoldiers()
//{
//	FVector relativeMoveVector = relativeForward * GetOwner<APlayerSquadPawn>()->GetInputMoveVector().X + relativeRight * GetOwner<APlayerSquadPawn>()->GetInputMoveVector().Y;
//
//	for (AActor* soldier : GetOwner<APlayerSquadPawn>()->GetSoldiers())
//	{
//		Cast<ASoldierCharacter>(soldier)->AddMovementInput(relativeMoveVector);
//	}
//}

