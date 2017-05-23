// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "Coletavel_ArielQuint.h"
#include "Personagem.h"


// Sets default values
AColetavel_ArielQuint::AColetavel_ArielQuint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>
		(TEXT("MeshComp"));
	ConstructorHelpers::FObjectFinder<UMaterial> Material
	(TEXT("Material'/Game/Materials/Amarelo.Amarelo'"));
	if (Material.Succeeded()) {
		MeshComp->SetMaterial(0, Material.Object);
	}
	MeshComp->SetCollisionProfileName("BlockAllDynamic");
	ConstructorHelpers::FObjectFinder<UStaticMesh> LoadMesh(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (LoadMesh.Succeeded()) {
		MeshComp->SetStaticMesh(LoadMesh.Object);
	}

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->InitSphereRadius(30.0f);
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AColetavel_ArielQuint::OnOverlapBegin);
	RootComponent = CollisionComp;

	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -20.0f));
	MeshComp->SetWorldScale3D(FVector(0.5f, 0.5f, 0.50f));
	MeshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AColetavel_ArielQuint::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void AColetavel_ArielQuint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector ActualLocation = GetActorLocation();
	if (Amplitude <= 300) {
		ActualLocation.Y += 5.0f;
		Amplitude += 5.0f;
	} else if (Amplitude >= 300 && Amplitude <= 600) {
		ActualLocation.Y -= 5.0f;
		Amplitude += 5.0f;
	}
	else if (Amplitude >= 600) {
		Amplitude = 0.0f;
	}

	SetActorLocation(ActualLocation);

}

void AColetavel_ArielQuint::OnOverlapBegin(UPrimitiveComponent*	OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
	OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if (OtherActor != nullptr && OtherActor->IsA(APersonagem::StaticClass())) {

		//Transforma(Cast) um um a Actor em um Personagem
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);

		Personagem->SetColected(Personagem->GetColected() + 10);
		UE_LOG(LogTemp, Warning, TEXT("Coletados %d"), Personagem->GetColected())

		if (Personagem->GetColected() == 10) {
			UE_LOG(LogTemp, Warning, TEXT("Tempo %f"), Personagem->TempoPercorrido);
		}

		Destroy();
	}
}

