// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "PersonagemHenrique.h"


// Sets default values
APersonagemHenrique::APersonagemHenrique()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->TargetArmLength = 600.0f;
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

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
void APersonagemHenrique::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(Temporizador, this, &APersonagemHenrique::Increase, 1.0f, true);

}

// Called every frame
void APersonagemHenrique::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void APersonagemHenrique::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move", this, &APersonagemHenrique::Move);
	PlayerInputComponent->BindAxis("Sides", this, &APersonagemHenrique::MoveSides);

}


void APersonagemHenrique::Move(float Value) {
	FVector Forward(1.0f, 0.0f, 0.0f);
	AddMovementInput(Forward, Value);
}

void APersonagemHenrique::MoveSides(float Value) {
	FVector Side(0.0f, 1.0f, 0.0f);
	AddMovementInput(Side, Value);
}

int16 APersonagemHenrique::GetPontuacao() {
	return pontuacao;
}

void APersonagemHenrique::SetPontuacao(int16 Value) {
	if (Value >= 0) {
		pontuacao = Value;
	}
}

int16 APersonagemHenrique::GetTempo() {
	return Tempo;
}

void APersonagemHenrique::Increase() {

	Tempo += 1;
}