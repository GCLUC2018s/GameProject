#ifndef IMAGE_RESOURCE_GUARD
#define IMAGE_RESOURCE_GUARD

#include "stdafx.h"
//!�A�j���[�V�����̎��
enum  {
	eAnimIdol,
	eAnimBill,
	eAnimPunch,
	eAnimKick,
	eAnimDamage,
	eAnimFall,
	eAnimJamp,
	eAnimDash,
	eAnimSquat,
	eAnimKamaMove = 1,
	eAnimKamaAttack,
	eAnimKamaKnockBack,
	eAnimKamaFall,
	eAnimEnemyMove = 1,
	eAnimEnemyAttack,
	eAnimEnemyKnockBack,
	eAnimEnemyFall,
	eAnimBossHeadIdol = 0,
	eAnimBossTailIdol,
	eAnimBossArm2Idol,
	eAnimBossArmIdol,
	eAnimBossTailAttack,
	eAnimBossBless,
	eAnimBossShowerLaser,
	eAnimBOssDown,
	eAnimEffectAttack1 = 0,
	eAnimEffectAttack2,
	eAnimEffectAttack3,
};
//player.png�̃A�j���[�V�����f�[�^
extern TexAnimData player_AnimData[];
//Enemy.png�̃A�j���[�V�����f�[�^
extern TexAnimData enemy_AnimData[];
//fire.png�̃A�j���[�V�����f�[�^
extern TexAnimData fire_Animdata[];
//itembox.png�̃A�j���[�V�����f�[�^
extern TexAnimData itembox_Animdata[];
//bill.png�̃A�j���[�V�����f�[�^
extern TexAnimData bill_Animdata[];
//zako_kamaitachi_motion.png�̃A�j���[�V�����f�[�^
extern TexAnimData kamaitachi_AnimData[];
//zako_kamaitachi_motion.png�̃A�j���[�V�����f�[�^
extern TexAnimData boss_AnimData[];
//motion_effect.png�̃A�j���[�V�����f�[�^
extern TexAnimData attack_ef_AnimData[];

#endif // !IMAGE_RESOURCE_GUARD