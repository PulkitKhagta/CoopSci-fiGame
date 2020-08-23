// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SExplosiveBarrel.generated.h"

class USHealthComponent;
class UStaticMeshComponent;
class URadialForceComponent;
class UParticleSystem;

UCLASS()
class COOPGAME_API ASExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplosiveBarrel();

protected:
	
	UPROPERTY(VisibleAnywhere, Category = "Comonents")
	USHealthComponent* HealthComp;

	UPROPERTY(VisibleAnywhere, Category = "Comonents")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Comonents")
	URadialForceComponent* RadialForceComp;

	UFUNCTION()
	void OnHealthChanged(USHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UPROPERTY(ReplicatedUsing = OnRep_Exploded)
	bool bExploded;

	UFUNCTION()
	void OnRep_Exploded();

	//Impulse apploed to the barrel mesh when it explodes to boost it up a little
    UPROPERTY(EditDefaultsOnly, Category = "FX")
	float ExplosionImpulse;

	//Particle to play when health reaches zero
	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UParticleSystem* ExplosionEffect;

	//The material to replace the original on the mesh once replaced (a blackened version)
	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UMaterialInterface* ExplodeMaterial;
};
