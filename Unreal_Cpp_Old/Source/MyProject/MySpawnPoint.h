#pragma once

#include "CoreMinimal.h"
#include "MySpawnPoint.generated.h"

UCLASS()
class AMySpawnPoint : public AActor {
	GENERATED_BODY()
public:

	AMySpawnPoint();

	virtual void Tick(float DeltaSeconds) override;

	void SpawnActor();

	FVector GetRandomLocation();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> SpawnActorClass;

	UPROPERTY(EditAnywhere)
	float Radius = 100;

	UPROPERTY(EditAnywhere)
	float SpawnInterval = 5;

	float _RemainTime = 0;

	UPROPERTY(VisibleAnywhere) class UBoxComponent*		BoxComponent = nullptr;
	UPROPERTY(VisibleAnywhere) class USphereComponent*	SphereComponent = nullptr;
	UPROPERTY(VisibleAnywhere) class USphereComponent*	SphereComponent2 = nullptr;

	UPROPERTY(VisibleAnywhere) class UMySceneComponent* MySceneComponent = nullptr;

	UPROPERTY(VisibleAnywhere) class UBillboardComponent* BillboardComponent = nullptr;
};