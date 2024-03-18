
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;

UCLASS()
class UE5_3DMOVEMENT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	

	AItem();
	virtual void Tick(float DeltaTime) override;

	// Floating item params

	float RunningTime = 0.f;

	UPROPERTY(EditInstanceOnly, Category = "C++")
	float Amplitude = 2.0f;
	UPROPERTY(EditInstanceOnly, Category = "C++")
	float TimeConstant = 5.0f;

	float SinOscillation(float DeltaTime);

protected:

	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereCollision;

private:

	bool canOscilate = true;


};
