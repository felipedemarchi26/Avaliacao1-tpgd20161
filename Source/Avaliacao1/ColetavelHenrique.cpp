// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "ColetavelHenrique.h"
#include "PersonagemHenrique.h"


// Sets default values
AColetavelHenrique::AColetavelHenrique()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DistanciaMover = 300;
	Velocidade = FMath::FRandRange(1, 15);
	Direction = FMath::FRandRange(0,1);

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AColetavelHenrique::OnOverlapBegin);
	CollisionComp->SetSphereRadius(34);
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->SetupAttachment(RootComponent);

	MeshComp->SetWorldScale3D(FVector(0.6f, 0.6f, 0.6f));
	MeshComp->SetWorldLocation(FVector(0.25f, -0.015f, -29.0f));

	ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}

	ConstructorHelpers::FObjectFinder<UMaterial>Mat(TEXT("Material'/Game/MaterialHenrique/MaterialHenrique.MaterialHenrique'"));

	if (Mat.Succeeded()) {
		MeshComp->SetMaterial(0, Mat.Object);
	}

}

// Called when the game starts or when spawned
void AColetavelHenrique::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
	
}

// Called every frame
void AColetavelHenrique::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover();


}

void AColetavelHenrique::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr && OtherActor->IsA(APersonagemHenrique::StaticClass())) {
		APersonagemHenrique* Personagem = Cast<APersonagemHenrique>(OtherActor);
		Personagem->SetPontuacao(Personagem->GetPontuacao() + 1);
		UE_LOG(LogTemp, Warning, TEXT("Pontuação: %d"), Personagem->GetPontuacao());

		if (Personagem->GetPontuacao() >= 10) {
			UE_LOG(LogTemp, Warning, TEXT("Fim de Jogo. Tempo: %d:%d"), Personagem->GetTempo() / 60 % 60, Personagem->GetTempo() % 60);
		}
		Destroy();
	}
}

void AColetavelHenrique::Mover()
{
	if (Direction == 0) {
		SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y + Velocidade, GetActorLocation().Z));
		if (GetActorLocation().Y >= InitialLocation.Y + DistanciaMover) {
			Direction = 1;
		}
	} else if (Direction == 1) {
		SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y - Velocidade, GetActorLocation().Z));
		if (GetActorLocation().Y <= InitialLocation.Y - DistanciaMover) {
			Direction = 0;
		}
	}
}