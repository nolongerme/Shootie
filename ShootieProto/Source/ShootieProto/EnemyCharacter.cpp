// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootieProto.h"
#include "EnemyCharacter.h"
#include "PlayerCharacter.h"
#include "ActorController.h"



// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Dummy root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//Create visible object and attach it to the root component
	visibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleComponent"));
	visibleComponent->AttachTo(RootComponent);

	//Adjust model size
	visibleComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 1.3f));
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );


	//Handle movement
	if (!currentVelocity.IsZero())
	{
		FVector newLocation = GetActorLocation() + (currentVelocity * DeltaTime * movementSpeed);
		SetActorLocation(newLocation);
	}
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	//Receive input here over the network
}

void AEnemyCharacter::MoveYAxis(float AxisValue)
{
	//Moves character sideways
	currentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}


//void AEnemyCharacter::CheckIfHit()
//{
//	if (!isInCover)
//	{
//		ActorController actorController;
//		APlayerCharacter& player;
//
//		player = actorController.getPlayerCharacter();
//	}
//}


void AEnemyCharacter::CoverAction()
{
	//Character moves in and out of cover depending on its state.

	if (isInCover)
		OutOfCover();
	else
		IntoCover();
}


//Private
void AEnemyCharacter::IntoCover()
{
	/*
	NOTE: In the prototype covering just moves character up and down.
	More functionality will be added here later e.g. play animations etc.
	*/


	isInCover = true;
}


void AEnemyCharacter::OutOfCover()
{
	isInCover = false;
}