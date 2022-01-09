// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyPath.h"
#include "FP_FirstPerson/HealthComponent.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

USTRUCT(BlueprintType)
struct FWeaponSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh *WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MagCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAutomatic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Rate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HitRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Offset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ShotsPerRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FailureChance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DamageReductionChance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxReductionPossible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* HitEFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* SoundEFX;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameStateEnemy);
UCLASS()
class LEZIONE2_API AEnemy : public ACharacter
{
GENERATED_BODY()

public:
	FTimerHandle UnusedHandle;
	// Sets default values for this character's properties
	AEnemy();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	bool canShot=true;
	bool FinishedRate=false;
	UPROPERTY(VisibleAnywhere, Category="Weapon")
	int CurrentRate=0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float AimOffset = 60.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FWeaponSlot WeaponSlot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path")
	AEnemyPath* PathToPatrol;

protected:
	virtual void BeginPlay() override;
	
	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Damage")
	void FireWithSphereSweep();
	UFUNCTION(BlueprintCallable, Category = "Cover")
	void CrouchMe();

	UFUNCTION(BlueprintCallable, Category = "Cover")
	void UncrouchMe();

	UFUNCTION(BlueprintCallable, Category = "Cover")
	void AimIn();

	UFUNCTION(BlueprintCallable, Category = "Cover")
	void AimOut();
	void SetCanShoot();
	void MeleeAttack();

	/** Broadcasted when character land on ground */
	UPROPERTY(BlueprintAssignable)
	FGameStateEnemy OnCharacterLanding;

	/** Broadcasted when character jump */
	UPROPERTY(BlueprintAssignable)
	FGameStateEnemy OnCharacterJumping;

	/** Broadcasted when character crouching */
	UPROPERTY(BlueprintAssignable)
	FGameStateEnemy OnCharacterCrouch;

	/** Broadcasted when character stop crouching */
	UPROPERTY(BlueprintAssignable)
	FGameStateEnemy OnCharacterUncrouch;

	/** Broadcasted when character start aiming */
	UPROPERTY(BlueprintAssignable)
	FGameStateEnemy OnCharacterAim;

	/** Broadcsted when character stop aiming */
	UPROPERTY(BlueprintAssignable)
	FGameStateEnemy OnCharacterStopAim;

	/** Broadcsted when character reloading the weapon */
	UPROPERTY(BlueprintAssignable)
	FGameStateEnemy OnCharacterStartReload;

	/** Broadcsted when character trace line from weapon */
	UPROPERTY(BlueprintAssignable)
	FGameStateEnemy OnCharacterTraceLine;
	
	UFUNCTION(BlueprintCallable, Category = "Health")
	FORCEINLINE class UHealthComponent* GetHealthComponent() const { return HealthComponent; }
};
