// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuantumComputingActorComponent.generated.h"

UENUM(BlueprintType)
enum EQuantumGateType
{
	VE_QuantumGateNull UMETA(DisplayName = "Null Gate"),
	VE_QuantumGateIdentity UMETA(DisplayName = "Identity Gate"),
	VE_QuantumGateH UMETA(DisplayName = "Hadamard Gate"),
	VE_QuantumGateX UMETA(DisplayName = "X Gate"),
	VE_QuantumGateY UMETA(DisplayName = "Y Gate"),
	VE_QuantumGateZ UMETA(DisplayName = "Z Gate"),
	VE_QuantumGateS UMETA(DisplayName = "S Gate"),
	VE_QuantumGateT UMETA(DisplayName = "T Gate"),
	VE_QuantumGateTDAG UMETA(DisplayName = "Inverse T Gate"),
	VE_QuantumGateCX UMETA(DisplayName = "Controlled X Gate"),
};
USTRUCT(BlueprintType) struct FQuantumGateSpecifier {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TEnumAsByte<EQuantumGateType> EnumGateType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<int32> ParameterQubits;
};
USTRUCT(BlueprintType) struct FQuantumStateSpecifier {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Evolution;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 StateIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector2D StateValue;
};

USTRUCT(BlueprintType) struct FQuantumTransitionTo {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Enum_012_SameSplitFlip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 EndState0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 EndState1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector2D TransitionValue0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector2D TransitionValue1;
};


UCLASS(BlueprintType, /*ClassGroup=(Custom), */meta=(BlueprintSpawnableComponent) )
class ENTANGLEDSTATES_API UQuantumComputingActorComponent : public UActorComponent
{
	GENERATED_BODY()
	uint32 ToggledBit(uint32 InputNumber, uint32 InputBit);
	uint32 CheckBit(uint32 InputNumber, uint32 InputBit);
	uint32 SwitchBitIf(uint32 InputNumber, uint32 InputControlBit, uint32 InputTargetBit);
	uint32 uint32pow(uint32 base, uint32 power);

public:	
	// Sets default values for this component's properties
	UQuantumComputingActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool LogOutputFlag;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	int32 ParseNameIntArrayToGateOperator(int32 QubitCount, int32 InputOperation, TEnumAsByte<EQuantumGateType> InputEnumGateType, TArray<int32> IntArray);
	UFUNCTION(BlueprintCallable, Category = "Quantum Computing") int32 FxnSetCircuitDescription(TMap<int32, FVector2D> InputKet, TArray<FQuantumGateSpecifier> InputList);
	UFUNCTION(BlueprintCallable, Category = "Quantum Computing") int32 FxnSetCircuitDescriptionSpecified(int32 QubitCountInput, TMap<int32, FVector2D> InputKet, TArray<FQuantumGateSpecifier> InputList);
	UFUNCTION(BlueprintCallable, Category = "Quantum Computing") TArray<bool> FxnGetBoolArray(int32 ParamQubitCount, int32 ParamInputInteger);
	FVector2D ComplexMul(FVector2D A, FVector2D B);
	FVector2D ComplexAdd(FVector2D A, FVector2D B);
	FVector2D MagPhaseMul(FVector2D A, FVector2D B);
	FVector2D MagPhaseAdd(FVector2D A, FVector2D B);
	int32 SingleGateStateTransitionsAdditional(
		int32 ParamInputEnum_SameSplitFlip_012, int32 ParamInputOperation, int32 ParamInputNumber, int32 ParamInputTargetBit,
		FVector2D FVectorMultiplier0, FVector2D FVectorMultiplier1, FVector2D FVectorMultiplier2, FVector2D FVectorMultiplier3);
	int32 intpow(int32 base, int32 power);
	int32 FxnAddKetState(FIntPoint InputFIP, FVector2D InputFV2D);
	//TMultiMap<FIntPoint, FQuantumTransitionTo> ExistingTransitions;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<FIntPoint, FIntPoint> MapIntSpecificArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ObjMaximumOperatorCount = 20;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ObjOperatorCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) int32 ObjQubitCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ObjDimQ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool FixedQubitCountDefaultFlag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ObjQubitCountDefault = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ObjMinimumQubitCount = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ObjMaximumQubitCount = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ObjStartStateIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ObjFloatThreshold;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<FIntPoint, FVector2D> SpecificStateMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<FIntPoint, FQuantumTransitionTo> GeneralOperatorMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<FIntPoint, FQuantumTransitionTo> SpecificOperatorMap;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
};
