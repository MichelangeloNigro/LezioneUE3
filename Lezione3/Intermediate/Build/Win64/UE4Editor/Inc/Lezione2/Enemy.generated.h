// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UHealthComponent;
#ifdef LEZIONE2_Enemy_generated_h
#error "Enemy.generated.h already included, missing '#pragma once' in Enemy.h"
#endif
#define LEZIONE2_Enemy_generated_h

#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_14_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FWeaponSlot_Statics; \
	LEZIONE2_API static class UScriptStruct* StaticStruct();


template<> LEZIONE2_API UScriptStruct* StaticStruct<struct FWeaponSlot>();

#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_48_DELEGATE \
static inline void FGameStateEnemy_DelegateWrapper(const FMulticastScriptDelegate& GameStateEnemy) \
{ \
	GameStateEnemy.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_SPARSE_DATA
#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetHealthComponent); \
	DECLARE_FUNCTION(execAimOut); \
	DECLARE_FUNCTION(execAimIn); \
	DECLARE_FUNCTION(execUncrouchMe); \
	DECLARE_FUNCTION(execCrouchMe); \
	DECLARE_FUNCTION(execFireWithSphereSweep);


#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetHealthComponent); \
	DECLARE_FUNCTION(execAimOut); \
	DECLARE_FUNCTION(execAimIn); \
	DECLARE_FUNCTION(execUncrouchMe); \
	DECLARE_FUNCTION(execCrouchMe); \
	DECLARE_FUNCTION(execFireWithSphereSweep);


#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Lezione2"), NO_API) \
	DECLARE_SERIALIZER(AEnemy)


#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_INCLASS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Lezione2"), NO_API) \
	DECLARE_SERIALIZER(AEnemy)


#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemy(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public:


#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemy)


#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_PRIVATE_PROPERTY_OFFSET
#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_49_PROLOG
#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_PRIVATE_PROPERTY_OFFSET \
	Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_SPARSE_DATA \
	Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_RPC_WRAPPERS \
	Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_INCLASS \
	Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_PRIVATE_PROPERTY_OFFSET \
	Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_SPARSE_DATA \
	Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_RPC_WRAPPERS_NO_PURE_DECLS \
	Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_INCLASS_NO_PURE_DECLS \
	Lezione3_Source_Lezione2_Public_Enemy_Enemy_h_52_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LEZIONE2_API UClass* StaticClass<class AEnemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Lezione3_Source_Lezione2_Public_Enemy_Enemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
