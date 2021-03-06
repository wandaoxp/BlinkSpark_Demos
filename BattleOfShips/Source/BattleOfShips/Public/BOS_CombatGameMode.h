// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "BOS_CombatGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEOFSHIPS_API ABOS_CombatGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ABOS_CombatGameMode();
	
	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual bool ShouldSpawnAtStartSpot(AController* Player) override;

	virtual void RestartPlayer(class AController * NewPlayer) override;

	// Properties
	UPROPERTY()
		int32 TeamID = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
		UDataTable *ShipBlockTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
		TArray<TSubclassOf<class ABOS_ShipBlock>> SpawnClasses;

	// Funcs
	UFUNCTION(BlueprintCallable, Category = "Factory|ShipBlock")
		AActor *ShipBlockFactory(int32 TypeID, FVector SpawnLoc, FRotator SpawnRot);
};
