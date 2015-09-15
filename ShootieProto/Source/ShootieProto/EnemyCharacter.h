// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "EnemyCharacter.generated.h"

/*
	Character controlled by the opposing player. Receives input over the internet.
*/

UCLASS()
class SHOOTIEPROTO_API AEnemyCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere)
	USceneComponent* visibleComponent;
	UPROPERTY(EditAnywhere)
	float movementSpeed;

	//Sideways movement of the character
	void MoveYAxis(float AxisValue);
	//Characters cover actions
	void CoverAction();

	//Check if enemy is shot
	//void CheckIfHit();

	FVector currentVelocity;
	bool isInCover;

private:
	void IntoCover();
	void OutOfCover();
};
