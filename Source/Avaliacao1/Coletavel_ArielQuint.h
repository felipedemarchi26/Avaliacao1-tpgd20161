// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Coletavel_ArielQuint.generated.h"

UCLASS()
class AVALIACAO1_API AColetavel_ArielQuint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColetavel_ArielQuint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere)
		float Amplitude;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
		USphereComponent* CollisionComp;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent*
			OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
			OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



	
};
