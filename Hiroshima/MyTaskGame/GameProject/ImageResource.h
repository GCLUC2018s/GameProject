#ifndef IMAGE_RESOURCE_GUARD
#define IMAGE_RESOURCE_GUARD

#include "stdafx.h"
//!アニメーションの種類
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
//player.pngのアニメーションデータ
extern TexAnimData player_AnimData[];
//Enemy.pngのアニメーションデータ
extern TexAnimData enemy_AnimData[];
//fire.pngのアニメーションデータ
extern TexAnimData fire_Animdata[];
//itembox.pngのアニメーションデータ
extern TexAnimData itembox_Animdata[];
//bill.pngのアニメーションデータ
extern TexAnimData bill_Animdata[];
//zako_kamaitachi_motion.pngのアニメーションデータ
extern TexAnimData kamaitachi_AnimData[];
//zako_kamaitachi_motion.pngのアニメーションデータ
extern TexAnimData boss_AnimData[];
//motion_effect.pngのアニメーションデータ
extern TexAnimData attack_ef_AnimData[];

#endif // !IMAGE_RESOURCE_GUARD