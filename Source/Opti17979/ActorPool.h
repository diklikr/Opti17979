// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TWINSTICKSHOOTER_API UActorPool : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorPool();

	UPROPERTY(EditAnywhere)
	int defaultSize = 10; // pool size

	UPROPERTY(EditAnywhere)
	TArray<AActor*> actorPool; // Actor array

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> actorTemplate; //clase de actor instanciado

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//funcion de instance del pool
	AActor* InstancePoolActor(TSubclassOf<AActor> actorRefrence);

	AActor* FindFirstActor(); //first available actor

public:	
	
	UFUNCTION(BlueprintCallable)
	AActor* GetActorFromPool();
};
