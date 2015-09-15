// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class SHOOTIEPROTO_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	AProjectile(const FObjectInitializer& objectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Sphere collision component
	UPROPERTY(VisibleDefaultsOnly)
	USphereComponent* CollisionComp;

	//Projectile moving component
	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* ProjectileMovement;

	void InitVelocity(const FVector& ShootDirection);
	
};
