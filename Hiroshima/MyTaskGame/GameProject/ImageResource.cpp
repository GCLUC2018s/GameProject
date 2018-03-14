#include "ImageResource.h"

TexAnim _PL_idol[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
	{ 4,5 },
	{ 5,5 },
	{ 6,5 },
	{ 7,5 },
};
TexAnim _PL_dash[] = {
	{ 70,5 },
	{ 71,5 },
	{ 72,5 },
	{ 73,5 },
	{ 74,5 },
	{ 75,5 },
};
TexAnim _PL_jamp[] = {
	{ 50,5 },
	{ 51,5 },
	{ 52,5 },
};
TexAnim _PL_squat[] = {
	{ 80,5 },
	{ 81,5 },
};
TexAnim _PL_punch[] = {
	{ 20,5 },
	{ 21,5 },
	{ 22,20 },
	{ 20,10 },
};
TexAnim _PL_kick[] = {
	{ 30,5 },
	{ 31,20 },
	{ 30,5 },
};
TexAnim _PL_fall[] = {
	{ 40,5 },
	{ 41,10 },
	{ 42,10 },
};

TexAnimData player_AnimData[] = {
	ANIMDATA(_PL_idol),
	ANIMDATA(_PL_dash),
	ANIMDATA(_PL_jamp),
	ANIMDATA(_PL_squat),
	ANIMDATA(_PL_punch),
	ANIMDATA(_PL_kick),
	ANIMDATA(_PL_fall),
};

//TexAnim _ENE_anim[] = {
//	{ 0,30 },
//	{ 1,30 },
//
//};
//TexAnimData enemy_AnimData[] = {
//	ANIMDATA(_ENE_anim),
//};

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


TexAnim _KAMAITACHI_anim[] = {
	{ 0,30 },

};
TexAnim _KAMAITACHI2_anim[] = {
	{ 1,30 },

};
TexAnim _KAMAITACHI_attack_anim[] = {
	{ 4,30 },
	{ 5,30 },
	{ 5, 1},

};
TexAnim _KAMAITACHI_knockback_anim[] = {
	{ 2,30 },
	{ 2,1 },
	

};
TexAnim _KAMAITACHI_fall_anim[] = {
	{ 3,30 },
	

};
TexAnimData kamaitachi_AnimData[] = {
	ANIMDATA(_KAMAITACHI_anim),
	ANIMDATA(_KAMAITACHI2_anim),
	ANIMDATA(_KAMAITACHI_attack_anim),
	ANIMDATA(_KAMAITACHI_knockback_anim),
	ANIMDATA(_KAMAITACHI_fall_anim),
};

TexAnim _ENEMY_anim[] = {
	{ 0,30 },

};
TexAnim _ENEMY_move_anim[] = {
	{ 0,30 },
	{ 1,30 },

};
TexAnim _ENEMY_attack_anim[] = {
	{ 4,30 },
	{ 5,30 },
	{ 5, 1 },

};
TexAnim _ENEMY_knockback_anim[] = {
	{ 2,30 },
	{ 2,1 },


};
TexAnim _ENEMY_fall_anim[] = {
	{ 3,30 },


};
TexAnimData enemy_AnimData[] = {
	ANIMDATA(_ENEMY_anim),
	ANIMDATA(_ENEMY_move_anim),
	ANIMDATA(_ENEMY_attack_anim),
	ANIMDATA(_ENEMY_knockback_anim),
	ANIMDATA(_ENEMY_fall_anim),
};


TexAnim _Boss_anim[] = {
	{ 0,10 },
	{ 1,10 },
	{ 2,10 },
	{ 3,10 },
	{ 4,10 },
	{ 5,10 },
	{ 6,10 },
	{ 7,10 },
};
TexAnim _Boss2_anim[] = {
	{ 8,10 },
	{ 9,10 },
	{ 10,10 },
	{ 11,10 },
	{ 12,10 },
	{ 13,10 },
	{ 14,10 },
	{ 15,10 },

};
TexAnim _Boss3_anim[] = {
	{ 16,10 },
	

};

TexAnim _Boss4_anim[] = {
	{ 17,10 },
	


};

TexAnim _Boss5_anim[] = {
	{ 24,10 },
	{ 25,10 },
	{ 26,10 },
	{ 27,10 },


};

TexAnim _Boss6_anim[] = {
	{ 32,30 },
	{ 33,30 },

};
TexAnim _Boss7_anim[] = {
	{ 40,10 },


};

TexAnim _Boss8_anim[] = {
	{ 48,10 },


};
TexAnimData boss_AnimData[] = {
	ANIMDATA(_Boss_anim),
	ANIMDATA(_Boss2_anim),
	ANIMDATA(_Boss3_anim),
	ANIMDATA(_Boss4_anim),
	ANIMDATA(_Boss5_anim),
	ANIMDATA(_Boss6_anim),
	ANIMDATA(_Boss7_anim),
	ANIMDATA(_Boss8_anim),
};


