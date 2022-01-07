// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Lezione2/Public/FP_FirstPerson/Pickable.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePickable() {}
// Cross Module References
	LEZIONE2_API UClass* Z_Construct_UClass_APickable_NoRegister();
	LEZIONE2_API UClass* Z_Construct_UClass_APickable();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Lezione2();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(APickable::execOnTriggerEnter)
	{
		P_GET_OBJECT(AActor,Z_Param_overlappedActor);
		P_GET_OBJECT(AActor,Z_Param_overlappingActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnTriggerEnter(Z_Param_overlappedActor,Z_Param_overlappingActor);
		P_NATIVE_END;
	}
	void APickable::StaticRegisterNativesAPickable()
	{
		UClass* Class = APickable::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnTriggerEnter", &APickable::execOnTriggerEnter },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APickable_OnTriggerEnter_Statics
	{
		struct Pickable_eventOnTriggerEnter_Parms
		{
			AActor* overlappedActor;
			AActor* overlappingActor;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_overlappedActor;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_overlappingActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::NewProp_overlappedActor = { "overlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Pickable_eventOnTriggerEnter_Parms, overlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::NewProp_overlappingActor = { "overlappingActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Pickable_eventOnTriggerEnter_Parms, overlappingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::NewProp_overlappedActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::NewProp_overlappingActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FP_FirstPerson/Pickable.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APickable, nullptr, "OnTriggerEnter", nullptr, nullptr, sizeof(Pickable_eventOnTriggerEnter_Parms), Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APickable_OnTriggerEnter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APickable_OnTriggerEnter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APickable_NoRegister()
	{
		return APickable::StaticClass();
	}
	struct Z_Construct_UClass_APickable_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoxComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BoxComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_damage_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_damage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APickable_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Lezione2,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_APickable_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APickable_OnTriggerEnter, "OnTriggerEnter" }, // 1210090935
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickable_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FP_FirstPerson/Pickable.h" },
		{ "ModuleRelativePath", "Public/FP_FirstPerson/Pickable.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickable_Statics::NewProp_BoxComponent_MetaData[] = {
		{ "Category", "Pickable" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/FP_FirstPerson/Pickable.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APickable_Statics::NewProp_BoxComponent = { "BoxComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APickable, BoxComponent), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APickable_Statics::NewProp_BoxComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APickable_Statics::NewProp_BoxComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickable_Statics::NewProp_damage_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "Public/FP_FirstPerson/Pickable.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APickable_Statics::NewProp_damage = { "damage", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APickable, damage), METADATA_PARAMS(Z_Construct_UClass_APickable_Statics::NewProp_damage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APickable_Statics::NewProp_damage_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APickable_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickable_Statics::NewProp_BoxComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickable_Statics::NewProp_damage,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APickable_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APickable>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APickable_Statics::ClassParams = {
		&APickable::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APickable_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APickable_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APickable_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APickable_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APickable()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APickable_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APickable, 3456207928);
	template<> LEZIONE2_API UClass* StaticClass<APickable>()
	{
		return APickable::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APickable(Z_Construct_UClass_APickable, &APickable::StaticClass, TEXT("/Script/Lezione2"), TEXT("APickable"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APickable);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
