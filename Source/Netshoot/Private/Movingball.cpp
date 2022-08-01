// Fill out your copyright notice in the Description page of Project Settings.


#include "Movingball.h"

// Sets default values
AMovingball::AMovingball()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingball::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	time += DeltaTime;
	FVector loc = GetActorLocation(); 
	//loc.X = 10*abs(time% 400 - 200);
	loc.X = sin(time) * 100;
	loc.Y = cos(time) * 100;
	SetActorLocation(loc);
}

