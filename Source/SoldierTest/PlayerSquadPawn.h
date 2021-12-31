// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerSquadPawn.generated.h"

UCLASS()
class SOLDIERTEST_API APlayerSquadPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerSquadPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> soldiers;

	FVector inputMoveVector{};
	void InputMoveForward(float direction);
	void InputMoveRight(float direction);

	FVector relativeForward{};
	FVector relativeRight{};

	void FlattenAndNormalizeRelatives();
	void MoveSoldiers();
	void CenterOnAllSoldiers();
};
