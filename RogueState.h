// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Castle_in_DungeonGameModeBase.h"
#include "RogueSaveGame.h"
#include "GameSettingSave.h"
#include "Door.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "RogueState.generated.h"

/**
 * 
 */
UCLASS()
class CASTLE_IN_DUNGEON_API ARogueState : public APlayerState
{
	GENERATED_BODY()


public:
	ARogueState();

protected:
	virtual void BeginPlay() override;

public:
	float GetRogueHp() { return RogueHp; }
	int32 GetRogueFullHp() { return FullMaxHp; }
	void SetFullMaxRogueHp(int32 FullHps) {
		FullMaxHp = FullHps;
	}
	void SetRogueHp(int32 newHp) { RogueHp = newHp; }
	void SetDamegedRogue(float Dameged);

	int32 GetCurrentKarma() { return CurrentKarma; }
	void SetCurrentKarma(int32 newKarma);
	void SetPlusCurrentKarma(int32 newKarma);

	int32 GetRogueKill() { return RogueKill; }
	void setRogueKill(int32 newKill) { RogueKill += newKill; }
	
	int32 GetRogueTotalKill() { return RogueTotalKill; }
	void setRogueTotalKill(int32 newKill) { RogueTotalKill += newKill; }
	
	int32 GetRogueDeath() { return RogueDeath; }
	void setRogueDeath(int32 newDeath) { RogueDeath += newDeath; }

	int32 GetRogueData() { return CurrentData; }
	void SetStaticRogueData(int32 UseDataValue);

	int32 GetRogueAllData() { return AllData; }
	int32 GetRogueUsedData() { return UsedData; }

	void SetRogueDeshData(float UseDataValue, float Data);

	void SetDynamicRogueData(int32 UseDataValue);

	bool getTorchElementOne(int32 SelectElementNumber) { return HadTorchElement[SelectElementNumber]; }
	void SetTorchElementOne(int32 SelectElementNumber, bool Take);

	bool getWeaponElementOne(int32 SelectElementNumber) { return HadWeaponElement[SelectElementNumber]; }
	void SetWeaponElementOne(int32 SelectElementNumber, bool Take);

	float getSelectWeapon() { return WeaponNumber; }
	void SetSelectWeapon(int32 SelectWeaponNumber);

	bool GetSaveState() { return SaveState; }
	void SetSaveState(bool SaveStates) { SaveState = SaveStates; }

	int32 SaveCount;
	
public:
	void TorchElementInit();
	void WeaponElementInit();
	void DataInit();
	void KarmaInit();
	void CurrentHpInit();
	void RogueKillInit();
	void getWorldGameModeBase();
	void AbilityInit();
	void AttackFormInit();
	void Widget_ViewInit();
	void HadWeaponCheckInit();
	void HadAttackFormCheckInit();
	void AbilityHadCheckInit();
	void ElementalHadCheckInit();
	void Call_HadWeapon();
	void Call_HadAttackForm();
	void Call_HadAbility();
	void Call_Elemental();
	//void SetEquipmentStringsInit();
	void AttackFormChange(int32 AttackForm, int32 AttackFormIndex, int32 AttackSlot);

public:
	void TorchElementDelegateInit();
	void WeaponElementDelegateInit();
	void WeaponChangeDelegateInit();
	void AttackAnimationDelegateInit();
	void DamegeDelegateInit();
	void RogueDataAndKarmaDelegateInit();
	void RogueAttackPlusIncreaseDelegateInit();
	void Call_RogueStartWeaponNumber();
	void Call_RogueStartAttackFormNumber();
	void Call_RogueStartTorchElementalNumber();

public:
	void GetWeaponSynergy(int32 WeaponNumbers, float Slash, float Break, float Stab, float WeaponDefaultDamege, float WeaponSpeed);
	void GetWeaponElementSynergy(float ElementSynergy, float ElementDefaultDamge, float ElementPer);
	void SetAttackAnimation();
	void GetAttackFormSynergy(float*, bool*, int32[3][2]);
	//void SetAttackAnimationSlot(int32 ChangeSlot) { AttackAnimationSlotCheck = ChangeSlot; }
	void GetTorchStatusSynergy(float DefaultDamege, float BurnAttacksDefault, float SpecialDefault, 
		float ElementCriper);

public:
	void GetTorchDemege();
	void GetWeaponPhysicsDamege();
	void GetWeaponElementDamege();
	void GetWeaponTotalDamege();

public:
	void SetTorchLevelUp();
	void SetWeaponLevelUp();
	void SetElementLevelUp();

public:
	void SetEquipmentStrings();
	void SetEquipmentAttackFormString(TCHAR** AttackFormString);
	void SetStatData();
	void SetGameState();
	void GetMoveSpeed(float MoveSpeed);
	int32 GetDialogueIndex();
	void SetDialogueIndex(int32 NewIndex);

public:
	int32 SlashSynergyIncreaseCount;
	void SlashSynergyIncrease();
	void DeleteSlashSynergyIncrease();
	
