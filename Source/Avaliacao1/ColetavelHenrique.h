// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ColetavelHenrique.generated.h"

UCLASS()
class AVALIACAO1_API AColetavelHenrique : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColetavelHenrique();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = "Property")
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Property")
		USphereComponent* CollisionComp;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);
	
	void Mover();

	UPROPERTY(EditAnywhere)
	int8 Direction;

	UPROPERTY(EditAnywhere)
	float DistanciaMover;

	UPROPERTY(EditAnywhere)
	float Velocidade;

	FVector InitialLocation;

};
