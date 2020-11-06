// Fill out your copyright notice in the Description page of Project Settings.


#include "QuantumComputingActorComponent_0.h"


// Sets default values for this component's properties
UQuantumComputingActorComponent_0::UQuantumComputingActorComponent_0()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	LogOutputFlag = false;
	// ...
}
// Called when the game starts
void UQuantumComputingActorComponent_0::BeginPlay()
{
	Super::BeginPlay();

	// ...

}
// Called every frame
void UQuantumComputingActorComponent_0::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TMap<FIntPoint, FVector2D> UQuantumComputingActorComponent_0::LocalGetPreparedOperator() {
	TMap<FIntPoint, FVector2D> PreparedTMap;
	for (int32 i = 0; i < ObjDimQ; i++) {
		for (int32 j = 0; j < ObjDimQ; j++) {
			PreparedTMap.Add(FIntPoint(i, j), FVector2D(0, 0));
		}
	}
	return PreparedTMap;
}
int32 UQuantumComputingActorComponent_0::LocalParseNameIntArrayToGateOperator(int32 OperatorIndex, FString GateName, TArray<int32> IntArray) {
	if (GateName == FString("h") && IntArray.Num() == 1) {
		LocalProduceMatrixHadamard(OperatorIndex, IntArray[0]);
	}
	else if (GateName == FString("x") && IntArray.Num() == 1) {
		LocalProduceMatrixX(OperatorIndex, IntArray[0]);
	}
	else if (GateName == FString("y") && IntArray.Num() == 1) {
		LocalProduceMatrixY(OperatorIndex, IntArray[0]);
	}
	else if (GateName == FString("z") && IntArray.Num() == 1) {
		LocalProduceMatrixZ(OperatorIndex, IntArray[0]);
	}
	else if (GateName == FString("s") && IntArray.Num() == 1) {
		LocalProduceMatrixS(OperatorIndex, IntArray[0]);
	}
	else if (GateName == FString("t") && IntArray.Num() == 1) {
		LocalProduceMatrixT(OperatorIndex, IntArray[0]);
	}
	else if (GateName == FString("cx") && IntArray.Num() == 2) {
		LocalProduceMatrixCX(OperatorIndex, IntArray[0], IntArray[1]);
	}
	//else if (GateName == FString("ccx") && IntArray.Num() == 3) {
	//		LocalProduceMatrixCCX(OperatorIndex, IntArray[0], IntArray[1], IntArray[2]);
	//}
	else {
		LocalProduceMatrixIdentity(OperatorIndex);
	}
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalProduceMatrixIdentity(int32 OperationIndex) {
	for (int32 i = 0; i < ObjDimQ; i++) {
		for (int32 j = 0; j < ObjDimQ; j++) {
			if (i == j) {
				OperatorGeneralArray[OperationIndex * ObjDimQ * ObjDimQ + i * ObjDimQ + j] = FVector2D(1, 0);
			}
			else {
				OperatorGeneralArray[OperationIndex * ObjDimQ * ObjDimQ + i * ObjDimQ + j] = FVector2D(0, 0);
			}

		}
	}
	return 0;
}
FVector2D UQuantumComputingActorComponent_0::LocalComplexMul(FVector2D A, FVector2D B) {
	FVector2D ReturnFVector2D;
	ReturnFVector2D.X = A.X * B.X - A.Y * B.Y;
	ReturnFVector2D.Y = A.Y + B.Y;
	return ReturnFVector2D;
}
FVector2D UQuantumComputingActorComponent_0::LocalComplexAdd(FVector2D A, FVector2D B) {
	FVector2D ReturnFVector2D;
	ReturnFVector2D.X = A.X + B.X;
	ReturnFVector2D.Y = A.Y + B.Y;
	return ReturnFVector2D;
}
int32 UQuantumComputingActorComponent_0::LocalGetBit(int32 value, int32 address) {
	int32 newvalue = value >> address;
	return (newvalue % 2);
}
FVector2D UQuantumComputingActorComponent_0::LocalGetSpecificCCX(int32 value0, int32 value1, int32 control0, int32 control1, int32 target) {
	if (LocalGetBit(value0, control0) == LocalGetBit(value0, control0) &&
		LocalGetBit(value0, control1) == LocalGetBit(value0, control1) &&
		LocalGetBit(value0, target) != LocalGetBit(value0, target)) {
		return FVector2D(1, 0);
	}
	else {
		return FVector2D(0, 0);
	}
}
FVector2D UQuantumComputingActorComponent_0::LocalGetSpecificCX(int32 value0, int32 value1, int32 control, int32 target) {
	if (LocalGetBit(value0, control) == LocalGetBit(value0, control) &&
		LocalGetBit(value0, target) != LocalGetBit(value0, target)) {
		return FVector2D(1, 0);
	}
	else {
		return FVector2D(0, 0);
	}
}
int32 UQuantumComputingActorComponent_0::Localintpow(int32 base, int32 power) {
	int32 result = 1;
	for (int32 i = 0; i < power; i++) {
		result = result * base;
	}
	return result;
}
// TMap<FIntPoint, FVector2D> UQuantumComputingActorComponent_0::LocalProduceMatrixCCX(int32 control0, int32 control1, int32 target) {
	// TMap<FIntPoint, FVector2D> NewMatrix = GetPreparedOperator();
	// for (int32 i = 0; i < ObjDimQ; i++) {
		// //int32 FirstIndex = ((i % (2 * AddressStep)) < AdressStep ? 0 : 1);
		// for (int32 j = 0; j < ObjDimQ; j++) {
			// //int32 SecondIndex = ((i % (2 * AddressStep)) < AdressStep ? 0 : 1);
			// NewMatrix[FIntPoint(i, j)] = GetSpecificCCX(i, j, control0, control1, target);
		// }
	// }
	// return NewMatrix;
// }
int32 UQuantumComputingActorComponent_0::LocalProduceMatrixCX(int32 OperationIndex, int32 control, int32 target) {
	int32 viCV = Localintpow(2, control); // (1 << control);
	int32 viCVP = Localintpow(2, control + 1); // (1 << (control + 1));
	int32 viTV = Localintpow(2, target); // (1 << target);
	int32 viTVP = Localintpow(2, target + 1); // (1 << (target + 1));
	for (int32 i = OperationIndex * ObjDimQ * ObjDimQ; i < ObjDimQ * ObjDimQ; i++) {
		OperatorGeneralArray[i] = FVector2D(0, 0);
	}
	for (int32 i = 0; i < ObjDimQ; i++) {
		if ((i % viCVP) >= viCV) {
			if ((i % viTVP) >= viTV) {
				OperatorGeneralArray[OperationIndex * ObjDimQ * ObjDimQ + i * ObjDimQ + i - viTV] = FVector2D(1, 0);
			}
			else {
				OperatorGeneralArray[OperationIndex * ObjDimQ * ObjDimQ + i * ObjDimQ + i + viTV] = FVector2D(1, 0);
			}
		}
		else {
			OperatorGeneralArray[OperationIndex * ObjDimQ * ObjDimQ + i * ObjDimQ + i] = FVector2D(1, 0);
		}
	}
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalProduceMatrixHadamard(int32 OperationIndex, int32 target) {
	TArray<FVector2D> TMapInput;
	TMapInput.Init(FVector2D(0, 0), 4);
	FVector2D Base2x2Matrix0 = FVector2D(0.70710678118, 0);
	FVector2D Base2x2Matrix1 = FVector2D(0.70710678118, 0);
	FVector2D Base2x2Matrix2 = FVector2D(0.70710678118, 0);
	FVector2D Base2x2Matrix3 = FVector2D(-0.70710678118, 0);
	LocalProduceMatrixSingle(OperationIndex, target, Base2x2Matrix0, Base2x2Matrix1, Base2x2Matrix2, Base2x2Matrix3);
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalProduceMatrixX(int32 OperationIndex, int32 target) {
	TArray<FVector2D> TMapInput;
	TMapInput.Init(FVector2D(0, 0), 4);
	FVector2D Base2x2Matrix0 = FVector2D(0, 0);
	FVector2D Base2x2Matrix1 = FVector2D(1, 0);
	FVector2D Base2x2Matrix2 = FVector2D(1, 0);
	FVector2D Base2x2Matrix3 = FVector2D(0, 0);
	LocalProduceMatrixSingle(OperationIndex, target, Base2x2Matrix0, Base2x2Matrix1, Base2x2Matrix2, Base2x2Matrix3);
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalProduceMatrixY(int32 OperationIndex, int32 target) {
	TArray<FVector2D> TMapInput;
	TMapInput.Init(FVector2D(0, 0), 4);
	FVector2D Base2x2Matrix0 = FVector2D(0, 0);
	FVector2D Base2x2Matrix1 = FVector2D(0, -1);
	FVector2D Base2x2Matrix2 = FVector2D(0, 1);
	FVector2D Base2x2Matrix3 = FVector2D(0, 0);
	LocalProduceMatrixSingle(OperationIndex, target, Base2x2Matrix0, Base2x2Matrix1, Base2x2Matrix2, Base2x2Matrix3);
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalProduceMatrixZ(int32 OperationIndex, int32 target) {
	TArray<FVector2D> TMapInput;
	TMapInput.Init(FVector2D(0, 0), 4);
	FVector2D Base2x2Matrix0 = FVector2D(1, 0);
	FVector2D Base2x2Matrix1 = FVector2D(0, 0);
	FVector2D Base2x2Matrix2 = FVector2D(0, 0);
	FVector2D Base2x2Matrix3 = FVector2D(-1, 0);
	LocalProduceMatrixSingle(OperationIndex, target, Base2x2Matrix0, Base2x2Matrix1, Base2x2Matrix2, Base2x2Matrix3);
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalProduceMatrixS(int32 OperationIndex, int32 target) {
	TArray<FVector2D> TMapInput;
	TMapInput.Init(FVector2D(0, 0), 4);
	FVector2D Base2x2Matrix0 = FVector2D(1, 0);
	FVector2D Base2x2Matrix1 = FVector2D(0, 0);
	FVector2D Base2x2Matrix2 = FVector2D(0, 0);
	FVector2D Base2x2Matrix3 = FVector2D(0, 1);
	LocalProduceMatrixSingle(OperationIndex, target, Base2x2Matrix0, Base2x2Matrix1, Base2x2Matrix2, Base2x2Matrix3);
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalProduceMatrixT(int32 OperationIndex, int32 target) {
	TArray<FVector2D> TMapInput;
	TMapInput.Init(FVector2D(0, 0), 4);
	FVector2D Base2x2Matrix0 = FVector2D(1, 0);
	FVector2D Base2x2Matrix1 = FVector2D(0, 0);
	FVector2D Base2x2Matrix2 = FVector2D(0, 0);
	FVector2D Base2x2Matrix3 = FVector2D(0.70710678118, 0.70710678118);
	LocalProduceMatrixSingle(OperationIndex, target, Base2x2Matrix0, Base2x2Matrix1, Base2x2Matrix2, Base2x2Matrix3);
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalProduceMatrixSingle(int32 OperationIndex, int32 InputTargetQubit, FVector2D MatrixVal0, FVector2D MatrixVal1, FVector2D MatrixVal2, FVector2D MatrixVal3) {
	TArray<FVector2D> InputMatrix2x2;
	InputMatrix2x2.Add(MatrixVal0);
	InputMatrix2x2.Add(MatrixVal1);
	InputMatrix2x2.Add(MatrixVal2);
	InputMatrix2x2.Add(MatrixVal3);
	TArray<FVector2D> NewSubMatrix;
	int32 DimSubUnitQ = Localintpow(2, InputTargetQubit);
	int32 DimSubQ = Localintpow(2, InputTargetQubit + 1);
	NewSubMatrix.Init(FVector2D(0, 0), DimSubQ * DimSubQ);
	for (int32 i = 0; i < DimSubQ; i++) {
		for (int32 j = 0; j < DimSubQ; j++) {
			NewSubMatrix[i * DimSubQ + j] = FVector2D(0, 0);
		}
	}
	for (int32 i = 0; i < DimSubQ; i++) {
		for (int32 j = 0; j < DimSubQ; j++) {
			int32 LocalValueI, LocalValueJ, ValueI_2x2, ValueJ_2x2;
			if (i < DimSubUnitQ) {
				LocalValueI = i;
				ValueI_2x2 = 0;
			}
			else {
				LocalValueI = i - DimSubUnitQ;
				ValueI_2x2 = 1;
			}
			if (j < DimSubUnitQ) {
				LocalValueJ = j;
				ValueJ_2x2 = 0;
			}
			else {
				LocalValueJ = j - DimSubUnitQ;
				ValueJ_2x2 = 1;
			}
			if (LocalValueI == LocalValueJ) {
				NewSubMatrix[i * DimSubQ + j] = InputMatrix2x2[ValueI_2x2 * 2 + ValueJ_2x2];
			}
			else {
				NewSubMatrix[i * DimSubQ + j] = FVector2D(0, 0);
			}
			if (LogOutputFlag) {
				UE_LOG(LogTemp, Warning,
					TEXT("SUB LOOP: MATRIX={{% f,% f},{% f,% f}} = (% d, % d, % d) = ( DimSubQ=% d, DimSubUnitQ=% d, ValueI_2x2=% d, ValueJ_2x2=% d, LocalValueI=% d, LocalValueJ=% d) = % f"),
					InputMatrix2x2[0].X, InputMatrix2x2[1].X, InputMatrix2x2[2].X, InputMatrix2x2[3].X, OperationIndex, i, j, DimSubQ, DimSubUnitQ, ValueI_2x2, ValueJ_2x2,
					LocalValueI, LocalValueJ, NewSubMatrix[i * DimSubQ + j].Y);

			}
		}

	}
	for (int32 i = 0; i < ObjDimQ; i++) {
		int32 FirstIndex = (i / DimSubQ);
		int32 FirstSubIndex = (i % DimSubQ);
		for (int32 j = 0; j < ObjDimQ; j++) {
			int32 SecondIndex = (j / DimSubQ);
			int32 SecondSubIndex = (j % DimSubQ);
			if (FirstIndex == SecondIndex) {
				OperatorGeneralArray[OperationIndex * ObjDimQ * ObjDimQ + i * ObjDimQ + j] = NewSubMatrix[FirstSubIndex * DimSubQ + SecondSubIndex];
			}
			else {
				OperatorGeneralArray[OperationIndex * ObjDimQ * ObjDimQ + i * ObjDimQ + j] = FVector2D(0, 0);
			}
			if (LogOutputFlag) {
				UE_LOG(LogTemp, Warning,
					TEXT("MAIN LOOP: (% d, % d, % d) = FirstIndex=% d FirstSubIndex=% d, SecondIndex=% d SecondSubIndex=% d) = % f"),
					OperationIndex, i, j, FirstIndex, FirstSubIndex,
					SecondIndex, SecondSubIndex, OperatorGeneralArray[OperationIndex * ObjDimQ * ObjDimQ + i * ObjDimQ + j].X);
			}

		}
	}
	if (LogOutputFlag) {
		for (int32 i = 0; i < ObjOperatorCount; i++) {
			for (int32 j = 0; j < ObjDimQ; j++) {
				for (int32 k = 0; k < ObjDimQ; k++) {
					UE_LOG(LogTemp, Warning,
						TEXT("TEST LOOP: (% d, % d, % d) = % f"),
						i, j, k, OperatorGeneralArray[i * ObjDimQ * ObjDimQ + j * ObjDimQ + k].X);
				}
			}
		}
	}
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalInitialize(int32 QubitCountInput, int32 InputOperatorCount) {
	ObjQubitCount = QubitCountInput;
	ObjOperatorCount = InputOperatorCount;
	KetArray.Empty();
	OperatorGeneralArray.Empty();
	OperatorSpecificArray.Empty();
	ObjQubitCount = QubitCountInput;
	ObjDimQ = Localintpow(2, ObjQubitCount);
	KetArray.Init(FVector2D(0, 0), (ObjOperatorCount + 1) * ObjDimQ);
	OperatorGeneralArray.Init(FVector2D(0, 0), ObjOperatorCount * ObjDimQ * ObjDimQ);
	OperatorSpecificArray.Init(FVector2D(0, 0), ObjOperatorCount * ObjDimQ * ObjDimQ);
	KetArray[0] = FVector2D(1, 0);
	//if (OperatorCount != 0) {
	//	OperatorGeneralArray.Init(FVector2D(0, 0), ObjOperatorCount * ObjDimQ * ObjDimQ);
	//	OperatorSpecificArray.Init(FVector2D(0, 0), ObjOperatorCount * ObjDimQ * ObjDimQ);
	//}
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalFxnGetMatrixValues(TArray<FQuantumGateSpecifier_0> InputList) {
	//ObjOperatorCount = InputList.Num();
	//ObjQubitCount = 1;
	//int32 LocalMax = 0;
	//for (int32 i = 0; i < ObjOperatorCount; i++) {
	//	for (int32 j = 0; j < InputList[i].ParameterQubits.Num(); j++) {
	//		if (LocalMax < InputList[i].ParameterQubits[j]) {
	//			LocalMax = InputList[i].ParameterQubits[j];
	//		}
	//	}
	//}
	for (int32 i = 0; i < ObjOperatorCount; i++) {
		LocalParseNameIntArrayToGateOperator(i, InputList[i].GateType, InputList[i].ParameterQubits);
	}
	if(LogOutputFlag){
		for (int32 i = 0; i < ObjOperatorCount; i++) {
			for (int32 j = 0; j < ObjDimQ; j++) {
				for (int32 k = 0; k < ObjDimQ; k++) {
					UE_LOG(LogTemp, Warning,
						TEXT("FINAL LOOP: (% d, % d, % d) = % f"),
						i, j, k, OperatorGeneralArray[i * ObjDimQ * ObjDimQ + j * ObjDimQ + k].X);

				}
			}
		}
	}
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalFxnGetKetTransitions() {
	for (int32 i = 0; i < ObjOperatorCount; i++) {
		for (int32 j = 0; j < ObjDimQ; j++) {
			OperatorSpecificArray[(i + 1) * ObjDimQ + j] = FVector2D(0, 0);
			for (int32 k = 0; k < ObjDimQ; k++) {
				FVector2D TempAFVector2D = LocalComplexMul(OperatorGeneralArray[i * ObjDimQ * ObjDimQ + j * ObjDimQ + k], KetArray[i * ObjDimQ + k]);
				OperatorSpecificArray[i * ObjDimQ * ObjDimQ + j * ObjDimQ + k] = TempAFVector2D;
				FVector2D TempBFVector2D = LocalComplexAdd(KetArray[(i + 1) * ObjDimQ + j], TempAFVector2D);
				KetArray[(i + 1) * ObjDimQ + j] = TempBFVector2D;
			}
		}
	}
	return 0;
}
int32 UQuantumComputingActorComponent_0::LocalFxnSetCircuitState(int32 InputQubitCount, int32 InputOperatorCount, TArray<FQuantumGateSpecifier_0> InputList) {
	//int32 LocalMax = 0;
	//for (int32 i = 0; i < ObjOperatorCount; i++) {
	//	for (int j = 0; j < InputList[i].ParameterQubits.Num(); j++) {
	//		if (LocalMax < InputList[i].ParameterQubits[j]) {
	//			LocalMax = InputList[i].ParameterQubits[j];
	//		}
	//	}
	//}
	//UE_LOG(LogTemp, Warning,
	//	TEXT("FINAL LOOP: (% d, % d, % d) = % f"),
	//	i, j, k, OperatorGeneralArray[i * ObjDimQ * ObjDimQ + j * ObjDimQ + k].X);


	LocalInitialize(InputQubitCount, InputOperatorCount);
	LocalFxnGetMatrixValues(InputList);
	LocalFxnGetKetTransitions();
	return 0;
}
