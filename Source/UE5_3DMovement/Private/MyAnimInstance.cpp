// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMyAnimInstance::NativeInitializeAnimation()
{
	Character = Cast<AMyCharacter>(TryGetPawnOwner());

	if (Character)
	{
		CharacterMovement = Character->GetCharacterMovement();
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (Character)
	{
		GroundSpeed = CharacterMovement->Velocity.Size2D();
		isJumping = CharacterMovement->IsFalling();
		CharacterState = Character->GetCharacterState();
	}
}
