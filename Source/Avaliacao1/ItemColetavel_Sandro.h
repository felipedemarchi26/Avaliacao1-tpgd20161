// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ItemColetavel_Sandro.generated.h"

UCLASS()
class AVALIACAO1_API AItemColetavel_Sandro : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemColetavel_Sandro();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MalhaEstatica;
	
	
	UPROPERTY(EditAnywhere)
		UCapsuleComponent* CollisionComp;
	
	void Movimentacao();
	int direcao;
	int girada;

	void Rotacao();


	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent,
		AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
		const FHitResult& Hit);

	
};
