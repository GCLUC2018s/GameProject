#include "ImageResource.h"

TexAnim _PL_idol[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
};
TexAnim _PL_dash[] = {
	{ 35,5 },
	{ 36,5 },
	{ 37,5 },
	{ 38,5 },
};
TexAnim _PL_jamp[] = {
	{ 25,5 },
	{ 26,5 },
	{ 27,5 },
};
TexAnim _PL_squat[] = {
	{ 41,5 },
	{ 42,5 },
};
TexAnim _PL_punch[] = {
	{ 10,5 },
	{ 11,5 },
	{ 12,15 },
	{ 10,5 },
};

TexAnimData player_AnimData[] = {
	ANIMDATA(_PL_idol),
	ANIMDATA(_PL_dash),
	ANIMDATA(_PL_jamp),
	ANIMDATA(_PL_squat),
	ANIMDATA(_PL_punch),
};

TexAnim _ENE_anim[] = {
	{ 0,30 },
	{ 1,30 },

};
TexAnimData enemy_AnimData[] = {
	ANIMDATA(_ENE_anim),
};

TexAnim _GI_fire[] = {
	{ 0,1 },
	{ 1,1 },
	{ 2,1 },
	{ 3,1 },
	{ 4,1 },
	{ 5,1 },
	{ 6,1 },
	{ 7,1 },
	{ 8,1 },
	{ 9,1 },
	{ 10,1 },
	{ 11,1 },
	{ 12,1 },
	{ 13,1 },
	{ 14,1 },
	{ 15,1 },
	{ 16,1 },
	{ 17,1 },
	{ 18,1 },
	{ 19,1 },
	{ 20,1 },
	{ 21,1 },
	{ 22,1 },
	{ 23,1 },
	{ 24,1 },
	{ 25,1 },
	{ 26,1 },
	{ 27,1 },
	{ 28,1 },
	{ 29,1 },
	{ 30,1 },
	{ 31,1 },
	{ 32,1 },
	{ 33,1 },
	{ 34,1 },
	{ 35,1 },
	{ 36,1 },
	{ 37,1 },
	{ 38,1 },
	{ 39,1 },
	{ 40,1 },
	{ 41,1 },
	{ 42,1 },
	{ 43,1 },
	{ 44,1 },
	{ 45,1 },
	{ 46,1 },
	{ 47,1 },
	{ 48,1 },
};
TexAnimData fire_Animdata[] = {
	ANIMDATA(_GI_fire),
};