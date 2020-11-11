// Fill out your copyright notice in the Description page of Project Settings.


#include "QuantumComputingActorComponent.h"
int32 UQuantumComputingActorComponent::intpow(int32 base, int32 power) {
	int32 result = 1;
	for (int32 i = 0; i < power; i++) {
		result = result * base;
	}
	return result;
}
FVector2D UQuantumComputingActorComponent::ComplexMul(FVector2D A, FVector2D B) {
	FVector2D ReturnFVector2D;
	ReturnFVector2D.X = A.X * B.X - A.Y * B.Y;
	ReturnFVector2D.Y = A.X * B.Y + A.Y * B.X;
	return ReturnFVector2D;
}
FVector2D UQuantumComputingActorComponent::ComplexAdd(FVector2D A, FVector2D B) {
	FVector2D ReturnFVector2D;
	ReturnFVector2D.X = A.X + B.X;
	ReturnFVector2D.Y = A.Y + B.Y;
	return ReturnFVector2D;
}
FVector2D UQuantumComputingActorComponent::MagPhaseMul(FVector2D A, FVector2D B) {
	FVector2D ReturnFVector2D;
	ReturnFVector2D.X = A.X * B.X - A.Y * B.Y;
	ReturnFVector2D.Y = A.X * B.Y + A.Y * B.X;
	return ReturnFVector2D;
}
FVector2D UQuantumComputingActorComponent::MagPhaseAdd(FVector2D A, FVector2D B) {
	FVector2D ReturnFVector2D;
	ReturnFVector2D.X = A.X + B.X;
	ReturnFVector2D.Y = A.Y + B.Y;
	return ReturnFVector2D;
}
UQuantumComputingActorComponent::UQuantumComputingActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	LogOutputFlag = false;
	// ...
}

// Called when the game starts
void UQuantumComputingActorComponent::BeginPlay()
{
	Super::BeginPlay();
	//ObjMinimumQubitCount = 1;
	//ObjQubitCount = 3;
	ObjQubitCountDefault = 4;
	FixedQubitCountDefaultFlag = false;
	// ...
	
}
// Called every frame
void UQuantumComputingActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
uint32 UQuantumComputingActorComponent::uint32pow(uint32 base, uint32 power) {
	uint32 result = 1;
	for (uint32 i = 0; i < power; i++) {
		result = result * base;
	}
	return result;
}
uint32 UQuantumComputingActorComponent::ToggledBit(uint32 InputNumber, uint32 InputBit) {
	uint32 LongIntUnity = 1;
	uint32 OutputNumber = InputNumber;
	OutputNumber ^= LongIntUnity << InputBit;
	return OutputNumber;
}
uint32 UQuantumComputingActorComponent::CheckBit(uint32 InputNumber, uint32 InputBit) {
	uint32 LongIntUnity = 1;
	return((InputNumber >> InputBit) & LongIntUnity);
}

TArray<bool> UQuantumComputingActorComponent::FxnGetBoolArray(int32 ParamQubitCount, int32 ParamInputInteger) {
	uint32 LongIntUnity = 1;
	uint32 InputInteger = ParamQubitCount;
	uint32 InputQubitCount = ParamInputInteger;
	TArray<bool> OutputBoolArray;
	for (uint32 i = 0; i < InputQubitCount; i++) {
		if (CheckBit(InputInteger, i)) {
			OutputBoolArray.Add(true);
		}
		else {
			OutputBoolArray.Add(false);
		}
	}
	return OutputBoolArray;
}

uint32 UQuantumComputingActorComponent::SwitchBitIf(uint32 InputNumber, uint32 InputControlBit, uint32 InputTargetBit) {
	uint32 LongIntUnity = 1;
	uint32 OutputNumber = InputNumber;
	if ((InputNumber >> InputControlBit) & LongIntUnity) {
		OutputNumber ^= LongIntUnity << InputTargetBit;
	}
	return OutputNumber;
}

