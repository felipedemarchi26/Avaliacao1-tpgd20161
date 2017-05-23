// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "ColetavelPaulo.h"


// Sets default values
AColetavelPaulo::AColetavelPaulo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AColetavelPaulo::OnOverlapBegin);
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}

	ConstructorHelpers::FObjectFinder<UMaterial>Mat(TEXT("Material'/Game/MaterialsPaulo/MaterialPaulo.MaterialPaulo'"));

	if (Mat.Succeeded()) {
		MeshComp->SetMaterial(0, Mat.Object);
	}

	MeshComp->SetWorldScale3D(FVector(0.6f, 0.6f, 0.6f));
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -30.0f));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AColetavelPaulo::BeginPlay()
{
	Super::BeginPlay();
	ChangePosition();
	Cont--;
	ZMin = GetActorLocation().Z - 15;
	ZMax = GetActorLocation().Z + 15;
	Bouncing = 1;
	GetWorldTimerManager().SetTimer(MyTimer, this, &AColetavelPaulo::AddSec, 1.0f, true);
	
}

// Called every frame
void AColetavelPaulo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Bounce();
	Spin();
}

void AColetavelPaulo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult) {
	ChangePosition();

}


void AColetavelPaulo::ChangePosition() {
	
	float X;
	float Y;
	bool Loop = true;

	while (Loop) {

		X = FMath::FRandRange(-460.0f, 460.0f);
		Y = FMath::FRandRange(-460.0f, 460.0f);

		if (X <= GetActorLocation().X - 100 || X >= GetActorLocation().X + 100) {
			Loop = false;
		}
	}
	FVector NewPosition(X, Y, GetActorLocation().Z);
	SetActorLocation(NewPosition);
	Cont++;

	if (Cont >= 20) {
		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Tempo: %d"), Tempo);
	}

}
void AColetavelPaulo::SetCont(int32 NewCont)
{
	Cont = NewCont;
}

int32 AColetavelPaulo::GetCont() {
	return Cont;
}

void AColetavelPaulo::Spin()
{
	SetActorRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw + 1, GetActorRotation().Roll));
}

void AColetavelPaulo::Bounce() {

	if (GetActorLocation().Z > ZMax || GetActorLocation().Z < ZMin) {
		Bouncing *= -1;
	}

	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + (0.25 * Bouncing)));

}

void AColetavelPaulo::AddSec() {
	Tempo += 1;
}