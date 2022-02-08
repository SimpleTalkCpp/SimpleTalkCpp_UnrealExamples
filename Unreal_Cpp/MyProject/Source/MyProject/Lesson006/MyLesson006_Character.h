#pragma once

#include "../Common/MyCommon.h"

#include <GameFramework/Character.h>

#include "MyLesson006_Bullet.h"
#include "MyLesson006_Character.generated.h"

UCLASS()
class AMyLesson006_Character : public ACharacter {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	bool MyCrouch = false;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AMyLesson006_Bullet>	BulletClass;

	AMyLesson006_Character();

	void MyFire();
};