int32 UQuantumComputingActorComponent::SingleGateStateTransitionsAdditional(
	int32 ParamInputEnum_SameSplitFlip_012, int32 ParamInputOperation, int32 ParamInputNumber, int32 ParamInputTargetBit,
	FVector2D FVectorMultiplier0, FVector2D FVectorMultiplier1, FVector2D FVectorMultiplier2, FVector2D FVectorMultiplier3) {
	uint32 InputOperation = ParamInputOperation;
	uint32 InputNumber = ParamInputNumber;
	uint32 InputTargetBit = ParamInputTargetBit;
	uint32 LongIntUnity = 1;
	FQuantumTransitionTo LocalTransition;
	uint32 FlippedNumber = (InputNumber ^ (LongIntUnity << InputTargetBit));
	LocalTransition.Enum_012_SameSplitFlip = ParamInputEnum_SameSplitFlip_012;
	if (ParamInputEnum_SameSplitFlip_012 == 0) {
		if (!((InputNumber >> InputTargetBit) & LongIntUnity)) {
			LocalTransition.EndState0 = InputNumber;
			LocalTransition.EndState1 = FlippedNumber;
			LocalTransition.TransitionValue0 = FVectorMultiplier0;
			LocalTransition.TransitionValue1 = FVectorMultiplier0;
		}
		else if (ParamInputEnum_SameSplitFlip_012 == 0) {
			LocalTransition.EndState0 = InputNumber;
			LocalTransition.EndState1 = FlippedNumber;
			LocalTransition.TransitionValue0 = FVectorMultiplier3;
			LocalTransition.TransitionValue1 = FVectorMultiplier3;
		}
	}
	else if (ParamInputEnum_SameSplitFlip_012 == 1) {
		if (!((InputNumber >> InputTargetBit) & LongIntUnity)) {
			LocalTransition.EndState0 = InputNumber;
			LocalTransition.EndState1 = FlippedNumber;
			LocalTransition.TransitionValue0 = FVectorMultiplier0;
			LocalTransition.TransitionValue1 = FVectorMultiplier2;
		}
		else {
			LocalTransition.EndState0 = FlippedNumber;
			LocalTransition.EndState1 = InputNumber;
			LocalTransition.TransitionValue0 = FVectorMultiplier1;
			LocalTransition.TransitionValue1 = FVectorMultiplier3;
		}
	}
	else if (ParamInputEnum_SameSplitFlip_012 == 2) {
		if (!((InputNumber >> InputTargetBit) & LongIntUnity)) {
			LocalTransition.EndState0 = InputNumber;
			LocalTransition.EndState1 = FlippedNumber;
			LocalTransition.TransitionValue0 = FVectorMultiplier2;
			LocalTransition.TransitionValue1 = FVectorMultiplier2;
		}
		else {
			LocalTransition.EndState0 = InputNumber;
			LocalTransition.EndState1 = FlippedNumber;
			LocalTransition.TransitionValue0 = FVectorMultiplier1;
			LocalTransition.TransitionValue1 = FVectorMultiplier1;
		}
	}
	GeneralOperatorMap.Add(FIntPoint(InputOperation, InputNumber), LocalTransition);
	return 0;
}