	int32 BreakSynergyIncreaseCount;
	void BreakSynergyIncrease();
	void DeleteBreakSynergyIncrease();
	
	int32 StabSynergyIncreaseCount;
	void StabSynergyIncrease();
	void DeleteStabSynergyIncrease();
	
	int32 BurnAttacksDamegeIncreaseCount;
	void BurnAttacksDamegeIncrease();
	void DeleteBurnAttacksDamegeIncrease();

	int32 CertainIncreaseCount;
	void CertainIncrease(int32);
	void DeleteCertainIncrease(int32);

	int32 BurnAttacksHitIncreaseCount;
	//int32 PreBurnAttacksHitIncreaseCount;
	void BurnAttacksHitIncrease();
	void DeleteBurnAttacksHitIncrease();

	int32 MoveSpeedIncreaseCount;
	//int32 PreMoveSpeedIncreaseCount;
	void MoveSpeedIncrease();
	void DeleteMoveSpeedIncrease();

	int32 HitToKnockBackCount;
	void HitToKnockBack();
	void DeleteHitToKnockBack();

	//int32 DoubleStateEffectDamegeIncreaseCount;
	//void DoubleStateEffectDamegeIncrease();

	int32 SuperArmorCount;
	void SuperArmor();
	void DeleteSuperArmor();

	int32 DamegeToHpChargeCount; //전투 구현 후
	void DamegeToHpCharge(); //전투 구현 후

	int32 AttackSuccessToSpecialPerPlusCount;
	void AttackSuccessToSpecialperPlus();
	void DeleteAttackSuccessToSpecialperPlus();

	int32 AttackTryToLowDataDecreaseCount;
	void AttackTryToLowDataDecrease();
	void DeleteAttackTryToLowDataDecrease();

	int32 TorchSpecialPerIncreaseCount;
	void TorchSpecialPerIncrease();
	void DeleteTorchSpecialPerIncrease();

	int32 WeaponSpecialPerIncreaseCount;
	void WeaponSpecialPerIncrease();
	void DeleteWeaponSpecialPerIncrease();

	int32 TorchSpecialDamegeIncreaseCount;
	void TorchSpecialDamegeIncrease();
	void DeleteTorchSpecialDamegeIncrease();

	int32 WeaponSpecialDamegeIncreaseCount;
	void WeaponSpecialDamegeIncrease();
	void DeleteWeaponSpecialDamegeIncrease();

	int32 AttackFormSpeedIncreaseCount;
	void AttackFormSpeedIncrease();
	void DeleteAttackFormSpeedIncrease();

	int32 LowHpToHighAttackSynergyCount;
	void LowHpToHighAttackSynergy();
	void DeleteLowHpToHighAttackSynergy();

	int32 FullHpToHighAttackSynergyCount;
	void FullHpToHighAttackSynergy();
	void DeleteFullHpToHighAttackSynergy();

	int32 NoHitToHighAttackSynergyCount;
	void NoHitToHighAttackSynergy();
	void DeleteNoHitToHighAttackSynergy();

	int32 HpIncreaseCount;
	void HpIncrease();
	void DeleteHpIncrease();

public:
	void AbilityRandTake(int32 AbilityIndex);
	void WeaponHadCheck(int32 WeaponNumber);
	void AttackFormHadCheck(int32 AttackForm, int32 AttackFromIndex);
	void AbilityHadCheck(int32 AbilityIndexNumber);
	void ElementalHadCheck(int32 ElementalIndexNumber);
	void GetRogueAbilityIndexAndString();
	void LastWeaponDamegeSetting();
	void LastTorchDamegeSetting();
	void LastSpeedSetting();
	void DeleteAbility();
	void SaveGameData();
	void SaveGameSetting();
	void RogueDataInit();
	void GameSettingSaveInit();
	void LoadGameData(URogueSaveGame* SaveData);
	void LoadGameSetting(UGameSettingSave* SaveSettingData);
	void DialogueRefInit();
	void DialgoueStateInit();
	void PlusDungeonClearCount(int32 DungeonIndex);
	UFUNCTION(BlueprintCallable)
		int32 GetDungeonClearCount(int32 DungeonIndex);
	UFUNCTION(BlueprintCallable)
		int32 GetDungeonClearAllCount();
	//void GetRogue();

public:
	ACastle_in_DungeonGameModeBase* MyGameMode;

private:
	int32 RogueHp;
	int32 FullMaxHp;
	int32 CurrentKarma;
	int32 RogueKill;
	int32 RogueTotalKill;
	int32 RogueDeath;
	int32 CurrentData;
	int32 AllData;
	int32 UsedData;
	int32 DialogueIndex;
	float UseDataValuePercent;
	float UseDeshData;

	float WeaponElementSynergy;
	float SlashSynergy;
	float BreakSynergy;
	float StabSynergy;
	float WeaponSpeed;
	float WeaponSpeedValueBonus;
	float AttackFormSynergy[3][3];
	bool DoubleAttackCheck[3];
	int32 AttackDirectionCheck[3][2];
	float RogueMoveSpeed;
	
	
	float WeaponPhysicsDamege[3];
	float WeaponElementDamege;
	float WeaponElementDamegeBonus;
	float WeaponTotalDamege[3];
	
