#pragma once

#include "MyLesson006_Bullet.generated.h"

UCLASS()
class AMyLesson006_Bullet : public AActor {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	float SimPhysicTime;

	UPROPERTY(EditAnywhere)
	float Lifespan;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent = nullptr;


	virtual void Tick(float DeltaSeconds) override;

	AMyLesson006_Bullet();

private:
	UPROPERTY(VisibleAnywhere, Transient)
	float	_lifeTime = 0;
};