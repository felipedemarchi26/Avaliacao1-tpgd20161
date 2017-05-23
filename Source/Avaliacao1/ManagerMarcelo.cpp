// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "ManagerMarcelo.h"
#include "ColetavelMarcelo1.h"


// Sets default values
AManagerMarcelo::AManagerMarcelo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AManagerMarcelo::BeginPlay()
{
	Super::BeginPlay();
	FVector Location1 = FVector(-350.0f, -350.0f, 70.0f);
	FVector Location2 = FVector(-350.0f, 350.0f, 70.0f);
	FVector Location3 = FVector(350.0f, 350.0f, 70.0f);
	FVector Location4 = FVector(350.0f, -350.0f, 70.0f);

	UWorld* World = GetWorld();
	if (World) {
		FActorSpawnParameters SpawnParameters;
		Coletavel1 =
			World->SpawnActor<AColetavelMarcelo1>(Location1,
				FRotator::ZeroRotator, SpawnParameters);
		Coletavel2 =
			World->SpawnActor<AColetavelMarcelo1>(Location2,
				FRotator::ZeroRotator, SpawnParameters);
		Coletavel3 =
			World->SpawnActor<AColetavelMarcelo1>(Location3,
				FRotator::ZeroRotator, SpawnParameters);
		Coletavel4 =
			World->SpawnActor<AColetavelMarcelo1>(Location4,
				FRotator::ZeroRotator, SpawnParameters);
	}
	
}

// Called every frame
void AManagerMarcelo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Coletavel1->IsPink() && Coletavel2->IsPink() && Coletavel3->IsPink() && Coletavel4->IsPink()) {
		int Pontos = Coletavel1->GetContador() + Coletavel3->GetContador() + Coletavel2->GetContador() + Coletavel4->GetContador();
		UE_LOG(LogTemp, Warning, TEXT("Pontuação: %d"), Pontos);
	}

}



