// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "ColetavelJonata.h"
#include "personagemJonata.h"


// Sets default values
AColetavelJonata::AColetavelJonata()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>
		(TEXT("CollisionComp"));

	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this,
		&AColetavelJonata :: OnOverlapBegin);
	RootComponent = CollisionComp;

	//CollisionComp->SetBoxExtent(FVector(15.0f, 15.0f, 15.0f));
	//RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>
		(TEXT("MeshComp"));

	MeshComp->SetCollisionProfileName("No Collision");
	ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	

	MeshComp->SetWorldScale3D(FVector(15.0f, 15.0f, 15.0f));
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -10.0f));
	MeshComp->SetupAttachment(RootComponent);





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
		
void AColetavelJonata::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (OtherActor != nullptr  && OtherActor->IsA(ApersonagemJonata::StaticClass())) {
		ApersonagemJonata* personagemJonata = Cast<ApersonagemJonata>(OtherActor);
		

	}
}

void AColetavelJonata::Posicao(AColetavelJonata*GetActorLocation){

		float X;
		float Y;

		X = FMath::FRandRange(-460.0f, 360.0f);
		Y = FMath::FRandRange(-500.0f, 330.0f);


		FVector NewPosiçao(X, Y, 0.0f);

		Num++;
		

		if (Num == 10) {
			Destroy();
		}
	
}

void AColetavelJonata::SetNum(int32 NewNum){
	Num = NewNum;

};

int32 AColetavelJonata::GetNum() {
	return Num;

}
void AColetavelJonata::AddNum() {
	Num++;
}


