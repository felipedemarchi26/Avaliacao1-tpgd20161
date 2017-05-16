// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "ColetavelJonata.h"


// Sets default values
AColetavelJonata::AColetavelJonata()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>
		(TEXT("CollisionComp"));

	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AColetavelJonata::OnOverlapBegin);

	CollisionComp->SetBoxExtent(FVector(15.0f, 15.0f, 15.0f));
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>
		(TEXT("MeshComp"));

	MeshComp->SetCollisionProfileName("No Collision");
	ConstructorHelpers::FObjectFinder<UStaticMesh> LoadMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	/*if (LoadMesh.Succeeded) {
		MeshComp->SetStaticMesh(LoadMesh.Object);
	}*/



}

// Called when the game starts or when spawned
void AColetavelJonata::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColetavelJonata::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AColetavelJonata::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){}
