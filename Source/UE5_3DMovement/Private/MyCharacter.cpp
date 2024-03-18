#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Math/RotationMatrix.h>
#include <Math/MathFwd.h>
#include <Weapon.h>

AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Camera Setup

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(FName("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(FName("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);

	// Character Rotation

	bUseControllerRotationYaw = false;
	CameraBoom->bUsePawnControlRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;

}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Axis

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AMyCharacter::LookUp);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AMyCharacter::Turn);

	// Actions

	PlayerInputComponent->BindAction(FName("MouseRightClick"), EInputEvent::IE_Pressed, this, &AMyCharacter::MouseRightClickPressed);
	PlayerInputComponent->BindAction(FName("MouseRightClick"), EInputEvent::IE_Released, this, &AMyCharacter::MouseRightClickReleased);
	PlayerInputComponent->BindAction(FName("Equip"), EInputEvent::IE_Pressed, this, &AMyCharacter::EKeyPressed);
	PlayerInputComponent->BindAction(FName("Jump"), EInputEvent::IE_Released, this, &ACharacter::Jump);
}

void AMyCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(FRotator(0.f, GetControlRotation().Yaw, 0.f)).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AMyCharacter::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(FRotator(0.f, GetControlRotation().Yaw, 0.f)).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AMyCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AMyCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AMyCharacter::MouseRightClickPressed()
{
	bUseControllerRotationYaw = true;
}

void AMyCharacter::MouseRightClickReleased()
{
	bUseControllerRotationYaw = false;
}

void AMyCharacter::EKeyPressed()
{
	if (OverlapingItem)
	{
		AWeapon* Weapon = Cast<AWeapon>(OverlapingItem);

		if (Weapon)
		{
			Weapon->Equip(GetMesh(), FName("hand_rSocket"));
			CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
		}
	}
}

