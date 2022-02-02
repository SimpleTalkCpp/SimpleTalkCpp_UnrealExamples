// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyLesson001_FirstActor.generated.h"

UCLASS()
class MYPROJECT_API AMyLesson001_FirstActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
	int TestInt = 100;

	UPROPERTY(EditAnywhere)
	float  RotateSpeed = 360;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent = nullptr;


	// Sets default values for this actor's properties
	AMyLesson001_FirstActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
