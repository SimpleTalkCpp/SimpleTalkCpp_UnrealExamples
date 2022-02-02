#include "MyLesson002_Actor.h"

void AMyLesson002_Actor::BeginPlay() {
	Super::BeginPlay();

	DemoStringFormat();
	DemoEnum();

	FName a(TEXT("abc5"));
	FName b(TEXT("abc100"));
}

void AMyLesson002_Actor::DemoEnum() {
	UEnum* EnumInfo = StaticEnum<EMyLesson002_MyEnumClass>();
	int N = EnumInfo->NumEnums();
	for (int i = 0; i < N; i++) {
		int64 value = EnumInfo->GetValueByIndex(i);
		FName name  = EnumInfo->GetNameByIndex(i);
		MY_LOG("EnumInfo {} {} {}", i, value, name);
	}

	{
		auto value = static_cast<EMyLesson002_MyEnumClass>(EnumInfo->GetValueByNameString("B"));
		MY_LOG("EnumInfo GetValueByNameString {}", value);
	}

	auto EnumBitwiseOr = EMyLesson002_MyEnumClass::A | EMyLesson002_MyEnumClass::B;
	MY_LOG("EnumInfo EnumBitwiseOr {}", EnumBitwiseOr);
}

void AMyLesson002_Actor::DemoStringFormat() {

	const char*    sz  = "Hello";
	const wchar_t* wcs = L"Hello";
	const TCHAR*   tcs = TEXT("Hello");

	{
		FString str = FString::Printf(TEXT("FString Printf %d %d %f %s"), 1, 2, 1.23f, TEXT("Hi!"));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	}

	{
		FString str = FString::Printf(TEXT("FString Printf is unsafe %s"), "Hi!");
		UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	}

	{
		FStringFormatOrderedArguments Args;
		Args.Add(123);
		Args.Add(2);
		Args.Add(1.23f);
		Args.Add(TEXT("Hi!"));
		FString str = FString::Format(TEXT("FString Format Ordered {0} {1} {2} {3}"), Args);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	}

	{
		FStringFormatNamedArguments Args;
		Args.Add("A", 123);
		Args.Add("B", 2);
		Args.Add("C", 1.23f);
		Args.Add("D", TEXT("Hi!"));
		FString str = FString::Format(TEXT("FString Format Named {A} {B} {C} {D}"), Args);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	}

	{
		FString str = MyFormat("MyFormat {} {}", 123, "string");
		UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	}

	MY_LOG("MY_LOG Test {}", 123);
}

