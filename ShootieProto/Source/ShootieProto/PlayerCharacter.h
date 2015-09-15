// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActorController.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacter.generated.h"



/*
	Player controlled character.
*/

UCLASS()
class SHOOTIEPROTO_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

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
	
	//Projectile class to spawn
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AProjectile> ProjectileClass;

	//Handles firing
	UFUNCTION()
	void Fire();

	//Sideways movement of the character
	void MoveYAxis(float AxisValue);
	//Characters cover actions
	void CoverAction();

	FVector currentVelocity;
	bool isInCover;
	bool isAlive;
	bool isFiring;

private:
	//Checks if the player has been shot
	void CheckHit();

	//Function for ducking and standing up.
	void IntoCover();
	void OutOfCover();
	
};
