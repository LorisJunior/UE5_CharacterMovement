#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "MyCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AItem;



UCLASS()
class UE5_3DMOVEMENT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AMyCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Input

	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookUp(float Value);
	void Turn(float Value);
	void MouseRightClickPressed();
	void MouseRightClickReleased();
	void EKeyPressed();
	void Attack();

	bool CanAttack();

	// Animation Montage

	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* AttackMontage = nullptr;

	UPROPERTY(BlueprintReadWrite)
	EActionState ActionState = EActionState::EAS_Unoccupied;

protected:

	virtual void BeginPlay() override;

	// Camera Setup

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

private:

	// States

	UPROPERTY(VisibleAnywhere)
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;


	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlapingItem = nullptr;

	// Animation

	void PlayAttackMontage();

public:

	FORCEINLINE void SetOverlapingItem(AItem* Item) { OverlapingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};
