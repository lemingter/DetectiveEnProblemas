#include "Item.h"

#include "DetectiveEnProblemasGameMode.h"
#include "MeshAttributes.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AItem::AItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(35.0f,35.0f,35.0f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;
	SuperMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	SuperMesh->AttachToComponent(CollisionBox, FAttachmentTransformRules::SnapToTargetIncludingScale);
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlapBegin);
	PitchValue = 0.f;
	YawValue = 0.f;
	RollValue = 1.f;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(PitchValue, YawValue, RollValue), false, 0, ETeleportType::None);
}

void AItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADetectiveEnProblemasGameMode* MyGameMode = Cast<ADetectiveEnProblemasGameMode>(GetWorld()->GetAuthGameMode());
	if (MyGameMode != nullptr)
	{
		MyGameMode->Counter ++;
	}

	this->Destroy();
}