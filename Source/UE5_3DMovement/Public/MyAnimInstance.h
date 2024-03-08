// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

class UCharacterMovementComponent;
class AMyCharacter;

UCLASS()
class UE5_3DMOVEMENT_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()



public:	
	void NativeInitializeAnimation() override;
	void NativeUpdateAnimation(float DeltaSeconds) override;

	 UPROPERTY(BlueprintReadOnly)
	float GroundSpeed;
	UPROPERTY(BlueprintReadOnly)
	bool isJumping;

private:
	UCharacterMovementComponent* CharacterMovement;
	AMyCharacter* Character;


	
};
