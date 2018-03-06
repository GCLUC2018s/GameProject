#ifndef IMAGE_RESOURCE_GUARD
#define IMAGE_RESOURCE_GUARD

#include "stdafx.h"
//!アニメーションの種類
enum  {
	eAnimUp,
	eAnimDown,
	eAnimLeft,
	eAnimRight,
};
//player.pngのアニメーションデータ
extern TexAnimData player_AnimData[];
//Enemy.pngのアニメーションデータ
extern TexAnimData enemy_AnimData[];
//fire.pngのアニメーションデータ
extern TexAnimData fire_Animdata[];

#endif // !IMAGE_RESOURCE_GUARD