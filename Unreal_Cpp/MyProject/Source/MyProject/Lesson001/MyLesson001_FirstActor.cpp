// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLesson001_FirstActor.h"

// Sets default values
AMyLesson001_FirstActor::AMyLesson001_FirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
}

// Called when the game starts or when spawned
void AMyLesson001_FirstActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello World %d"), 200);
}

// Called every frame
void AMyLesson001_FirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
//	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Testing"));

	FRotator Rot = GetActorRotation();
	Rot.Yaw += RotateSpeed * DeltaTime;
	SetActorRotation(Rot);
}

