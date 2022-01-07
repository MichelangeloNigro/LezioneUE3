// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef LEZIONE2_FP_FirstPersonCharacter_generated_h
#error "FP_FirstPersonCharacter.generated.h already included, missing '#pragma once' in FP_FirstPersonCharacter.h"
#endif
#define LEZIONE2_FP_FirstPersonCharacter_generated_h

#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_16_DELEGATE \
static inline void FReloadEvent_DelegateWrapper(const FMulticastScriptDelegate& ReloadEvent) \
{ \
	ReloadEvent.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_15_DELEGATE \
struct _Script_Lezione2_eventPLayerEventTwo_Parms \
{ \
	AActor* HitActor; \
	bool bHit; \
}; \
static inline void FPLayerEventTwo_DelegateWrapper(const FMulticastScriptDelegate& PLayerEventTwo, AActor* HitActor, bool bHit) \
{ \
	_Script_Lezione2_eventPLayerEventTwo_Parms Parms; \
	Parms.HitActor=HitActor; \
	Parms.bHit=bHit ? true : false; \
	PLayerEventTwo.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_SPARSE_DATA
#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStampString);


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStampString);


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_EVENT_PARMS \
	struct FP_FirstPersonCharacter_eventPlayerHasShoot_Parms \
	{ \
		AActor* actor; \
		bool hasHitSomething; \
	};


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_CALLBACK_WRAPPERS
#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFP_FirstPersonCharacter(); \
	friend struct Z_Construct_UClass_AFP_FirstPersonCharacter_Statics; \
public: \
	DECLARE_CLASS(AFP_FirstPersonCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Lezione2"), NO_API) \
	DECLARE_SERIALIZER(AFP_FirstPersonCharacter)


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAFP_FirstPersonCharacter(); \
	friend struct Z_Construct_UClass_AFP_FirstPersonCharacter_Statics; \
public: \
	DECLARE_CLASS(AFP_FirstPersonCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Lezione2"), NO_API) \
	DECLARE_SERIALIZER(AFP_FirstPersonCharacter)


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFP_FirstPersonCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFP_FirstPersonCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFP_FirstPersonCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFP_FirstPersonCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFP_FirstPersonCharacter(AFP_FirstPersonCharacter&&); \
	NO_API AFP_FirstPersonCharacter(const AFP_FirstPersonCharacter&); \
public:


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFP_FirstPersonCharacter(AFP_FirstPersonCharacter&&); \
	NO_API AFP_FirstPersonCharacter(const AFP_FirstPersonCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFP_FirstPersonCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFP_FirstPersonCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFP_FirstPersonCharacter)


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AFP_FirstPersonCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AFP_FirstPersonCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AFP_FirstPersonCharacter, FirstPersonCameraComponent); }


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_18_PROLOG \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_EVENT_PARMS


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_SPARSE_DATA \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_RPC_WRAPPERS \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_CALLBACK_WRAPPERS \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_INCLASS \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_SPARSE_DATA \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_CALLBACK_WRAPPERS \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_INCLASS_NO_PURE_DECLS \
	Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LEZIONE2_API UClass* StaticClass<class AFP_FirstPersonCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Lezione3_Source_Lezione2_FP_FirstPerson_FP_FirstPersonCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
