// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Pickable.generated.h"

UCLASS()
class LEZIONE2_API APickable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickable();
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UBoxComponent*BoxComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= Gameplay)
	float damage;
	UFUNCTION()
	void OnTriggerEnter(AActor* overlappedActor, AActor* overlappingActor);   
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
