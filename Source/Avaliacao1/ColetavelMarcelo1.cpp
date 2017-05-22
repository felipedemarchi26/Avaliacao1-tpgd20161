// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "ColetavelMarcelo1.h"


// Sets default values
AColetavelMarcelo1::AColetavelMarcelo1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this,
		&AColetavelMarcelo1::OnOverlapBegin);
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>
		(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}

	ConstructorHelpers::FObjectFinder<UMaterial>MaterialMarcelo1(TEXT("Material'/Game/MaterialMarcelo/NewMaterial.NewMaterial'"));

	if (MaterialMarcelo1.Succeeded()) {
		MaterialBlack = MaterialMarcelo1.Object;

	}
	ConstructorHelpers::FObjectFinder<UMaterial>MaterialMarcelo2(TEXT("Material'/Game/MaterialMarcelo/NewMaterial2.NewMaterial2'"));
	if (MaterialMarcelo2.Succeeded()) {
		MaterialPink = MaterialMarcelo2.Object;

	}
	ConstructorHelpers::FObjectFinder<UMaterial>MaterialMarcelo3(TEXT("Material'/Game/MaterialMarcelo/NewMaterial3.NewMaterial3'"));
	if (MaterialMarcelo3.Succeeded()) {
		MaterialPurple = MaterialMarcelo3.Object;

	}
	ConstructorHelpers::FObjectFinder<UMaterial>MaterialMarcelo4(TEXT("Material'/Game/MaterialMarcelo/NewMaterial4.NewMaterial4'"));
	if (MaterialMarcelo4.Succeeded()) {
		MaterialWhite = MaterialMarcelo4.Object;

	}
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f,-30.0f));
	MeshComp->SetWorldScale3D(FVector(0.6f, 0.6f, 0.6f));
	MeshComp->SetMaterial(0, MaterialBlack);
	MeshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AColetavelMarcelo1::BeginPlay()
{
	Super::BeginPlay();
	IndexMarcelo = 0;
	Contador = 0;
	Pink = false;
	
}

// Called every frame
void AColetavelMarcelo1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IndexMarcelo == 1) {
		Pink = true;
	}
	else {
		Pink = false;
	}

}
bool AColetavelMarcelo1::IsPink()
{
	return Pink;
}

void AColetavelMarcelo1::SetPink(bool NewPink)
{
	Pink = NewPink;
}

void AColetavelMarcelo1::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ChangeCollor();
}

void AColetavelMarcelo1::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

void AColetavelMarcelo1::ChangeCollor() {
	switch (IndexMarcelo) {
		case 0:
			MeshComp->SetMaterial(0, MaterialPink);
			IndexMarcelo++;
			break;
		case 1:
			MeshComp->SetMaterial(0, MaterialPurple);
			IndexMarcelo++;
			break;
		case 2:
			MeshComp->SetMaterial(0, MaterialWhite);
			IndexMarcelo++;
			break;
		case 3:
			MeshComp->SetMaterial(0, MaterialBlack);
			IndexMarcelo = 0;
			break;
	}
	Contador++;
}
int AColetavelMarcelo1::GetContador() {
	return Contador;
}
void AColetavelMarcelo1::SetContador(int NewContador) {
	Contador = NewContador;
}
