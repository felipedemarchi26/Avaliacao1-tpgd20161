// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Personagem.generated.h"

UCLASS()
class AVALIACAO1_API APersonagem : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APersonagem();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//Gets e Sets
	int GetColected();
	void SetColected(int NewColected);
	float TempoPercorrido;

	
private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* CameraBoom;

	void Move(float Value);

	void MoveSides(float Value);

	void StartCrouch();

	void StopCrouch();

	int Colected;

	FTimerHandle Timer;

	void Tempo();


};
