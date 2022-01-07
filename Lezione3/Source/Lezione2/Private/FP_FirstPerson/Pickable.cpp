// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_FirstPerson/Pickable.h"

#include "FP_FirstPerson/HealthComponent.h"
#include "GameFramework/Character.h"

// Sets default values
// Sets default values
APickable::APickable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent=CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	BoxComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("UBoxComponent"));
}

// Called when the game starts or when spawned
void APickable::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &APickable::OnTriggerEnter);
}

// Called every frame
void APickable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickable::OnTriggerEnter(AActor* overlappedActor, AActor* overlappingActor)
{
	if(overlappingActor->IsA(ACharacter::StaticClass()))
	{
		UHealthComponent* LifeManager;
		LifeManager = Cast<UHealthComponent>(overlappingActor->GetComponentByClass(UHealthComponent::StaticClass())) ;
		check(LifeManager);
		if (IsValid(LifeManager))
		{
			LifeManager->AssignDamage(damage);
			overlappedActor->Destroy();
		}
	}
}

