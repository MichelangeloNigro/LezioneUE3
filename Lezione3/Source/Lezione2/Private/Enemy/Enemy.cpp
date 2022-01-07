// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Lezione2/FP_FirstPerson/FP_FirstPersonCharacter.h"

// Sets default values
AEnemy::AEnemy()
{
 	PrimaryActorTick.bCanEverTick = true;

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

void AEnemy::BeginPlay() {
	Super::BeginPlay();	
}

void AEnemy::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AEnemy::OnConstruction(const FTransform & Transform) {
	WeaponMesh->SetStaticMesh(WeaponSlot.WeaponMesh);
	//GetHealthComponent()->bAutoRecovery = false;
}

//////////////////////////////////////////////////////////////////////////
// Mechanic: Fire with weapon

void AEnemy::FireWithSphereSweep() {

	FCollisionQueryParams Params;
	// Ignore the enemy's pawn
	AActor* Myself = Cast<AActor>(this);
	Params.AddIgnoredActor(Myself);

	float WeaponRange = WeaponSlot.Range;
	float WeaponOffset = WeaponSlot.Offset;
	float WeaponRadius = WeaponSlot.HitRadius;

	FCollisionShape CollShape = FCollisionShape::MakeSphere(WeaponRadius);
	
	FVector ZForward = FVector::UpVector * WeaponOffset;
	FVector Start = GetActorLocation() + ZForward;
	FVector End = Start + (GetActorForwardVector() * WeaponRange);
	FHitResult Hit;

	bool bHit = GetWorld()->SweepSingleByChannel(Hit, Start, End, FQuat::Identity, ECC_Pawn, CollShape, Params);
	OnCharacterTraceLine.Broadcast();

	if (bHit) {
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), WeaponSlot.HitEFX, Hit.ImpactPoint);
		AFP_FirstPersonCharacter* HitPlayer = Cast<AFP_FirstPersonCharacter>(Hit.Actor.Get());

		if (HitPlayer) {
			GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Green, TEXT("Hit! Player"));
			HitPlayer->GetHealthComponent()->AssignDamage(WeaponSlot.Damage);
		} else {
			GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Green, TEXT("Hit! " + Hit.Actor.Get()->GetName()));
		}		
	}
}

//////////////////////////////////////////////////////////////////////////
// Mechanic: Aim

void AEnemy::AimIn() {
	OnCharacterAim.Broadcast();
}

void AEnemy::AimOut() {
	OnCharacterStopAim.Broadcast();
}

//////////////////////////////////////////////////////////////////////////
// Mechanic: Crouch

void AEnemy::CrouchMe() {
	if (CanCrouch()) {
		Crouch();
		OnCharacterCrouch.Broadcast();
	}
}

void AEnemy::UncrouchMe() {
	GEngine->AddOnScreenDebugMessage(-1, 5.2f, FColor::Orange, TEXT("Enemy uncrouch!"));
	UnCrouch();
	OnCharacterUncrouch.Broadcast();
}