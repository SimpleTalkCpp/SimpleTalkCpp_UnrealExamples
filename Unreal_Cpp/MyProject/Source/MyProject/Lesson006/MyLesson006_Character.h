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
	TSubclassOf<AMyLesson006_Bullet> BulletClass;

	UPROPERTY(EditAnywhere)
	TWeakObjectPtr<AActor>	Target;

	AMyLesson006_Character();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void MyFire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera = nullptr;

	const USkeletalMeshSocket* MyFindSocket(FName name);

	TWeakObjectPtr<USkeletalMeshSocket const> SpawnBulletSocket;
	TWeakObjectPtr<USkeletalMeshSocket const> AimStartSocket;
};