// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "MyActor.generated.h"

UCLASS()
class LEZIONE2_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UBoxComponent*BoxComponent;
	FTimerHandle UnusedHandle;
	// UFUNCTION()
	//  void OnBeginOverlap(AActor* overlappedActor, AActor* overlappingActor);
	//
	// UFUNCTION()
	//  void OnEndOverlap(AActor* overlappedActor, AActor* overlappingActor);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Settings")
	TMap<int, AActor*> MyMap;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Settings")
	int tickTime;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Settings")
	TSubclassOf<AActor> SensedClass= {ACharacter::StaticClass()};
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Settings")
	TArray<AActor*> ActorInside;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Settings")
	TArray<AActor*> ActorSensed;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void CheckCollider();

};
