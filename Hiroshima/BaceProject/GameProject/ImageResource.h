#pragma once
#include "stdafx.h"
enum {
	eImageArrowDoor,
	eImageArrowDown,
	eImageArrowLeft,
	eImageArrowUp,
	eImageBackGround1,
	eImageBackGround2,
	eImageBackGround3,
	eImageBackGround4,
	eImageBackGround5,
	eImageBackGround6,
	eImageBackGround7,
	eImageBlack,
	eImageBlackLight,
	eImageBullet,
	eImageButton,
	eImageClear,
	eImageEffect,
	eImageEffectBlood,
	eImageEffectBomb,
	eImageEffectShotHit,
	eImageEffectSlash,
	eImageEffectSmoke,
	eImageEnemy01,
	eImageFlag,
	eImageHollyWater,
	eImageItem,
	eImageLifeScreen,
	eImageMark,
	eImageMap,
	eImageNumber,
	eImagePanel,
	eImagePlayer,
	eImageShutter,
	eImageTitle,
	eImageWater,
	eImageWord1,
	eImageMax
};
extern CImage g_image[eImageMax];

//!�A�j���[�V�����̎��
enum  {
	eAnimIdle = 0,
	eAnimRun,
	eAnimJumpUp,
	eAnimJumpDown,
	eAnimAttack01,
	eAnimAttack01End,
	eAnimAttack02,
	eAnimAttack02End,
	eAnimAttack03,
	eAnimAttack03End,
	eAnimDamage,
	eAnimDamageEnd,
	eAnimDeath,
	eAnimDown,
	eAnimDownGround,
	eAnimWakeUp,
	eAnimGuard,
	eAnimGuardEnd,
	eAnimCrash,
	eAnimCrashEnd,
	eAnimExtAttack01,
	eAnimExtAttack01End,
	eAnimExtAttack02,
	eAnimExtAttack02End,
	eAnimStep,
};
//Arrow�̃A�j���[�V�����f�[�^
extern TexAnimData Arrow_AnimData[];
//Bullet.png�̃A�j���[�V�����f�[�^
extern TexAnimData bullet_anim_Data[];
//Effect_Blood.png�̃A�j���[�V�����f�[�^
extern TexAnimData Effect_Blood_AnimData[];
//Effect_Bomb.png�̃A�j���[�V�����f�[�^
extern TexAnimData Effect_Bomb_AnimData[];
//Effect_ShotHit.png�̃A�j���[�V�����f�[�^
extern TexAnimData Effect_ShotHit_AnimData[];
//Effect_Slash.png�̃A�j���[�V�����f�[�^
extern TexAnimData Effect_Slash_AnimData[];
//Effect_Smoke.png�̃A�j���[�V�����f�[�^
extern TexAnimData Effect_Smoke_AnimData[];
//player.png�̃A�j���[�V�����f�[�^
extern TexAnimData playerAnimData[];
//Item.png�̃A�j���[�V�����f�[�^
extern TexAnimData Item01AnimData[];
//Mark.png�̃A�j���[�V�����f�[�^
extern TexAnimData Mark_AnimData[];
//panel.png�̃A�j���[�V�����f�[�^
extern TexAnimData Panel_AnimData[];
//enemy.png�̃A�j���[�V�����f�[�^
extern TexAnimData enemy01AnimData[];