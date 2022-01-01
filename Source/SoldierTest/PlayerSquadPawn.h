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

	TArray<AActor*> GetSoldiers();

	FVector GetInputMoveVector() const;

private:
	FVector inputMoveVector{};
	void InputMoveForward(float direction);
	void InputMoveRight(float direction);

	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> soldiers;

	UPROPERTY(VisibleAnywhere)
	class USquadMovement* squadMovementComponent;

	void CenterOnAllSoldiers();
};
