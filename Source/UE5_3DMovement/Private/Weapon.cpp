// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"

void AWeapon::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Green, FString(TEXT("Entrou")));
	}
}

void AWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red, FString(TEXT("Saiu!")));
	}
}

void AWeapon::Equip(USceneComponent* InParent, FName InSocketName)
{
	StaticMesh->AttachToComponent(InParent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), InSocketName);
}
