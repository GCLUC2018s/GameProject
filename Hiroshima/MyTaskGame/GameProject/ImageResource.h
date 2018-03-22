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
	eAnimDeathblow,
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
	eAnimBossDown,
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
//pipo-mapeffect013a-1.png�̃A�j���[�V�����f�[�^
extern TexAnimData aura_ef_AnimData[];
//�`���[�W�̃A�j���[�V�����f�[�^
extern TexAnimData charge_ef_AnimData[];
//�u���X�̃A�j���[�V�����f�[�^
extern TexAnimData bress_ef_AnimData[];
//�r�[���̃A�j���[�V�����f�[�^
extern TexAnimData beam_ef_AnimData[];

#endif // !IMAGE_RESOURCE_GUARD