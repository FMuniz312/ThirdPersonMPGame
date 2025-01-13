#include "GameAttributeSet.h"
#include "Net/UnrealNetwork.h"

void UGameAttributeSet::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGameAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameAttributeSet, ShieldHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGameAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UGameAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGameAttributeSet, Health, OldHealth);
}

void UGameAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGameAttributeSet, Stamina, OldStamina);
}

void UGameAttributeSet::OnRep_ShieldHealth(const FGameplayAttributeData& OldShieldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGameAttributeSet, ShieldHealth, OldShieldHealth);
}

void UGameAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGameAttributeSet, MovementSpeed, OldMovementSpeed);
}

void UGameAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGameAttributeSet, MaxHealth, OldMaxHealth);
}
