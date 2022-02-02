#pragma once

#include "../Common/MyCommon.h"
#include "MyLesson003_Bullet.h"

#include "MyLesson003_Actor.generated.h"

UCLASS()
class AMyLesson003_Actor : public AActor {
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere)
	UBillboardComponent* BillboardComponent = nullptr;

	UPROPERTY(VisibleAnywhere)
	class UMyLesson003_GunComponent* GunComponent = nullptr;

	UPROPERTY(VisibleAnywhere)
	class UMyLesson003_RotateComponent* RotateComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AMyLesson003_Bullet2>	BulletClass;

	AMyLesson003_Actor();
	virtual void BeginPlay() override;
};