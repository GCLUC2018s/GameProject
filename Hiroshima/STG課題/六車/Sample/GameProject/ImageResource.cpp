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
	{ 12,5 },
};

TexAnimData player_AnimData[] = {
	ANIMDATA(_PL_idol),
	ANIMDATA(_PL_dash),
	ANIMDATA(_PL_jamp),
	ANIMDATA(_PL_squat),
	ANIMDATA(_PL_punch),
};

TexAnim _ENE_anim[] = {
	{ 4,5 },
	{ 5,5 },
	{ 6,5 },
	{ 7,5 },

};
TexAnimData enemy_AnimData[] = {
	ANIMDATA(_ENE_anim),
};

