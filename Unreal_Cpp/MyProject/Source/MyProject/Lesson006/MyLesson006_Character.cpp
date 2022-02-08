
#include "MyLesson006_Character.h"
#include "MyLesson006_AnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/SkeletalMeshSocket.h"

#include <DrawDebugHelpers.h>

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

	static FName AimLocatorName(TEXT("AimLocator"));
	AimLocator = CreateDefaultSubobject<USceneComponent>(AimLocatorName);
	AimLocator->SetRelativeLocation(FVector(500, 0, 0));
}

void AMyLesson006_Character::BeginPlay() {
	Super::BeginPlay();

	static FName SpawnBulletSocketName(TEXT("SpawnBulletSocket"));
	SpawnBulletSocket = MyFindSocket(SpawnBulletSocketName);

	static FName AimStartSocketName(TEXT("AimStartSocket"));
	AimStartSocket = MyFindSocket(AimStartSocketName);
}

const USkeletalMeshSocket* AMyLesson006_Character::MyFindSocket(FName name) {
	auto* sock = GetMesh()->GetSocketByName(name);
	if (!sock) {
		MY_LOG("cannot find socket {}", name);
	}
	return sock;
}


void AMyLesson006_Character::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	if (auto* startSock = AimStartSocket.Get()) {
		auto start = startSock->GetSocketLocation(GetMesh());
		auto aim   = AimLocator->GetComponentLocation();
		DrawDebugLine(GetWorld(), start, aim, FColor::Red);
	}
}

void AMyLesson006_Character::MyFire() {
	UClass* cls = BulletClass.Get();
	if (!cls) {
		MY_LOG("BulletClass is null");
		return;
	}

	if (auto* sock = SpawnBulletSocket.Get()) {
		FTransform trans = sock->GetSocketTransform(GetMesh());
		trans.SetScale3D(FVector::OneVector);
		GetWorld()->SpawnActor(cls, &trans);
	}
}
