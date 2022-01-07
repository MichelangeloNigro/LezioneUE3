// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthEvent);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEZIONE2_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= Gameplay)
	float maxLife;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category= Gameplay)
	float currentLife;

	UPROPERTY(BlueprintAssignable)
	FHealthEvent OnHealthToZero;

	UPROPERTY(BlueprintAssignable)
	FHealthEvent OnTakeDamage;
	
	UFUNCTION(BlueprintCallable)
	void AssignDamage(float amount);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
