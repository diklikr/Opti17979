// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPool.h"
#include "ActorUtilities.h"

// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UActorPool::BeginPlay()
{
	Super::BeginPlay();

	if (!actorTemplate || defaultSize <= 0) { return; }

	for (int i = 0; i < defaultSize; i++) {
		InstancePoolActor(actorTemplate);
	}
}

AActor* UActorPool::InstancePoolActor(TSubclassOf<AActor> actorRefrence)
{
	FActorSpawnParameters spawnInfo;
	spawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* actor = GetWorld()->SpawnActor<AActor>(actorRefrence, spawnInfo);

	if (!actor)
	{
		return nullptr;
	}

	actorPool.Add(actor);

	UActorUtilities::ToggleActorHidden(actor, true);

	return actor;
}

AActor* UActorPool::FindFirstActor()
{
	for (AActor* actor : actorPool) {
		if (actor && actor->IsHidden()) { return actor; }
	}
	return InstancePoolActor(actorTemplate);
}

AActor* UActorPool::GetActorFromPool()
{
	AActor* actorFound = FindFirstActor();

	if (actorFound) { UActorUtilities::ToggleActorHidden(actorFound, false); return actorFound; }
	return nullptr;
}
