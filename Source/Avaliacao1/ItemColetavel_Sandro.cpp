// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "ItemColetavel_Sandro.h"


// Sets default values
AItemColetavel_Sandro::AItemColetavel_Sandro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Colisao"));
	CollisionComp->OnComponentHit.AddDynamic(this, &AItemColetavel_Sandro::OnHit);
	CollisionComp->SetCollisionProfileName("BlockAllDynamic");
	RootComponent = CollisionComp;
		

	MalhaEstatica = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coletavel"));
	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	// muda a localização
	MalhaEstatica->SetWorldLocation(FVector(0.0f, 0.0f, -40.0f));
	// muda o tamanho [da malha estática]
	MalhaEstatica->SetWorldScale3D(FVector(0.8f, 0.8f, 0.8f));
	if (MeshRef.Succeeded()) {
		MalhaEstatica->SetStaticMesh(MeshRef.Object);
	}
	MalhaEstatica->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AItemColetavel_Sandro::BeginPlay()
{
	Super::BeginPlay();
	direcao = 1;
}

// Called every frame
void AItemColetavel_Sandro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Movimentacao();
	Rotacao();
	
}

void AItemColetavel_Sandro::OnHit(UPrimitiveComponent* HitComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	const FHitResult& Hit) {

	switch (girada)
	{
	case 0: 
	case 1: 
		girada++;
		break;
	case 2: girada = 0;
		break;
	}
}


void AItemColetavel_Sandro::Rotacao() {
	float pitch = GetActorRotation().Pitch;
	float yaw = GetActorRotation().Yaw;
	float roll = GetActorRotation().Roll;
	
	UE_LOG(LogTemp, Warning, TEXT("GIRADA: %d"),girada);
	
	
	switch (girada)
	{
	case 0: 
		SetActorRotation(FRotator(pitch + 0.5f, yaw, roll));
		UE_LOG(LogTemp, Warning, TEXT("PITCH: %d"), pitch);
		break;
	case 1: 
		SetActorRotation(FRotator(pitch, yaw + 0.5f, roll));
		UE_LOG(LogTemp, Warning, TEXT("YAW: %d"), yaw);
		break;
	case 2:  
		SetActorRotation(FRotator(pitch, yaw, roll + 0.5f));
		UE_LOG(LogTemp, Warning, TEXT("ROLL: %d"), roll);
		break;

	}
	
}

void AItemColetavel_Sandro::Movimentacao() {
	int velocidade = 5 * direcao;
	int x = GetActorLocation().X;
	int y = GetActorLocation().Y;
	SetActorLocation(FVector(x + velocidade, y, GetActorLocation().Z));
	if (GetActorLocation().X >= 500.0f || GetActorLocation().X <= -500.0f || GetActorLocation().Y >= 500.0f || GetActorLocation().Y <= -500.0f)
	{
		direcao *= -1;
		
			}

}
