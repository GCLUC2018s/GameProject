#pragma once
#include "stdafx.h"
enum {
	eImagePlayer,
	eImageEnemy01,
	eImageMap,
	eImageBackGround,
	eImageBullet,
	eImageItem,
	eImageNumber,
	eImageFlag,
	eImageClear,
	eImageEffect,
	eImageEffectBomb,
	eImageEffectSlash,
	eImageEffectBlood,
	eImageEffectShotHit,
	eImageEffectSmoke,
	eImageMax
};
extern CImage g_image[eImageMax];

//!アニメーションの種類
enum  {
	eAnimIdle,
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
//player.pngのアニメーションデータ
extern TexAnimData enemy01AnimData[];
//enemy01.pngのアニメーションデータ
extern TexAnimData playerAnimData[];
//Effect_Bomb.pngのアニメーションデータ
extern TexAnimData Effect_Bomb_AnimData[];
//Bullet.pngのアニメーションデータ
extern TexAnimData bullet_anim_Data[];
//Item.pngのアニメーションデータ
extern TexAnimData Item01AnimData[];
//Effect_Slash.pngのアニメーションデータ
extern TexAnimData Effect_Slash_AnimData[];
//Effect_Blood.pngのアニメーションデータ
extern TexAnimData Effect_Blood_AnimData[];
//Effect_ShotHit.pngのアニメーションデータ
extern TexAnimData Effect_ShotHit_AnimData[];
//Effect_Smoke.pngのアニメーションデータ
extern TexAnimData Effect_Smoke_AnimData[];