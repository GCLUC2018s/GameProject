#ifndef IMAGE_RESOURCE_GUARD
#define IMAGE_RESOURCE_GUARD

#include "stdafx.h"
//!アニメーションの種類
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
//player.pngのアニメーションデータ
extern TexAnimData player_AnimData[];
//Enemy.pngのアニメーションデータ
extern TexAnimData enemy_AnimData[];
//fire.pngのアニメーションデータ
extern TexAnimData fire_Animdata[];
//zako_kamaitachi_motion.pngのアニメーションデータ
extern TexAnimData kamaitachi_AnimData[];
//zako_kamaitachi_motion.pngのアニメーションデータ
extern TexAnimData boss_AnimData[];

#endif // !IMAGE_RESOURCE_GUARD