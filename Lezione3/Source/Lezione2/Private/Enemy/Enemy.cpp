// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Lezione2/FP_FirstPerson/FP_FirstPersonCharacter.h"

// Sets default values
AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("UBoxComponent"));
	// Set character movement 
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	GetCharacterMovement()->CrouchedHalfHeight = 52.0f;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 0.0f, 250.0f);

	// Add a mesh for the weapon
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, "hand_rSocket");

	// Add Health manager
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

//////////////////////////////////////////////////////////////////////////
// UE4 functions for game thread

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetOverlappingActors(ActorsInside,SensedClass);
}

void AEnemy::OnConstruction(const FTransform& Transform)
{
	WeaponMesh->SetStaticMesh(WeaponSlot.WeaponMesh);
	//GetHealthComponent()->bAutoRecovery = false;
}

//////////////////////////////////////////////////////////////////////////
// Mechanic: Fire with weapon

void AEnemy::FireWithSphereSweep()
{
	if (canShot)
	{
		FCollisionQueryParams Params;
		// Ignore the enemy's pawn
		AActor* Myself = Cast<AActor>(this);
		Params.AddIgnoredActor(Myself);

		float WeaponRange = WeaponSlot.Range;
		float WeaponOffset = WeaponSlot.Offset;
		float WeaponRadius = WeaponSlot.HitRadius;
		float damage = WeaponSlot.Damage;
		int temp2;
		temp2 = FMath::RandRange(0, 100);
		if (temp2 < WeaponSlot.DamageReductionChance)
		{
			int temp3;
			temp3 = FMath::RandRange(1, WeaponSlot.MaxReductionPossible);
			damage -= temp3;
		}

		FCollisionShape CollShape = FCollisionShape::MakeSphere(WeaponRadius);

		FVector ZForward = FVector::UpVector * WeaponOffset;
		FVector Start = GetActorLocation() + ZForward;
		FVector End = Start + (GetActorForwardVector() * WeaponRange);
		FHitResult Hit;

		bool bHit = GetWorld()->SweepSingleByChannel(Hit, Start, End, FQuat::Identity, ECC_Pawn, CollShape, Params);
		OnCharacterTraceLine.Broadcast();
		int temp;
		temp = FMath::RandRange(0, 100);
		if (temp < WeaponSlot.FailureChance)
		{
			bHit = false;
		}

		if (bHit)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), WeaponSlot.HitEFX, Hit.ImpactPoint);
			AFP_FirstPersonCharacter* HitPlayer = Cast<AFP_FirstPersonCharacter>(Hit.Actor.Get());
			if (WeaponSlot.SoundEFX != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, WeaponSlot.SoundEFX, GetActorLocation());
			}
			if (WeaponSlot.HitEFX != nullptr)
			{
				UGameplayStatics::SpawnEmitterAtLocation(this, WeaponSlot.HitEFX,
				                                         Hit.Actor->GetTransform().GetLocation());
			}

			if (HitPlayer)
			{
				GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Green, TEXT("Hit! with gun"));
				HitPlayer->GetHealthComponent()->AssignDamage(damage);
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Green, TEXT("Hit! " + Hit.Actor.Get()->GetName()));
			}
		}
		if (WeaponSlot.IsAutomatic)
		{
			CurrentRate++;
			if (CurrentRate >= WeaponSlot.ShotsPerRate)
			{
				canShot = false;
				GetWorldTimerManager().SetTimer(UnusedHandle, this, &AEnemy::SetCanShoot, WeaponSlot.Rate, false);
			}
		}
		if (!WeaponSlot.IsAutomatic)
		{
			canShot = false;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &AEnemy::SetCanShoot, WeaponSlot.Rate, false);
		}
	}
}

void AEnemy::SetCanShoot()
{
	canShot = true;
	CurrentRate = 0;
}


//////////////////////////////////////////////////////////////////////////
// Mechanic: Aim

void AEnemy::AimIn()
{
	OnCharacterAim.Broadcast();
}

void AEnemy::AimOut()
{
	OnCharacterStopAim.Broadcast();
}

//////////////////////////////////////////////////////////////////////////
// Mechanic: Crouch

void AEnemy::CrouchMe()
{
	if (CanCrouch())
	{
		Crouch();
		OnCharacterCrouch.Broadcast();
	}
}

void AEnemy::UncrouchMe()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.2f, FColor::Orange, TEXT("Enemy uncrouch!"));
	UnCrouch();
	OnCharacterUncrouch.Broadcast();
}

bool AEnemy::MeleeAttack()
{
	//AFP_FirstPersonCharacter* HitPlayer = Cast<AFP_FirstPersonCharacter>(.Actor.Get());
	if (ActorsInside.IsValidIndex(0))
	{
		
	
		if (WeaponSlot.SoundEFX != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, WeaponSlot.SoundEFX, GetActorLocation());
		}
		if (WeaponSlot.HitEFX != nullptr)
		{
			UGameplayStatics::SpawnEmitterAtLocation(this, WeaponSlot.HitEFX, ActorsInside[0]->GetTransform().GetLocation());
		}
		GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Green, TEXT("Melee"));
		Cast<AFP_FirstPersonCharacter>(ActorsInside[0])->GetHealthComponent()->AssignDamage(WeaponSlot.Damage);
		return true;
	}
	return false;
}


//TODO funzione per fare melee
