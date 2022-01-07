// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Lezione2/Public/Enemy/EnemyPath.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyPath() {}
// Cross Module References
	LEZIONE2_API UClass* Z_Construct_UClass_AEnemyPath_NoRegister();
	LEZIONE2_API UClass* Z_Construct_UClass_AEnemyPath();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Lezione2();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(AEnemyPath::execActualPoint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->ActualPoint();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AEnemyPath::execGoNextNode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GoNextNode();
		P_NATIVE_END;
	}
	void AEnemyPath::StaticRegisterNativesAEnemyPath()
	{
		UClass* Class = AEnemyPath::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ActualPoint", &AEnemyPath::execActualPoint },
			{ "GoNextNode", &AEnemyPath::execGoNextNode },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics
	{
		struct EnemyPath_eventActualPoint_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EnemyPath_eventActualPoint_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics::Function_MetaDataParams[] = {
		{ "Category", "AI Path" },
		{ "Comment", "/** Retrieve actual point */" },
		{ "ModuleRelativePath", "Public/Enemy/EnemyPath.h" },
		{ "ToolTip", "Retrieve actual point" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyPath, nullptr, "ActualPoint", nullptr, nullptr, sizeof(EnemyPath_eventActualPoint_Parms), Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyPath_ActualPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyPath_ActualPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEnemyPath_GoNextNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyPath_GoNextNode_Statics::Function_MetaDataParams[] = {
		{ "Category", "AI Path" },
		{ "Comment", "/** Set the index to next node */" },
		{ "ModuleRelativePath", "Public/Enemy/EnemyPath.h" },
		{ "ToolTip", "Set the index to next node" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyPath_GoNextNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyPath, nullptr, "GoNextNode", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyPath_GoNextNode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyPath_GoNextNode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyPath_GoNextNode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyPath_GoNextNode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AEnemyPath_NoRegister()
	{
		return AEnemyPath::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyPath_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PathPoints_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathPoints_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PathPoints;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyPath_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Lezione2,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AEnemyPath_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemyPath_ActualPoint, "ActualPoint" }, // 3771607742
		{ &Z_Construct_UFunction_AEnemyPath_GoNextNode, "GoNextNode" }, // 386694062
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyPath_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Enemy/EnemyPath.h" },
		{ "ModuleRelativePath", "Public/Enemy/EnemyPath.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemyPath_Statics::NewProp_PathPoints_Inner = { "PathPoints", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyPath_Statics::NewProp_PathPoints_MetaData[] = {
		{ "Category", "Path Points" },
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "Public/Enemy/EnemyPath.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AEnemyPath_Statics::NewProp_PathPoints = { "PathPoints", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyPath, PathPoints), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AEnemyPath_Statics::NewProp_PathPoints_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyPath_Statics::NewProp_PathPoints_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemyPath_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyPath_Statics::NewProp_PathPoints_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyPath_Statics::NewProp_PathPoints,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyPath_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyPath>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyPath_Statics::ClassParams = {
		&AEnemyPath::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AEnemyPath_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyPath_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemyPath_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyPath_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyPath()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyPath_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyPath, 2314008466);
	template<> LEZIONE2_API UClass* StaticClass<AEnemyPath>()
	{
		return AEnemyPath::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyPath(Z_Construct_UClass_AEnemyPath, &AEnemyPath::StaticClass, TEXT("/Script/Lezione2"), TEXT("AEnemyPath"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyPath);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
