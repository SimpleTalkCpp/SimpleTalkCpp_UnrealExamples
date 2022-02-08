
#include "MyLesson006_Character.h"
#include "MyLesson006_AnimInstance.h"

#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include <Engine/SkeletalMeshSocket.h>
#include "GameFramework/CharacterMovementComponent.h"
#include <GameFramework/SpringArmComponent.h>

#include <DrawDebugHelpers.h>
#include <Kismet/GameplayStatics.h>

AMyLesson006_Character::AMyLesson006_Character() {
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("SkeletalMesh'/Game/AnimStarterPack/UE4_Mannequin/Mesh/SK_Mannequin'"));
	GetMesh()->SkeletalMesh = mesh.Object;
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -97), FRotator(0, 270, 0));

	// AnimBP
	static ConstructorHelpers::FClassFinder<UMyLesson006_AnimInstance> animBP(TEXT("AnimBlueprint'/Game/SimpleTalkCpp/Lesson006/Lesson006_AnimBP'"));
	GetMesh()->AnimClass = animBP.Class;

	// Character Movement
	bUseControllerRotationYaw = true;

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->MaxWalkSpeed = 150;

	// Bullet
	BulletClass = AMyLesson006_Bullet::StaticClass();
}

void AMyLesson006_Character::BeginPlay() {
	Super::BeginPlay();

	static FName SpawnBulletSocketName(TEXT("SpawnBulletSocket"));
	SpawnBulletSocket = MyFindSocket(SpawnBulletSocketName);

	static FName AimStartSocketName(TEXT("AimStartSocket"));
	AimStartSocket = MyFindSocket(AimStartSocketName);

	TArray<AActor*> TargetList;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("MyTarget"), TargetList);
	if (TargetList.Num() > 0) {
		Target = TargetList[0];
	}
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

	if (auto* t = Target.Get()) {
		if (auto* startSock = AimStartSocket.Get()) {
			auto start = startSock->GetSocketLocation(GetMesh());
			auto aim   = t->GetActorLocation();
			DrawDebugLine(GetWorld(), start, aim, FColor::Red);
		}
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
