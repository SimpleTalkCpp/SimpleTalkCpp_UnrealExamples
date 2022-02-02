#pragma once

#include "../Common/MyCommon.h"
#include "MyLesson003_Bullet.generated.h"

UCLASS()
class AMyLesson003_Bullet2 : public AActor {
	GENERATED_BODY()
public:
	AMyLesson003_Bullet2();

	UPROPERTY(VisibleAnywhere)
	class UMyLesson003_CubeComponent* CubeComponent = nullptr;

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 100;

	virtual void Tick(float DeltaSeconds) override;
};

//UCLASS()
//class AMyLesson003_Bullet : public AMyLesson003_Bullet2 {
//	GENERATED_BODY()
//};
