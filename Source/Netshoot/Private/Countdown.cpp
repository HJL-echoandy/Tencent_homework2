// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);

	RootComponent = CountdownText;
	Countdowntime = 60;
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();
	
	UpdateTimeDisplay();

	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);
}

// Called every frame
void ACountdown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACountdown::UpdateTimeDisplay()
{
	CountdownText->SetText(FString::FromInt(FMath::Max(Countdowntime, 0)));
}

void ACountdown::AdvanceTimer()
{
	--Countdowntime;
	UpdateTimeDisplay();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Hello world, this is %d"), Countdowntime), true);
	if (Countdowntime < 1)
	{
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
	}
}

