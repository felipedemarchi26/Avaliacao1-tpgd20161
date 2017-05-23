// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ColetavelMarcelo1.generated.h"

UCLASS()
class AVALIACAO1_API AColetavelMarcelo1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColetavelMarcelo1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool IsPink();
	void SetPink(bool NewPink);

	int GetContador();
	void SetContador(int NewContador);

private:
	UPROPERTY(EditAnywhere)
		UBoxComponent* CollisionComp;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;

	UMaterial* MaterialBlack;
	UMaterial* MaterialPink;
	UMaterial* MaterialPurple;
	UMaterial* MaterialWhite;

	bool Pink;
	int32 IndexMarcelo;
	int Contador;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent*
			OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32
			OtherBodyIndex);

	void ChangeCollor();

	
};
