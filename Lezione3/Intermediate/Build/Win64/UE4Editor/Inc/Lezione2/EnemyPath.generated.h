// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
#ifdef LEZIONE2_EnemyPath_generated_h
#error "EnemyPath.generated.h already included, missing '#pragma once' in EnemyPath.h"
#endif
#define LEZIONE2_EnemyPath_generated_h

#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_SPARSE_DATA
#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execActualPoint); \
	DECLARE_FUNCTION(execGoNextNode);


#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execActualPoint); \
	DECLARE_FUNCTION(execGoNextNode);


#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemyPath(); \
	friend struct Z_Construct_UClass_AEnemyPath_Statics; \
public: \
	DECLARE_CLASS(AEnemyPath, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Lezione2"), NO_API) \
	DECLARE_SERIALIZER(AEnemyPath)


#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAEnemyPath(); \
	friend struct Z_Construct_UClass_AEnemyPath_Statics; \
public: \
	DECLARE_CLASS(AEnemyPath, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Lezione2"), NO_API) \
	DECLARE_SERIALIZER(AEnemyPath)


#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemyPath(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemyPath) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyPath); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyPath); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyPath(AEnemyPath&&); \
	NO_API AEnemyPath(const AEnemyPath&); \
public:


#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemyPath(AEnemyPath&&); \
	NO_API AEnemyPath(const AEnemyPath&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyPath); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyPath); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemyPath)


#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_PRIVATE_PROPERTY_OFFSET
#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_9_PROLOG
#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_PRIVATE_PROPERTY_OFFSET \
	Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_SPARSE_DATA \
	Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_RPC_WRAPPERS \
	Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_INCLASS \
	Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_PRIVATE_PROPERTY_OFFSET \
	Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_SPARSE_DATA \
	Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_INCLASS_NO_PURE_DECLS \
	Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LEZIONE2_API UClass* StaticClass<class AEnemyPath>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Lezione3_Source_Lezione2_Public_Enemy_EnemyPath_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
