#pragma once

#include "../Common/MyCommon.h"
#include "MyLesson002_Actor.generated.h"

USTRUCT()
struct FMyLesson002_MyStruct {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) float x;
	UPROPERTY(EditAnywhere) float y;
};

USTRUCT(NoExport)
struct FMyLesson002_MyStruct2 {
	UPROPERTY(EditAnywhere) float x;
	UPROPERTY(EditAnywhere) float y;
};

UCLASS()
class UMyLesson002_MyObject : public UObject {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) float x;
	UPROPERTY(EditAnywhere) float y;	
};

UENUM()
enum EMyLesson002_MyEnum {
	EMyLesson002_A,
	EMyLesson002_B,
	EMyLesson002_C,
};

UENUM()
enum class EMyLesson002_MyEnumClass {
	A,
	B,
	C UMETA(DisplayName="CCCC"),
};

ENUM_CLASS_FLAGS(EMyLesson002_MyEnumClass)

//inline
//EMyLesson002_MyEnumClass operator|(EMyLesson002_MyEnumClass a, EMyLesson002_MyEnumClass b) {
//	int v = static_cast<int>(a) | static_cast<int>(b);
//	return static_cast<EMyLesson002_MyEnumClass>(v);
//}

UCLASS()
class AMyLesson002_Actor : public AActor {
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	int Test_Edit = 0;
	
	UPROPERTY(VisibleAnywhere)
	int Test_Visible = 0;
	
	UPROPERTY(EditAnywhere, Category="My Category")
	int Test_Category = 0;
	
	UPROPERTY(EditAnywhere, Transient)
	int Test_Transient = 0;

	UPROPERTY(EditAnywhere, meta=(DisplayName = "Test Name"))
	int Test_DisplayName = 0;
	
	UPROPERTY(EditAnywhere, meta=(ClampMin = "0", ClampMax = "100"))
	int Test_Clamp = 0;

	UPROPERTY(EditAnywhere)
	bool Test_Condition_Bool = false;

	UPROPERTY(EditAnywhere, meta=(EditCondition="Test_Condition_Bool"))
	int Test_Condition_Int = 0;

	UPROPERTY(EditAnywhere)
	FString Test_FString;

	UPROPERTY(EditAnywhere)
	FName Test_FName;

	UPROPERTY(EditAnywhere)
	FText Test_FText;

	UPROPERTY(EditAnywhere)
	FMyLesson002_MyStruct Test_Struct;

	UPROPERTY(EditAnywhere)
	UMyLesson002_MyObject* Test_Object = nullptr;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<EMyLesson002_MyEnum> Test_Enum;

	UPROPERTY(EditAnywhere)
	EMyLesson002_MyEnumClass Test_EnumClass;

	void DemoStringFormat();
	void DemoEnum();

};