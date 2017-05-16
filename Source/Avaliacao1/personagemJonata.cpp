// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "personagemJonata.h"


// Sets default values
ApersonagemJonata::ApersonagemJonata()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(CameraBoom);

	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("SkeletalMesh'/Game/AnimStarterPack/UE4_Mannequin/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (SkeletalMesh.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
	}
	GetMesh()->SetWorldLocation(FVector(0.0f, 0.0f, -80.0f));
	GetMesh()->SetWorldScale3D(FVector(0.9f, 0.9f, 0.9f));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimObj(TEXT("AnimBlueprint'/Game/Animations/WalkAnimation.WalkAnimation'"));
	if (AnimObj.Succeeded()) {
		GetMesh()->SetAnimInstanceClass(AnimObj.Object->GetAnimBlueprintGeneratedClass());
	}

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}




// Called when the game starts or when spawned
void ApersonagemJonata::BeginPlay(){
	Super::BeginPlay();
	
}

// Called every frame
void ApersonagemJonata::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ApersonagemJonata::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Move", this, &ApersonagemJonata::Move);
	PlayerInputComponent->BindAxis("Sides", this, &ApersonagemJonata::MoveSides);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ApersonagemJonata::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ApersonagemJonata::StopCrouch);

}

void ApersonagemJonata::Move(float Value) {
	FVector Forward(1.0f, 0.0f, 0.0f);
	if (Value > 1.0f) {
		Value = 1.0f;
	}
	AddMovementInput(Forward, Value);
}

void ApersonagemJonata::MoveSides(float Value) {
	FVector Side(0.0f, 1.0f, 0.0f);
	if (Value > 1.0f) {
		Value = 1.0f;
	}
	AddMovementInput(Side, Value);
}

void ApersonagemJonata::StartCrouch() {
	Crouch();
}

void ApersonagemJonata::StopCrouch() {
	UnCrouch();
}


