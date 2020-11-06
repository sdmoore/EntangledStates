//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "Engine/UserDefinedStruct.h"
//#include "QuantumGateSpecifierStruct.generated.h"
//
///**
// * 
// */
//UCLASS()
//class ENTANGLEDSTATES_API UQuantumGateSpecifierStruct : public UUserDefinedStruct
//{
//	GENERATED_BODY()
//	
//};
//// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "QuantumGateSpecifierStruct.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, meta = (BlueprintSpawnableComponent))
class ENTANGLEDSTATES_API UQuantumGateSpecifierStruct : public UUserDefinedStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FString GateType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) TArray<int32> ParameterQubits;
};
