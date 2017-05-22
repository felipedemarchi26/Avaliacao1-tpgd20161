// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ManagerMarcelo.generated.h"

UCLASS()
class AVALIACAO1_API AManagerMarcelo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AManagerMarcelo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	class AColetavelMarcelo1* Coletavel1;
	class AColetavelMarcelo1* Coletavel2;
	class AColetavelMarcelo1* Coletavel3;
	class AColetavelMarcelo1* Coletavel4;


	
	

};
