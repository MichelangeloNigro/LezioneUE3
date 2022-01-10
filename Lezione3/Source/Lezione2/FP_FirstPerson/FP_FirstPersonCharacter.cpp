// Copyright Epic Games, Inc. All Rights Reserved.

#include "FP_FirstPersonCharacter.h"
#include "Animation/AnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "FP_FirstPerson/HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

#define COLLISION_WEAPON		ECC_GameTraceChannel1

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

void AFP_FirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	setWeapon(WeaponSlot);
	if (IsValid(HealthComponent))
	{
		HealthComponent->OnTakeDamage.AddDynamic(this, &AFP_FirstPersonCharacter::StampString);
	}
}

void AFP_FirstPersonCharacter::StampString()
{
	//not raised??
	GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Red,"Che Male, vita rimanente " + FString::FromInt(HealthComponent->currentLife));
}

//////////////////////////////////////////////////////////////////////////
// AFP_FirstPersonCharacter

AFP_FirstPersonCharacter::AFP_FirstPersonCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));

	// Set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(0, 0, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true); // Set so only owner can see mesh
	Mesh1P->SetupAttachment(FirstPersonCameraComponent); // Attach mesh to FirstPersonCameraComponent
	Mesh1P->bCastDynamicShadow = false; // Disallow mesh to cast dynamic shadows
	Mesh1P->CastShadow = false; // Disallow mesh to cast other shadows

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true); // Only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false; // Disallow mesh to cast dynamic shadows
	FP_Gun->CastShadow = false; // Disallow mesh to cast other shadows
	FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));

	// Set weapon damage and range
	
	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 30.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AFP_FirstPersonCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Set up gameplay key bindings

	// Bind jump events
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AFP_FirstPersonCharacter::reloadTimer);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFP_FirstPersonCharacter::OnFire);

	// Attempt to enable touch screen movement
	TryEnableTouchscreenMovement(PlayerInputComponent);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AFP_FirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFP_FirstPersonCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFP_FirstPersonCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFP_FirstPersonCharacter::LookUpAtRate);
}

void AFP_FirstPersonCharacter::OnFire()
{
	//fare timer per automatica.
	// if (WeaponSlot.IsAutomatic)
	// {
	// 	while ()
	// 	{
	// 		
	// 	}
	// }
	GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Red, FString::FromInt(CurrentAmmo));
	if (CurrentAmmo > 0)
	{
		CurrentAmmo--;

		// Play a sound if there is one
		if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		// Try and play a firing animation if specified
		if (FireAnimation != nullptr)
		{
			// Get the animation object for the arms mesh
			UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
			if (AnimInstance != nullptr)
			{
				AnimInstance->Montage_Play(FireAnimation, 1.f);
			}
		}

		// Now send a trace from the end of our gun to see if we should hit anything
		APlayerController* PlayerController = Cast<APlayerController>(GetController());

		FVector ShootDir = FVector::ZeroVector;
		FVector StartTrace = FVector::ZeroVector;

		if (PlayerController)
		{
			// Calculate the direction of fire and the start location for trace
			FRotator CamRot;
			//Setta i valori start e camrot
			PlayerController->GetPlayerViewPoint(StartTrace, CamRot);
			ShootDir = CamRot.Vector();

			// Adjust trace so there is nothing blocking the ray between the camera and the pawn, and calculate distance from adjusted start
			StartTrace = StartTrace + ShootDir * ((GetActorLocation() - StartTrace) | ShootDir);
		}

		// Calculate endpoint of trace
		const FVector EndTrace = StartTrace + ShootDir * WeaponRange;

		// Check for impact
		const FHitResult Impact = WeaponTrace(StartTrace, EndTrace);

		// Deal with impact
		AActor* DamagedActor = Impact.GetActor();
		PlayerHasShoot(DamagedActor, Impact.bBlockingHit);
		//OnHitActor.Broadcast(DamagedActor,Impact.bBlockingHit);
	}
	else if (CurrentAmmo == 0)
	{
		reloadTimer();
	}
}

