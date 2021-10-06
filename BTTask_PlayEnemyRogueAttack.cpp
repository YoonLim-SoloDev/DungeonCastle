// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PlayEnemyRogueAttack.h"

EBTNodeResult::Type UBTTask_PlayEnemyRogueAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	EnemyController =
		Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	
	auto Blackboard = OwnerComp.GetBlackboardComponent();

	if (EnemyController) {
		EnemyController->StopMovement();
		//EnemyController->ClearFocus((EAIFocusPriority::Type)'\002');
		EnemyController->DoAttack();
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
