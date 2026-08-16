// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "DecalimpactBullet.generated.h"

/**
 * 
 */
UCLASS()
class OPTI17979_API ADecalimpactBullet : public ADecalActor
{
	GENERATED_BODY()

public:
	ADecalimpactBullet();


	UFUNCTION(BlueprintCallable, Category = "Decal")
	void SetupDecal(const FHitResult& hit, float lifeSpan = 2, float fadeTime = 1);

protected:

	FTimerHandle timerHandle;
	void ReturnDecalToPool();
	
};
