#include "DecalImpactBullet.h"
#include "Components/DecalComponent.h"
#include "ActorUtilities.h"

ADecalimpactBullet::ADecalimpactBullet()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ADecalimpactBullet::SetupDecal(const FHitResult& hit, float lifeSpan, float fadeTime)
{

	SetActorLocation(hit.ImpactPoint);
	SetActorRotation(hit.ImpactNormal.Rotation());

	UDecalComponent* decalComp = GetDecal();
	if (!IsValid(decalComp))
	{
		UE_LOG(LogTemp, Error, TEXT("DecalImpactBullet: No tiene un decalComponent"));
		return;
	}

	SetLifeSpan(0.0f);
	GetWorldTimerManager().ClearTimer(timerHandle);

	//Asegurarse que el decalComponent sea visible
	decalComp->SetVisibility(true);

	//resetear la opacidad del material por medio del delegado.
	OnDecalActivated.Broadcast();

	//Determinar tiempo de delay
	const float delayBeforeFade = FMath::Max(0.0f, lifeSpan - fadeTime);

	//llamar el fade por medio de un delegado.
	OnDecalStartFade.Broadcast(lifeSpan);
	FTimerHandle FadeTimer;
	GetWorldTimerManager().SetTimer(FadeTimer, [this, fadeTime]()
		{
		}, delayBeforeFade, false);

	GetWorldTimerManager().SetTimer(
		timerHandle,
		this,
		&ADecalimpactBullet::ReturnDecalToPool,
		lifeSpan,
		false
	);
}

void ADecalimpactBullet::ReturnDecalToPool()
{
	UActorUtilities::ToggleActorHidden(this, true);
}
