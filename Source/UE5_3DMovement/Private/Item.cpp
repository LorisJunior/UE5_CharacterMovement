
#include "Item.h"
#include "Components/SphereComponent.h"
#include "MyCharacter.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	// Components

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	StaticMesh->SetupAttachment(GetRootComponent());
	SphereCollision = CreateDefaultSubobject<USphereComponent>(FName("Sphere Collision"));
	SphereCollision->SetupAttachment(StaticMesh);
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereBeginOverlap);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndOverlap);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (canOscilate)
	{
		AddActorWorldOffset(FVector(0.f, 0.f, SinOscillation(DeltaTime)));
	}
}

float AItem::SinOscillation(float DeltaTime)
{
	RunningTime += DeltaTime;
	const float ZOffset = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	return ZOffset;
}

void AItem::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMyCharacter* Character = Cast<AMyCharacter>(OtherActor);

	if (Character)
	{
		Character->SetOverlapingItem(this);
		canOscilate = false;
	}
}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AMyCharacter* Character = Cast<AMyCharacter>(OtherActor);

	if (Character)
	{
		Character->SetOverlapingItem(nullptr);
	}
}