int32 UQuantumComputingActorComponent::ParseNameIntArrayToGateOperator(int32 QubitCount, int32 InputOperation, TEnumAsByte<EQuantumGateType> InputEnumGateType, TArray<int32> IntArray) {
	uint32 LongIntUnity = 1;
	uint32 LocalDimQ = uint32pow(2, QubitCount);
	if (InputEnumGateType == VE_QuantumGateH && IntArray.Num() == 1) {
		for (uint32 i = 0; i < LocalDimQ; i++) {
			SingleGateStateTransitionsAdditional(1, InputOperation, i, IntArray[0], FVector2D(0.70710678118, 0), FVector2D(0.70710678118, 0), FVector2D(0.70710678118, 0), FVector2D(-0.70710678118, 0));
		}
	}
	else if (InputEnumGateType == VE_QuantumGateX && IntArray.Num() == 1) {
		for (uint32 i = 0; i < LocalDimQ; i++) {
			SingleGateStateTransitionsAdditional(2, InputOperation, i, IntArray[0], FVector2D(0, 0), FVector2D(1, 0), FVector2D(1, 0), FVector2D(0, 0));
		}
	}
	else if (InputEnumGateType == VE_QuantumGateY && IntArray.Num() == 1) {
		for (uint32 i = 0; i < LocalDimQ; i++) {
			SingleGateStateTransitionsAdditional(2, InputOperation, i, IntArray[0], FVector2D(0, 0), FVector2D(0, -1), FVector2D(0, 1), FVector2D(0, 0));
		}
	}
	else if (InputEnumGateType == VE_QuantumGateZ && IntArray.Num() == 1) {
		for (uint32 i = 0; i < LocalDimQ; i++) {
			SingleGateStateTransitionsAdditional(0, InputOperation, i, IntArray[0], FVector2D(1, 0), FVector2D(0, 0), FVector2D(0, 0), FVector2D(-1, 0));
		}
	}
	else if (InputEnumGateType == VE_QuantumGateS && IntArray.Num() == 1) {
		for (uint32 i = 0; i < LocalDimQ; i++) {
			SingleGateStateTransitionsAdditional(0, InputOperation, i, IntArray[0], FVector2D(1, 0), FVector2D(0, 0), FVector2D(0, 0), FVector2D(0, 1));
		}
	}
	else if (InputEnumGateType == VE_QuantumGateT && IntArray.Num() == 1) {
		for (uint32 i = 0; i < LocalDimQ; i++) {
			SingleGateStateTransitionsAdditional(0, InputOperation, i, IntArray[0], FVector2D(1, 0), FVector2D(0, 0), FVector2D(0, 0), FVector2D(0.70710678118, 0.70710678118));
		}
	}
	else if (InputEnumGateType == VE_QuantumGateTDAG && IntArray.Num() == 1) {
		for (uint32 i = 0; i < LocalDimQ; i++) {
			SingleGateStateTransitionsAdditional(0, InputOperation, i, IntArray[0], FVector2D(1, 0), FVector2D(0, 0), FVector2D(0, 0), FVector2D(0.70710678118, -0.70710678118));
		}
	}
	else if (InputEnumGateType == VE_QuantumGateCX && IntArray.Num() == 2) {
		for (uint32 i = 0; i < LocalDimQ; i++) {
			uint32 FlippedNumber = (i ^ (LongIntUnity << IntArray[1]));
			FQuantumTransitionTo LocalTransition;
			LocalTransition.EndState0 = i;
			LocalTransition.EndState1 = FlippedNumber;
			if (!((i >> IntArray[0]) & LongIntUnity)) {
				LocalTransition.Enum_012_SameSplitFlip = 0;
				LocalTransition.TransitionValue0 = FVector2D(1, 0);
				LocalTransition.TransitionValue1 = FVector2D(0, 0);
			}
			else {
				LocalTransition.Enum_012_SameSplitFlip = 2;
				LocalTransition.TransitionValue0 = FVector2D(0, 0);
				LocalTransition.TransitionValue1 = FVector2D(1, 0);
			}
			GeneralOperatorMap.Add(FIntPoint(InputOperation, i), LocalTransition);
			//if (!((i >> IntArray[0]) & LongIntUnity)) {
			//	SingleGateStateTransitionsAdditional(0, InputOperation, i, IntArray[1], FVector2D(1, 0), FVector2D(0, 0), FVector2D(0, 0), FVector2D(0, 1));
			//}
			//else {
			//	SingleGateStateTransitionsAdditional(2, InputOperation, i, IntArray[1], FVector2D(0, 0), FVector2D(1, 0), FVector2D(1, 0), FVector2D(0, 0));
			//}
		}
	}
	else {
		for (uint32 i = 0; i < LocalDimQ; i++) {
			SingleGateStateTransitionsAdditional(0, InputOperation, i, IntArray[0], FVector2D(1, 0), FVector2D(0, 0), FVector2D(0, 0), FVector2D(1, 0));
		}
	}
	return 0;

}
int32 UQuantumComputingActorComponent::FxnAddKetState(FIntPoint InputFIP, FVector2D InputFV2D) {
	if (SpecificStateMap.Contains(InputFIP)) {
		FVector2D TempFV2D = ComplexAdd(InputFV2D, SpecificStateMap[InputFIP]);
		SpecificStateMap[InputFIP] = TempFV2D;
	}
	else {
		SpecificStateMap.Add(InputFIP, InputFV2D);
	}
	if (SpecificStateMap[InputFIP].SizeSquared() < ObjFloatThreshold) {
		SpecificStateMap.Remove(InputFIP);
	}
	return 0;
}
int32 UQuantumComputingActorComponent::FxnSetCircuitDescription(TMap<int32, FVector2D> InputKet, TArray<FQuantumGateSpecifier> InputList) {
	ObjQubitCount = 4;
	//ObjQubitCount = ObjQubitCountDefault;
	int32 LocalMax = ObjMinimumQubitCount;
	for (auto& iter0 : InputList) {
		for (auto& iter1 : iter0.ParameterQubits) {
			if (iter1 > LocalMax) {
				LocalMax = iter1;
			}
		}
	}
	if (InputList.Num() > ObjMaximumOperatorCount) {
		return 1;
	}
	else if ((LocalMax + 1) > ObjMaximumQubitCount) {
		return 2;
	}
	else if (FixedQubitCountDefaultFlag && (LocalMax + 1) > ObjQubitCountDefault) {
		ObjQubitCount = ObjQubitCountDefault;
		return 3;
	}
	else {
		if (FixedQubitCountDefaultFlag) {
			ObjQubitCount = ObjQubitCountDefault;
		}
		else {
			ObjQubitCount = LocalMax + 1;
		}
		ObjOperatorCount = InputList.Num();
		ObjDimQ = intpow(2, ObjQubitCount);
		float TempFloat = (float)(1.0 / ObjDimQ);
		ObjFloatThreshold = 0.001 * TempFloat;
		//TMap<int32, FVector2D> LocalStartKet;
		//for (int32 i = 0; i < ObjDimQ; i++) {
		//	if (SpecificStateMap.Contains(FIntPoint(-1, i))) {
		//		LocalStartKet.Add(i, SpecificStateMap[FIntPoint(-1, i)]);
		//	}
		//}
		SpecificStateMap.Empty();
		GeneralOperatorMap.Empty();
		SpecificOperatorMap.Empty();
		//for (int32 i = 0; i < ObjDimQ; i++) {
		//	if (LocalStartKet.Contains(i)) {
		//		SpecificStateMap.Add(FIntPoint(-1, i), LocalStartKet[i]);
		//	}
		//}
		for (auto& iter : InputKet) {
			SpecificStateMap.Add(FIntPoint(-1, iter.Key), iter.Value);
		}
		//if (ObjStartStateIndex > 0 && ObjStartStateIndex < ObjDimQ) {
		//	SpecificStateMap.Add(FIntPoint(-1, ObjStartStateIndex), FVector2D(1, 0));
		//}
		//else {
		//	SpecificStateMap.Add(FIntPoint(-1, 0), FVector2D(1, 0));
		//}
		for (int32 i = 0; i < ObjOperatorCount; i++) {
			ParseNameIntArrayToGateOperator(ObjQubitCount, i, InputList[i].EnumGateType, InputList[i].ParameterQubits);
		}
		for (int32 i = 0; i < ObjOperatorCount; i++) {
			for (int32 j = 0; j < ObjDimQ; j++) {
				FIntPoint CurrentFIP = FIntPoint(i, j);
				FIntPoint PreviousStateFIP = FIntPoint(i - 1, j);
				if (SpecificStateMap.Contains(PreviousStateFIP) &&
					GeneralOperatorMap.Contains(CurrentFIP)) {
					FQuantumTransitionTo LocalFQTT;
					GeneralOperatorMap[CurrentFIP];
					if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 0) {
						LocalFQTT.Enum_012_SameSplitFlip = 0;
						LocalFQTT.EndState0 = GeneralOperatorMap[CurrentFIP].EndState0;
						LocalFQTT.TransitionValue0 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue0);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState0), LocalFQTT.TransitionValue0);
					}
					else if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 1) {
						LocalFQTT.Enum_012_SameSplitFlip = 1;
						LocalFQTT.EndState0 = GeneralOperatorMap[CurrentFIP].EndState0;
						LocalFQTT.TransitionValue0 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue0);
						LocalFQTT.EndState1 = GeneralOperatorMap[CurrentFIP].EndState1;
						LocalFQTT.TransitionValue1 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue1);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState0), LocalFQTT.TransitionValue0);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState1), LocalFQTT.TransitionValue1);
					}
					else if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 2) {
						LocalFQTT.Enum_012_SameSplitFlip = 2;
						LocalFQTT.EndState1 = GeneralOperatorMap[CurrentFIP].EndState1;
						LocalFQTT.TransitionValue1 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue1);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState1), LocalFQTT.TransitionValue1);
					}
					SpecificOperatorMap.Add(CurrentFIP, LocalFQTT);
				}
			}
		}
		//TArray<FIntPoint> KeySet;
		//SpecificStateMap.GenerateKeyArray(KeySet);
		//for (auto& iter: KeySet) {
		//	float LocalSize = SpecificStateMap[iter].SizeSquared();
		//	float LocalCompare = ObjFloatThreshold;
		//	if (SpecificStateMap[iter].SizeSquared() < ((1 / ObjDimQ) * 0.001)) {
		//		SpecificStateMap.Remove(iter);
		//	}
		//	if (LocalSize < LocalCompare) {
		//		SpecificStateMap.Remove(iter);
		//	}
		//}
		return 0;
	}
}
int32 UQuantumComputingActorComponent::FxnSetCircuitDescriptionSpecified(int32 QubitCountInput, TMap<int32, FVector2D> InputKet, TArray<FQuantumGateSpecifier> InputList) {
	ObjQubitCount = QubitCountInput;
	//ObjQubitCount = ObjQubitCountDefault;
	int32 LocalMax = 0;
	for (auto& iter0 : InputList) {
		for (auto& iter1 : iter0.ParameterQubits) {
			if (iter1 > LocalMax) {
				LocalMax = iter1;
			}
		}
	}
	if (InputList.Num() > ObjMaximumOperatorCount) {
		return 1;
	}
	else if ((LocalMax + 1) > ObjQubitCount) {
		return 2;
	}
	else {
		ObjOperatorCount = InputList.Num();
		ObjDimQ = intpow(2, ObjQubitCount);
		float TempFloat = (float)(1.0 / ObjDimQ);
		ObjFloatThreshold = 0.001 * TempFloat;
		//TMap<int32, FVector2D> LocalStartKet;
		//for (int32 i = 0; i < ObjDimQ; i++) {
		//	if (SpecificStateMap.Contains(FIntPoint(-1, i))) {
		//		LocalStartKet.Add(i, SpecificStateMap[FIntPoint(-1, i)]);
		//	}
		//}
		SpecificStateMap.Empty();
		GeneralOperatorMap.Empty();
		SpecificOperatorMap.Empty();
		//for (int32 i = 0; i < ObjDimQ; i++) {
		//	if (LocalStartKet.Contains(i)) {
		//		SpecificStateMap.Add(FIntPoint(-1, i), LocalStartKet[i]);
		//	}
		//}
		for (auto& iter : InputKet) {
			SpecificStateMap.Add(FIntPoint(-1, iter.Key), iter.Value);
		}
		//if (ObjStartStateIndex > 0 && ObjStartStateIndex < ObjDimQ) {
		//	SpecificStateMap.Add(FIntPoint(-1, ObjStartStateIndex), FVector2D(1, 0));
		//}
		//else {
		//	SpecificStateMap.Add(FIntPoint(-1, 0), FVector2D(1, 0));
		//}
		for (int32 i = 0; i < ObjOperatorCount; i++) {
			ParseNameIntArrayToGateOperator(ObjQubitCount, i, InputList[i].EnumGateType, InputList[i].ParameterQubits);
		}
		for (int32 i = 0; i < ObjOperatorCount; i++) {
			for (int32 j = 0; j < ObjDimQ; j++) {
				FIntPoint CurrentFIP = FIntPoint(i, j);
				FIntPoint PreviousStateFIP = FIntPoint(i - 1, j);
				if (SpecificStateMap.Contains(PreviousStateFIP) &&
					GeneralOperatorMap.Contains(CurrentFIP)) {
					FQuantumTransitionTo LocalFQTT;
					GeneralOperatorMap[CurrentFIP];
					if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 0) {
						LocalFQTT.Enum_012_SameSplitFlip = 0;
						LocalFQTT.EndState0 = GeneralOperatorMap[CurrentFIP].EndState0;
						LocalFQTT.TransitionValue0 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue0);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState0), LocalFQTT.TransitionValue0);
					}
					else if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 1) {
						LocalFQTT.Enum_012_SameSplitFlip = 1;
						LocalFQTT.EndState0 = GeneralOperatorMap[CurrentFIP].EndState0;
						LocalFQTT.TransitionValue0 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue0);
						LocalFQTT.EndState1 = GeneralOperatorMap[CurrentFIP].EndState1;
						LocalFQTT.TransitionValue1 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue1);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState0), LocalFQTT.TransitionValue0);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState1), LocalFQTT.TransitionValue1);
					}
					else if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 2) {
						LocalFQTT.Enum_012_SameSplitFlip = 2;
						LocalFQTT.EndState1 = GeneralOperatorMap[CurrentFIP].EndState1;
						LocalFQTT.TransitionValue1 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue1);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState1), LocalFQTT.TransitionValue1);
					}
					SpecificOperatorMap.Add(CurrentFIP, LocalFQTT);
				}
			}
		}
		//TArray<FIntPoint> KeySet;
		//SpecificStateMap.GenerateKeyArray(KeySet);
		//for (auto& iter: KeySet) {
		//	float LocalSize = SpecificStateMap[iter].SizeSquared();
		//	float LocalCompare = ObjFloatThreshold;
		//	if (SpecificStateMap[iter].SizeSquared() < ((1 / ObjDimQ) * 0.001)) {
		//		SpecificStateMap.Remove(iter);
		//	}
		//	if (LocalSize < LocalCompare) {
		//		SpecificStateMap.Remove(iter);
		//	}
		//}
		return 0;
	}
}
int32 UQuantumComputingActorComponent::FxnSetGeneralCircuit(int32 QubitCountInput, TMap<int32, FVector2D> InputKet, TArray<FQuantumGateSpecifier> InputList) {
	ObjQubitCount = QubitCountInput;
	//ObjQubitCount = ObjQubitCountDefault;
	int32 LocalMax = 0;
	for (auto& iter0 : InputList) {
		for (auto& iter1 : iter0.ParameterQubits) {
			if (iter1 > LocalMax) {
				LocalMax = iter1;
			}
		}
	}
	if (InputList.Num() > ObjMaximumOperatorCount) {
		return 1;
	}
	else if ((LocalMax + 1) > ObjQubitCount) {
		return 2;
	}
	else {
		ObjOperatorCount = InputList.Num();
		ObjDimQ = intpow(2, ObjQubitCount);
		float TempFloat = (float)(1.0 / ObjDimQ);
		ObjFloatThreshold = 0.001 * TempFloat;
		//TMap<int32, FVector2D> LocalStartKet;
		//for (int32 i = 0; i < ObjDimQ; i++) {
		//	if (SpecificStateMap.Contains(FIntPoint(-1, i))) {
		//		LocalStartKet.Add(i, SpecificStateMap[FIntPoint(-1, i)]);
		//	}
		//}
		SpecificStateMap.Empty();
		GeneralOperatorMap.Empty();
		SpecificOperatorMap.Empty();
		//for (int32 i = 0; i < ObjDimQ; i++) {
		//	if (LocalStartKet.Contains(i)) {
		//		SpecificStateMap.Add(FIntPoint(-1, i), LocalStartKet[i]);
		//	}
		//}
		for (auto& iter : InputKet) {
			SpecificStateMap.Add(FIntPoint(-1, iter.Key), iter.Value);
		}
		//if (ObjStartStateIndex > 0 && ObjStartStateIndex < ObjDimQ) {
		//	SpecificStateMap.Add(FIntPoint(-1, ObjStartStateIndex), FVector2D(1, 0));
		//}
		//else {
		//	SpecificStateMap.Add(FIntPoint(-1, 0), FVector2D(1, 0));
		//}
		for (int32 i = 0; i < ObjOperatorCount; i++) {
			ParseNameIntArrayToGateOperator(ObjQubitCount, i, InputList[i].EnumGateType, InputList[i].ParameterQubits);
		}
		for (int32 i = 0; i < ObjOperatorCount; i++) {
			for (int32 j = 0; j < ObjDimQ; j++) {
				FIntPoint CurrentFIP = FIntPoint(i, j);
				FIntPoint PreviousStateFIP = FIntPoint(i - 1, j);
				if (SpecificStateMap.Contains(PreviousStateFIP) &&
					GeneralOperatorMap.Contains(CurrentFIP)) {
					FQuantumTransitionTo LocalFQTT;
					GeneralOperatorMap[CurrentFIP];
					if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 0) {
						LocalFQTT.Enum_012_SameSplitFlip = 0;
						LocalFQTT.EndState0 = GeneralOperatorMap[CurrentFIP].EndState0;
						LocalFQTT.TransitionValue0 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue0);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState0), LocalFQTT.TransitionValue0);
					}
					else if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 1) {
						LocalFQTT.Enum_012_SameSplitFlip = 1;
						LocalFQTT.EndState0 = GeneralOperatorMap[CurrentFIP].EndState0;
						LocalFQTT.TransitionValue0 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue0);
						LocalFQTT.EndState1 = GeneralOperatorMap[CurrentFIP].EndState1;
						LocalFQTT.TransitionValue1 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue1);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState0), LocalFQTT.TransitionValue0);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState1), LocalFQTT.TransitionValue1);
					}
					else if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 2) {
						LocalFQTT.Enum_012_SameSplitFlip = 2;
						LocalFQTT.EndState1 = GeneralOperatorMap[CurrentFIP].EndState1;
						LocalFQTT.TransitionValue1 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue1);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState1), LocalFQTT.TransitionValue1);
					}
					SpecificOperatorMap.Add(CurrentFIP, LocalFQTT);
				}
			}
		}
		//TArray<FIntPoint> KeySet;
		//SpecificStateMap.GenerateKeyArray(KeySet);
		//for (auto& iter: KeySet) {
		//	float LocalSize = SpecificStateMap[iter].SizeSquared();
		//	float LocalCompare = ObjFloatThreshold;
		//	if (SpecificStateMap[iter].SizeSquared() < ((1 / ObjDimQ) * 0.001)) {
		//		SpecificStateMap.Remove(iter);
		//	}
		//	if (LocalSize < LocalCompare) {
		//		SpecificStateMap.Remove(iter);
		//	}
		//}
		return 0;
	}
}
int32 UQuantumComputingActorComponent::FxnGetSpecificCircuit(TMap<int32, FVector2D> InputKet) {
		ObjOperatorCount = InputList.Num();
		ObjDimQ = intpow(2, ObjQubitCount);
		float TempFloat = (float)(1.0 / ObjDimQ);
		ObjFloatThreshold = 0.001 * TempFloat;
		//TMap<int32, FVector2D> LocalStartKet;
		//for (int32 i = 0; i < ObjDimQ; i++) {
		//	if (SpecificStateMap.Contains(FIntPoint(-1, i))) {
		//		LocalStartKet.Add(i, SpecificStateMap[FIntPoint(-1, i)]);
		//	}
		//}
		LocalStateMap.Empty();4
		LocalOperatorMap.Empty();
		for (auto& iter : InputKet) {
			LocalStateMap.Add(FIntPoint(-1, iter.Key), iter.Value);
		}
		//if (ObjStartStateIndex > 0 && ObjStartStateIndex < ObjDimQ) {
		//	SpecificStateMap.Add(FIntPoint(-1, ObjStartStateIndex), FVector2D(1, 0));
		//}
		//else {
		//	SpecificStateMap.Add(FIntPoint(-1, 0), FVector2D(1, 0));
		//}
		TMap<FIntPoint, FQuantumTransitionTo> LocalOperatorMap;
		for (int32 i = 0; i < ObjOperatorCount; i++) {
			for (int32 j = 0; j < ObjDimQ; j++) {
				FIntPoint CurrentFIP = FIntPoint(i, j);
				FIntPoint PreviousStateFIP = FIntPoint(i - 1, j);
				if (SpecificStateMap.Contains(PreviousStateFIP) &&
					GeneralOperatorMap.Contains(CurrentFIP)) {
					FQuantumTransitionTo LocalFQTT;
					GeneralOperatorMap[CurrentFIP];
					if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 0) {
						LocalFQTT.Enum_012_SameSplitFlip = 0;
						LocalFQTT.EndState0 = GeneralOperatorMap[CurrentFIP].EndState0;
						LocalFQTT.TransitionValue0 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue0);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState0), LocalFQTT.TransitionValue0);
					}
					else if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 1) {
						LocalFQTT.Enum_012_SameSplitFlip = 1;
						LocalFQTT.EndState0 = GeneralOperatorMap[CurrentFIP].EndState0;
						LocalFQTT.TransitionValue0 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue0);
						LocalFQTT.EndState1 = GeneralOperatorMap[CurrentFIP].EndState1;
						LocalFQTT.TransitionValue1 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue1);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState0), LocalFQTT.TransitionValue0);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState1), LocalFQTT.TransitionValue1);
					}
					else if (GeneralOperatorMap[CurrentFIP].Enum_012_SameSplitFlip == 2) {
						LocalFQTT.Enum_012_SameSplitFlip = 2;
						LocalFQTT.EndState1 = GeneralOperatorMap[CurrentFIP].EndState1;
						LocalFQTT.TransitionValue1 = ComplexMul(
							SpecificStateMap[PreviousStateFIP],
							GeneralOperatorMap[CurrentFIP].TransitionValue1);
						FxnAddKetState(FIntPoint(CurrentFIP.X, LocalFQTT.EndState1), LocalFQTT.TransitionValue1);
					}
					LocalOperatorMap.Add(CurrentFIP, LocalFQTT);
				}
			}
		}
		//TArray<FIntPoint> KeySet;
		//SpecificStateMap.GenerateKeyArray(KeySet);
		//for (auto& iter: KeySet) {
		//	float LocalSize = SpecificStateMap[iter].SizeSquared();
		//	float LocalCompare = ObjFloatThreshold;
		//	if (SpecificStateMap[iter].SizeSquared() < ((1 / ObjDimQ) * 0.001)) {
		//		SpecificStateMap.Remove(iter);
		//	}
		//	if (LocalSize < LocalCompare) {
		//		SpecificStateMap.Remove(iter);
		//	}
		//}
		return LocalOperatorMap;
}
