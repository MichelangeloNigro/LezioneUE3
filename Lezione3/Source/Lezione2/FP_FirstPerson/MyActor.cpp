// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval= 0.2f;
	RootComponent=CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	BoxComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("UBoxComponent"));
}
// void AMyActor::OnBeginOverlap(AActor* overlappedActor, AActor* overlappingActor)
// {
// 	UClass*OtherActorClass=overlappingActor->GetClass();
// 	for (auto& sensedCharacterClass:SensedClass)
// 	{
// 		if (sensedCharacterClass==OtherActorClass||OtherActorClass->IsChildOf(sensedCharacterClass))
// 		{
// 			GEngine->AddOnScreenDebugMessage(-1,6.f, FColor::Red,"class:" +sensedCharacterClass->GetName());
// 			ActorInside.Add(overlappingActor);
//
// 		}
// 	}
// 	if(!IsValid(overlappedActor))
// 	{
// 		return;
// 	}
// 	UWorld* world=GetWorld();
// 	if(!IsValid(world))
// 	{
// 		return;
// 	}
// 	if(overlappingActor==UGameplayStatics::GetPlayerPawn(world, 0))
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1,2.f, FColor::Cyan,"in" +overlappingActor->GetName());
// 	}
// }
//
// void AMyActor::OnEndOverlap(AActor* overlappedActor, AActor* overlappingActor)
// {/*
// 	if(!IsValid(overlappedActor))
// 	{
// 		return;
// 	}
// 	UWorld* world=GetWorld();
// 	if(!IsValid(world))
// 	{
// 		return;
// 	}
// 	if(overlappingActor==UGameplayStatics::GetPlayerPawn(world, 0))
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1,2.f, FColor::Cyan,"out" +overlappingActor->GetName());
// 	}
// 	*/
// 	UClass*OtherActorClass=overlappingActor->GetClass();
// 	for (auto& sensedCharacterClass:SensedClass)
// 	{
// 		if (sensedCharacterClass==OtherActorClass||OtherActorClass->IsChildOf(sensedCharacterClass))
// 		{
// 			GEngine->AddOnScreenDebugMessage(-1,6.f, FColor::Red,"class:" +sensedCharacterClass->GetName());
// 			ActorInside.Remove(overlappingActor);
//
// 		}
// 	}
// }

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	//OnActorBeginOverlap.AddDynamic(this, &AMyActor::OnBeginOverlap);
	//OnActorEndOverlap.AddDynamic(this, &AMyActor::OnEndOverlap);
	// if (IsOverlappingActor(UGameplayStatics::GetPlayerPawn(world,0)))
	// {
	// 	OnBeginOverlap(this,UGameplayStatics::GetPlayerPawn(world,0));
	// }
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PrimaryActorTick.TickInterval= tickTime;
	CheckCollider();
	
	
}
void AMyActor::CheckCollider()
{
	GetOverlappingActors(ActorSensed,SensedClass);
	for (auto actor : ActorSensed)
	{
		if (!ActorInside.Contains(actor))
		{
			ActorInside.Add(actor);
		}
	}
	for (auto actor : ActorInside)
	{
		if (!ActorSensed.Contains(actor))
		{
			ActorInside.Remove(actor);
		}
	}
}