// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PersonagemHenrique.generated.h"

UCLASS()
class AVALIACAO1_API APersonagemHenrique : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APersonagemHenrique();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	int16 GetPontuacao();

	void SetPontuacao(int16 coletado);

	int16 GetTempo();

private:
	
	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* CameraBoom;

	int16 pontuacao;
	
	void Move(float Value);

	void MoveSides(float Value);
	
	void Increase();
	
	FTimerHandle Temporizador;

	int16 Tempo;	
};
