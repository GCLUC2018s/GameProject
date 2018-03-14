#ifndef IMAGE_RESOURCE_GUARD
#define IMAGE_RESOURCE_GUARD

#include "stdafx.h"
//!�A�j���[�V�����̎��
enum  {
	eAnimIdol,
	eAnimDash,
	eAnimJamp,
	eAnimSquat,
	eAnimPunch,
	eAnimKick,
	eAnimFall,
	eAnimKamaMove = 1,
	eAnimKamaAttack,
	eAnimKamaKnockBack,
	eAnimKamaFall,
	eAnimEnemyMove = 1,
	eAnimEnemyAttack,
	eAnimEnemyKnockBack,
	eAnimEnemyFall,
};
//player.png�̃A�j���[�V�����f�[�^
extern TexAnimData player_AnimData[];
//Enemy.png�̃A�j���[�V�����f�[�^
extern TexAnimData enemy_AnimData[];
//fire.png�̃A�j���[�V�����f�[�^
extern TexAnimData fire_Animdata[];
//zako_kamaitachi_motion.png�̃A�j���[�V�����f�[�^
extern TexAnimData kamaitachi_AnimData[];
//zako_kamaitachi_motion.png�̃A�j���[�V�����f�[�^
extern TexAnimData boss_AnimData[];

#endif // !IMAGE_RESOURCE_GUARD