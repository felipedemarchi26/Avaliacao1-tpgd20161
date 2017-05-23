// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "personagemJonata.generated.h"

UCLASS()
class AVALIACAO1_API ApersonagemJonata : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ApersonagemJonata();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

	void SetCollected(int32 NewCollected);
	int32 GetCollected();
	void AddCollected();

private:

	UPROPERTY
	(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* CameraComp;

	UPROPERTY
	(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, Category = "Properties")
		 int32 Collected;

	void Move(float Value);

	void MoveSides(float Value);

	void StartCrouch();

	void StopCrouch();
	
	
};

