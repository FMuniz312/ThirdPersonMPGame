
#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameAttributeSet.generated.h"

// Macro to autogenerate getters and setters functions for the attributes
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * For sake of simplicity, I will use a single attribute set to represent any and all gameplay attributes. 
 */
UCLASS()
class THIRDPERSONMPGAME_API UGameAttributeSet : public UAttributeSet
{ 

private:
	GENERATED_BODY()
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
protected:
	UPROPERTY(BlueprintReadOnly, Category = "PlayerStats", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGameAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category = "PlayerStats", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UGameAttributeSet, Stamina)

	UPROPERTY(BlueprintReadOnly, Category = "Combat", ReplicatedUsing = OnRep_ShieldHealth)
	FGameplayAttributeData ShieldHealth;
	ATTRIBUTE_ACCESSORS(UGameAttributeSet, ShieldHealth)

	UPROPERTY(BlueprintReadOnly, Category = "PlayerStats", ReplicatedUsing = OnRep_MovementSpeed)
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UGameAttributeSet, MovementSpeed)
	
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	
	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);
	
	UFUNCTION()
	virtual void OnRep_ShieldHealth(const FGameplayAttributeData& OldShieldHealth);

	UFUNCTION()
	virtual void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed);
	
};
