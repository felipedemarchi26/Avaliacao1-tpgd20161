// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ColetavelPaulo.generated.h"

UCLASS()
class AVALIACAO1_API AColetavelPaulo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColetavelPaulo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetCont(int32 NewCont);

	int32 GetCont();

private:
	UPROPERTY(EditAnywhere, Category = "Property")
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Property")
		UBoxComponent* CollisionComp;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);	

	FTimerHandle MyTimer;

	void ChangePosition();
	void Bounce();
	void AddSec();
	void Spin();

	float ZMin;
	float ZMax;

	int32 Bouncing;
	int32 Cont;

	int Tempo;

};
