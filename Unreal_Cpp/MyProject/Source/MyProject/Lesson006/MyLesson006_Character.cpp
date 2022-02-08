
#include "MyLesson006_Character.h"
#include "MyLesson006_AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/SkeletalMeshSocket.h"

AMyLesson006_Character::AMyLesson006_Character() {

	GetCapsuleComponent()->SetCapsuleHalfHeight(97);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("SkeletalMesh'/Game/AnimStarterPack/UE4_Mannequin/Mesh/SK_Mannequin'"));
	GetMesh()->SkeletalMesh = mesh.Object;
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -97), FRotator(0, 270, 0));

	static ConstructorHelpers::FClassFinder<UMyLesson006_AnimInstance> animBP(TEXT("AnimBlueprint'/Game/SimpleTalkCpp/Lesson006/Lesson006_AnimBP'"));
	GetMesh()->AnimClass = animBP.Class;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw   = false;


	BulletClass = AMyLesson006_Bullet::StaticClass();
}

void AMyLesson006_Character::MyFire() {
	UClass* cls = BulletClass.Get();
	if (!cls) {
		MY_LOG("BulletClass is null");
		return;
	}

	static FName SpawnBulletSocket(TEXT("SpawnBulletSocket"));
	auto* sock = GetMesh()->GetSocketByName(SpawnBulletSocket);
	if (!sock) {
		MY_LOG("cannot find socket {}", SpawnBulletSocket);
		return;
	}

	FTransform trans = sock->GetSocketTransform(GetMesh());
	trans.SetScale3D(FVector::OneVector);
	GetWorld()->SpawnActor(cls, &trans);
}
