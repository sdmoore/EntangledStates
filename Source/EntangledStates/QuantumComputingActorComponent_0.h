// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuantumComputingActorComponent_0.generated.h"

USTRUCT(BlueprintType) struct FQuantumGateSpecifier_0 {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString GateType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<int32> ParameterQubits;
};

UCLASS(BlueprintType, meta = (BlueprintSpawnableComponent))
class ENTANGLEDSTATES_API UQuantumComputingActorComponent_0 : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UQuantumComputingActorComponent_0();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	TMap<FIntPoint, FVector2D> LocalGetPreparedOperator();
	int32 LocalParseNameIntArrayToGateOperator(int32 OperatorIndex, FString GateName, TArray<int32> IntArray);
	int32 LocalProduceMatrixIdentity(int32 OperationIndex);
	FVector2D LocalComplexMul(FVector2D A, FVector2D B);
	FVector2D LocalComplexAdd(FVector2D A, FVector2D B);
	int32 LocalGetBit(int32 value, int32 address);
	FVector2D LocalGetSpecificCCX(int32 value0, int32 value1, int32 control0, int32 control1, int32 target);
	FVector2D LocalGetSpecificCX(int32 value0, int32 value1, int32 control, int32 target);
	int32 Localintpow(int32 base, int32 power);
	// TMap<FIntPoint, FVector2D> LocalProduceMatrixCCX(int32 control0, int32 control1, int32 target); 
	int32 LocalProduceMatrixCX(int32 OperationIndex, int32 control, int32 target);
	int32 LocalProduceMatrixHadamard(int32 OperationIndex, int32 target);
	int32 LocalProduceMatrixX(int32 OperationIndex, int32 target);
	int32 LocalProduceMatrixY(int32 OperationIndex, int32 target);
	int32 LocalProduceMatrixZ(int32 OperationIndex, int32 target);
	int32 LocalProduceMatrixS(int32 OperationIndex, int32 target);
	int32 LocalProduceMatrixT(int32 OperationIndex, int32 target);
	int32 LocalProduceMatrixSingle(int32 OperationIndex, int32 InputTargetQubit, FVector2D MatrixVal0, FVector2D MatrixVal1, FVector2D MatrixVal2, FVector2D MatrixVal3);
	//int32 LocalProduceMatrixSingle(int32 OperationIndex, TArray<FVector2D> InputMatrix2x2, int32 InputTargetQubit);
	int32 LocalFxnGetMatrixValues(TArray<FQuantumGateSpecifier_0> InputList);
	int32 LocalFxnGetKetTransitions();
	int32 LocalInitialize(int32 QubitCountInput, int32 InputOperatorCount);
	UFUNCTION(BlueprintCallable, Category = "Quantum Computing") int32 LocalFxnSetCircuitState(int32 InputQubitCount, int32 InputOperatorCount, TArray<FQuantumGateSpecifier_0> InputList);//TArray<FVector2D> OutputOperations, TArray<FVector2D> OutputKets, TArray<FVector2D> OutputSpecificOperations);
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool LogOutputFlag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ObjOperatorCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ObjQubitCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ObjDimQ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FVector2D> KetArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FVector2D> OperatorGeneralArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FVector2D> OperatorSpecificArray;


};