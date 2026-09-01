// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "DecalimpactBullet.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDecalActivated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDecalStartFade, float, FadeDuration);
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




	UPROPERTY(BlueprintAssignable, Category = "Decal")
	FOnDecalActivated OnDecalActivated;

	UPROPERTY(BlueprintAssignable, Category = "Decal")
	FOnDecalStartFade OnDecalStartFade;


	FTimerHandle timerHandle;
	void ReturnDecalToPool();
};
