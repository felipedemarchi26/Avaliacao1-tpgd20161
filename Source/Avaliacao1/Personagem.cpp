// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "Personagem.h"


// Sets default values
APersonagem::APersonagem()
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
void APersonagem::BeginPlay()
{
	Super::BeginPlay();
	//Ativar o temporizador - Ariel Quint
	GetWorldTimerManager().SetTimer(Timer, this,
		&APersonagem::Tempo, 1.0f, true);

	SetColected(0);
}

// Called every frame
void APersonagem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void APersonagem::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move", this, &APersonagem::Move);
	PlayerInputComponent->BindAxis("Sides", this, &APersonagem::MoveSides);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &APersonagem::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &APersonagem::StopCrouch);

}

void APersonagem::Move(float Value) {
	FVector Forward(1.0f, 0.0f, 0.0f);
	if (Value > 1.0f) {
		Value = 1.0f;
	}
	AddMovementInput(Forward, Value);
}

void APersonagem::MoveSides(float Value) {
	FVector Side(0.0f, 1.0f, 0.0f);
	if (Value > 1.0f) {
		Value = 1.0f;
	}
	AddMovementInput(Side, Value);
}

void APersonagem::StartCrouch() {
	Crouch();
}

void APersonagem::StopCrouch() {
	UnCrouch();
}


//Metodos de Get e Set
int APersonagem::GetColected() { return Colected; }
void APersonagem::SetColected(int NewColected) { Colected = NewColected; }

void APersonagem::Tempo() {

	TempoPercorrido++;

}
