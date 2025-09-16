// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorGameplayTags.h"
namespace WarriorGameplayTags
{
	//*********InputTags*********//
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe, "InputTag.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Equip, "InputTag.Equip");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAxe, "InputTag.UnequipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Unequip, "InputTag.Unequip");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Axe, "InputTag.LightAttack.Axe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Sword, "InputTag.LightAttack.Sword");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Axe, "InputTag.HeavyAttack.Axe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Sword, "InputTag.HeavyAttack.Sword");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Roll, "InputTag.Roll");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_MustBeHeld, "InputTag.MustBeHeld");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_MustBeHeld_Block, "InputTag.MustBeHeld.Block");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_MustBeHeld_Sprint, "InputTag.MustBeHeld.Sprint");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Toggleable, "InputTag.Toggleable");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Toggleable_TargetLock, "InputTag.Toggleable.TargetLock");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Toggleable_Rage, "InputTag.Toggleable.Rage");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_SwitchTarget, "InputTag.SwitchTarget");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_SpecialWeaponAbility_Light, "InputTag.SpecialWeaponAbility.Light");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_SpecialWeaponAbility_Heavy, "InputTag.SpecialWeaponAbility.Heavy");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_PickUp_Stones, "InputTag.PickUp.Stones");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Switchable_BetweenWalkAndRun, "InputTag.Switchable.BetweenWalkAndRun");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Dodge, "InputTag.Dodge");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_AttackRising, "InputTag.AttackRising");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_AttackDown, "InputTag.AttackDown");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_DodgeAttackInAir, "InputTag.DodgeAttackInAir");
	
	//*********PlayerTags*********//
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Axe, "Player.Ability.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Axe, "Player.Ability.Unequip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack, "Player.Ability.Attack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Axe, "Player.Ability.Attack.Light.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Axe, "Player.Ability.Attack.Heavy.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Sworde, "Player.Ability.Attack.Heavy.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Sword, "Player.Ability.Attack.Heavy.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_HitPause, "Player.Ability.HitPause");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Roll, "Player.Ability.Roll");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Block, "Player.Ability.Block");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_TargetLock, "Player.Ability.TargetLock");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Rage, "Player.Ability.Rage");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_SpecialWeaponAbility_Light, "Player.Ability.SpecialWeaponAbility.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_SpecialWeaponAbility_Heavy, "Player.Ability.SpecialWeaponAbility.Heavy");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_PickUp_Stones, "Player.Ability.PickUp.Stones");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Dodge, "Player.Ability.Dodge");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Sprint, "Player.Ability.Sprint");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Jump, "Player.Ability.Jump");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_AttackRising, "Player.Ability.AttackRising");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_AttackDown, "Player.Ability.AttackDown");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_DodgeAttackInAir, "Player.Ability.DodgeAttackInAir");

	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_SpecialWeaponAbility_Light, "Player.Cooldown.SpecialWeaponAbility.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_SpecialWeaponAbility_Heavy, "Player.Cooldown.SpecialWeaponAbility.Heavy");
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_SpecialWeaponAbility_AttackRising, "Player.Cooldown.SpecialWeaponAbility.AttackRising");

	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Sword, "Player.Weapon.Sword");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Axe, "Player.Event.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Axe, "Player.Event.Unequip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_HitPause, "Player.Event.HitPause");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SuccessfulBlock, "Player.Event.SuccessfulBlock");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_PerfectBlock, "Player.Event.PerfectBlock");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_BlockBreached, "Player.Event.BlockBreached");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SwitchTarget_Left, "Player.Event.SwitchTarget.Left");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SwitchTarget_Right, "Player.Event.SwitchTarget.Right");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ActivateRage, "Player.Event.ActivateRage");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_AOE, "Player.Event.AOE");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ConsumeStones, "Player.Event.ConsumeStones");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_PerfectDodge, "Player.Event.PerfectDodge");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Sprint, "Player.Event.Sprint");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_CancelRecovery, "Player.Event.CancelRecovery");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_EnableGrabAbility, "Player.Event.EnableGrabAbility");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_DisableGrabAbility, "Player.Event.DisableGrabAbility");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rolling, "Player.Status.Rolling");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Blocking, "Player.Status.Blocking");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_TargetLock, "Player.Status.TargetLock");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_Activatinng, "Player.Status.Rage.Activatinng");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_Activate, "Player.Status.Rage.Activate");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_Full, "Player.Status.Rage.Full");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_None, "Player.Status.Rage.None");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Walking, "Player.Status.Walking");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Running, "Player.Status.Running");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Sprinting, "Player.Status.Sprinting");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Dodging, "Player.Status.Dodging");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Jumping, "Player.Status.Jumping");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ComboAllowed, "Player.Status.ComboAllowed");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_RecoveryCancelAllowed, "Player.Status.RecoveryCancelAllowed");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Recovering_BlockBreached, "Player.Status.Recovering.BlockBreached");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Dodging_Invinciable, "Player.Status.Dodging.Invinciable");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_MovementMode_OnGround, "Player.Status.MovementMode.OnGround");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_MovementMode_InAir, "Player.Status.MovementMode.InAir");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Attacking, "Player.Status.Attacking");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Light, "Player.SetByCaller.AttackType.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Heavy, "Player.SetByCaller.AttackType.Heavy");


	//*********EnemyTags*********//

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee, "Enemy.Ability.Melee");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Ranged, "Enemy.Ability.Ranged");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_SummonEnemies, "Enemy.Ability.SummonEnemies");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Spawn_Stone, "Enemy.Ability.Spawn.Stone");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Event_SummonEnemies, "Enemy.Event.SummonEnemies");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Strafing, "Enemy.Status.Strafing");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_UnderAttack, "Enemy.Status.UnderAttack");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Unblockable, "Enemy.Status.Unblockable");
	
	//*********SharedTags*********//
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact, "Shared.Event.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_SpawnProjectile, "Shared.Event.SpawnProjectile");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_EndCurrentActivatedAbility, "Shared.Event.EndCurrentActivatedAbility");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Block_Successful, "Shared.Event.Block.Successful");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Block_Perfect, "Shared.Event.Block.Perfect");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Block_Breached, "Shared.Event.Block.Breached");
	
	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage, "Shared.SetByCaller.BaseDamage");

	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact, "Shared.Ability.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Death, "Shared.Ability.Death");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Block, "Shared.Ability.Block");

	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Dead, "Shared.Status.Dead");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Front, "Shared.Status.HitReact.Front");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Left, "Shared.Status.HitReact.Left");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Right, "Shared.Status.HitReact.Right");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Back, "Shared.Status.HitReact.Back");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Invincible, "Shared.Status.Invincible");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_BeGrabing, "Shared.Status.BeGrabing");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Walking, "Shared.Status.Walking");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Running, "Shared.Status.Running");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Sprinting, "Shared.Status.Sprinting");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Blocking, "Shared.Status.Blocking");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_TargetLock, "Shared.Status.TargetLock");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Unblockable, "Shared.Status.Unblockable");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Block_Starting, "Shared.Status.Block.Starting");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Block_Holding, "Shared.Status.Block.Holding");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Block_Ending, "Shared.Status.Block.Ending");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_TurnInPlace, "Shared.Status.TurnInPlace");
	//***************************Game Data Tags***************************//
	UE_DEFINE_GAMEPLAY_TAG(GameData_Level_SurvivalGameModeMap, "GameData.Level.SurvivalGameModeMap");
	UE_DEFINE_GAMEPLAY_TAG(GameData_Level_MainMenuMap, "GameData.Level.MainMenuMap");
	UE_DEFINE_GAMEPLAY_TAG(GameData_SaveGame_Slot_1, "GameData.SaveGame.Slot.1");

}

