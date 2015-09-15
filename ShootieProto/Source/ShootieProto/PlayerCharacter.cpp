// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootieProto.h"
#include "PlayerCharacter.h"
#include "Projectile.h"
#include "EngineUtils.h"

//Public

// Sets default values
APlayerCharacter::APlayerCharacter() : movementSpeed(1.0f)
{

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set this character to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Dummy root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//Create a camera and a visible object
	UCameraComponent* camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	visibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleComponent"));

	//Attach the camera and the visible component to the root component
	camera->AttachTo(RootComponent);
	camera->SetRelativeLocation(FVector(-40.0f, 30.0f, 90.0f));
	camera->SetRelativeRotation(FRotator(-10.0f, 0.0f, 0.0f));
	visibleComponent->AttachTo(RootComponent);

	//Adjust model size
	visibleComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 1.3f));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	//NOTE: Do we need to check this every tick? (Performance)
	CheckHit();


	//Set firing state false after every tick to prevent continuous firing.
	isFiring = false;
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("Cover", IE_Pressed, this, &APlayerCharacter::CoverAction);
	InputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::Fire);
}

//Character moves in and out of cover depending on its state.
void APlayerCharacter::CoverAction()
{
	if (isInCover)
		OutOfCover();
	else
		IntoCover();
}


void APlayerCharacter::Fire()
{
	isFiring = true;
}


//Private

//Get info if enemy fires its gun while player is out of cover
void APlayerCharacter::CheckHit()
{

}


void APlayerCharacter::IntoCover()
{
	/*
	NOTE: In the prototype covering just moves character up and down.
	More functionality will be added here later e.g. to trigger animations etc.
	*/

	//Replace with ducking animation
	FVector newLocation = GetActorLocation() + FVector(0.0f, 0.0f, -50.0f);
	SetActorLocation(newLocation);
	//

	isInCover = true;
}


void APlayerCharacter::OutOfCover()
{
	//Replace with standing up animation
	FVector newLocation = GetActorLocation() + FVector(0.0f, 0.0f, 50.0f);
	SetActorLocation(newLocation);
	//

	isInCover = false;
}