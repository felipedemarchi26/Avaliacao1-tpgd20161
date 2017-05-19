// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ColetavelJonata.generated.h"

UCLASS()
class AVALIACAO1_API AColetavelJonata : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColetavelJonata();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
	void SetNum(int32 NewNum);
	int32 GetNum();
	void AddNum();

	
private:

	UPROPERTY(EditAnyWhere, Category = "Collision")
		UBoxComponent* CollisionComp;

	UPROPERTY(EditAnyWhere, Category = "Mesh")
		UStaticMeshComponent* MeshComp;


	UPROPERTY(EditAnywhere, Category = "Num")
		int32 Num;

		UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void Posicao(AColetavelJonata*GetActorLocation);
	
	
};



