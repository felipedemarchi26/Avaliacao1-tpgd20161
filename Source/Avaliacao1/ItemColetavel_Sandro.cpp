// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "ItemColetavel_Sandro.h"


// Sets default values
AItemColetavel_Sandro::AItemColetavel_Sandro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemColetavel_Sandro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coletavel"));
	ConstructorHelpers::FObjectFinder< UStaticMeshComponent> MeshRef(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	
}

// Called when the game starts or when spawned
void AItemColetavel_Sandro::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemColetavel_Sandro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