	float WeaponDefaultDamege;
	float WeaponElementDefaultDamge;
	float WeaponElementValue;
	float WeaponElementValueBonus;
	float AvgWeaponDamege;
	float LastAvgWeaponDamege;
	float LastAvgWeaponEDamge;

	float TorchStabDefaultDamege;
	float TorchBurnAttacksDefaultDamege;
	float TorchElementSpecialDefaultDamege;
	
	float TorchElementSynergy;
	float TorchElementSpecialSynergy;
	float TorchElementCriper;
	float TorchElementCriperValue;

	float TorchBurnAttackSynergy;
	
	float TorchStabTotalDamege;
	float TorchBurnAttacksTotalDamege;
	float TorchSpecialTotalDamege;
	float TorchSpecialTotalDamegeValue;
	
	int32 WeaponElementNumber;
	int32 WeaponNumber;
	int32 TorchElementNumber;
	float WeaponLevelValue;
	int32 WeaponLevel;
	float TorchLevelValue;
	int32 TorchLevel;
	float ElementLevelValue;
	int32 ElementLevel;


	float SelectedElementBonus[5];

	int32 AttackForm[3];
	int32 AttackFormIndex[3];
	int32 AttackFormNumber;
	int32 AttackFormIndexNumber;
	int32 AttackAnimationSlotCheck = 0;

	int32 Strength;
	int32 Concentration;
	int32 Calmness;
	int32 Agility;

	float StatData[16];
	float GameStateData[5];
	FString SaveSlotName;
	FString GameSettingName;
	FString EquipData[6];
	int32 EquipNumberData[3];
	TCHAR* EquipAttackFormVideoData[3];
	TCHAR* EquipAttackFormRefData[3];
	FString WeaponName;
	FString WeaponElementName;
	FString TorchElementName;
	//FString AttackFormName[3];
	FString AttackFormName[4][10];
	TCHAR *RogueAttackFormVideoString[4][10];
	FString AbilityName[100];
	FString AbilityTotalName[100];
	FString AbilityOverlapString[100];
	int32 AbilityQue[100];
	bool SaveState;
	bool NewGame;
	bool DungeonIn;
	bool HadWeaponCheck[10];
	bool HadAttackFormCheck[4][10];
	bool HadAbilityCheck[24];
	bool HadElementalCheck[10];
	bool EquipAbilityOverlap;
	bool DialogueStepCheck[4];
	float HadAbilityOverlap[24];
	float HadAttackFormOverlap[4][10];
	float HadWeaponOverlap[10];
	float HadElementalOverlap[10];
	float OverlapData[6];
	float* TotalOverlapData[6];
	
	//TArray<ADoor> *ShortCutDoor;
	TArray<int32> TotalEquipAbilityDataList;
	TArray<int32> TotalWeaponDataList;
	TArray<int32> TotalElementDataList;
	TArray<int32> TotalAttackFormDataList1;
	TArray<int32> TotalAttackFormDataList2;

public:
	int32 StartWeaponNumber;
	int32 StartWeaponElementNumber;
	int32 StartTorchElementNumber;
	int32 EquipAbilityCount;
	int32 TotalAbilityCount;
	int32 TotalEquipCount;
	int32 TotalWeaponCount;
	int32 TotalElementCount;
	int32 TotalAttackFormCount;
	float SlashValueBonus;
	float BreakValueBonus;
	float StabValueBonus;
	float TorchBurnAttackSynergyValue;
	int32 ItemCount;
	int32 DialogueTutorialCount;
	float MoveSpeedIncreaseCountValue;
	int32 DoorStateCheck[10];
	float WeaponLevelEx;
	float TorchLevelEx;
	float ElementLevelEx;
	float WeaponLevelExMax;
	float TorchLevelExMax;
	float ElementLevelExMax;

private:
	bool HadTorchElement[5];
	bool HadWeaponElement[5];
	bool StateEffect[9];

private:
	bool Ignite;
	bool Freezing;
	bool Poisoning;
	bool ElectricShock;
	bool Stun;
	bool Fear;
	bool Mad;
	bool Stablity;

	UPROPERTY(EditAnywhere)
		int32 DungeonClearCount[3];
	UPROPERTY(EditAnywhere)
		int32 DungeonClearAllCount;



public:
	int32 TaskLevel;
	int32 StartDialogueState[7];
	int32 MainDialogueState[5];
	int32 SubDialogueState[2][4];
	//int32 Eng_StartDialogueState[7];
	//int32 Eng_MainDialogueState[5];
	//int32 Eng_SubDialogueState[2][4];
	
	TCHAR* StartDialogueSourceRef[7][3];
	//TCHAR* StartDialogueSoundRef[7];
	TCHAR* MainStoryDialogueSourceRef[5][3];
	TCHAR* SubStoryDialogueSourceRef[2][4][3];
};