void AFP_FirstPersonCharacter::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// If touch is already pressed check the index. If it is not the same as the current touch assume a second touch and thus we want to fire
	if (TouchItem.bIsPressed == true)
	{
		if (TouchItem.FingerIndex != FingerIndex)
		{
			OnFire();
		}
	}
	else
	{
		// Cache the finger index and touch location and flag we are processing a touch
		TouchItem.bIsPressed = true;
		TouchItem.FingerIndex = FingerIndex;
		TouchItem.Location = Location;
		TouchItem.bMoved = false;
	}
}

void AFP_FirstPersonCharacter::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// If we didn't record the start event do nothing, or this is a different index
	if ((TouchItem.bIsPressed == false) || (TouchItem.FingerIndex != FingerIndex))
	{
		return;
	}

	// If the index matches the start index and we didn't process any movement we assume we want to fire
	if ((FingerIndex == TouchItem.FingerIndex) && (TouchItem.bMoved == false))
	{
		OnFire();
	}

	// Flag we are no longer processing the touch event
	TouchItem.bIsPressed = false;
}

void AFP_FirstPersonCharacter::TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// If we are processing a touch event and this index matches the initial touch event process movement
	if ((TouchItem.bIsPressed == true) && (TouchItem.FingerIndex == FingerIndex))
	{
		if (GetWorld() != nullptr)
		{
			UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
			if (ViewportClient != nullptr)
			{
				FVector MoveDelta = Location - TouchItem.Location;
				FVector2D ScreenSize;
				ViewportClient->GetViewportSize(ScreenSize);
				FVector2D ScaledDelta = FVector2D(MoveDelta.X, MoveDelta.Y) / ScreenSize;
				if (FMath::Abs(ScaledDelta.X) >= (4.0f / ScreenSize.X))
				{
					TouchItem.bMoved = true;
					float Value = ScaledDelta.X * BaseTurnRate;
					AddControllerYawInput(Value);
				}
				if (FMath::Abs(ScaledDelta.Y) >= (4.0f / ScreenSize.Y))
				{
					TouchItem.bMoved = true;
					float Value = ScaledDelta.Y * BaseTurnRate;
					AddControllerPitchInput(Value);
				}
				TouchItem.Location = Location;
			}
			TouchItem.Location = Location;
		}
	}
}

void AFP_FirstPersonCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// Add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFP_FirstPersonCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// Add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AFP_FirstPersonCharacter::TurnAtRate(float Rate)
{
	// Calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFP_FirstPersonCharacter::LookUpAtRate(float Rate)
{
	// Calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

FHitResult AFP_FirstPersonCharacter::WeaponTrace(const FVector& StartTrace, const FVector& EndTrace) const
{
	// Perform trace to retrieve hit info
	FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(WeaponTrace), true, GetInstigator());
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, COLLISION_WEAPON, TraceParams);

	return Hit;
}

void AFP_FirstPersonCharacter::Reload()
{
	CurrentAmmo = MaxAmmo;
	reloadAnim();
	GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Red, "reloading");
	IsReloading = false;
}

void AFP_FirstPersonCharacter::reloadTimer()
{
	if (CurrentAmmo==MaxAmmo)
	{
		return;
	}
	GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Red, "started");
	if (!IsReloading)
	{
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &AFP_FirstPersonCharacter::Reload, reloadTime, false);
	}
	IsReloading = true;
}

void AFP_FirstPersonCharacter::setWeapon(FWeaponSlot WeaponToCopy)
{
	WeaponRange = WeaponToCopy.Range;
	WeaponDamage = WeaponToCopy.Damage;
	MaxAmmo=WeaponToCopy.MagCapacity;
	CurrentAmmo=WeaponToCopy.MagCapacity;
	IsReloading = false;
}


void AFP_FirstPersonCharacter::TryEnableTouchscreenMovement(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AFP_FirstPersonCharacter::BeginTouch);
	PlayerInputComponent->BindTouch(EInputEvent::IE_Released, this, &AFP_FirstPersonCharacter::EndTouch);
	PlayerInputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AFP_FirstPersonCharacter::TouchUpdate);
}
