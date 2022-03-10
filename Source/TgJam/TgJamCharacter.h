// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TgJamCharacter.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStats
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current Stats")
	int Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current Stats")
	int Dexterity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current Stats")
	int Constitution;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current Stats")
	int Intelligence;	
};

class UPlayerHealthSystem;
class UInventoryComponent;
UCLASS(config=Game)
class ATgJamCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ATgJamCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current Stats")
	FCharacterStats BaseStats;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current Stats")
	FCharacterStats CurrentStats;	

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);
	

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPlayerHealthSystem* HealthSystem;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UInventoryComponent* InventoryComponent;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable,Category="Inventory functions")
	void AddPotionToPlayer() const;

	UFUNCTION(BlueprintCallable,Category="Inventory functions")
	void AddArmorToPlayer(int ArmorValue) const;
	
};

