#include "ImageResource.h"

TexAnim _PL_idol[] = {
	{ 0,15 },
	{ 1,5 },
	{ 2,5 },
	{ 3,15 },
	{ 4,5 },
	{ 5,5 },
	{ 6,5 },
	{ 7,5 },
};
TexAnim _PL_bill[] = {
	{ 10,10 },
	{ 11,15 },
	{ 10,5 },
};
TexAnim _PL_punch[] = {
	{ 20,5 },
	{ 21,5 },
	{ 22,20 },
	{ 30,3 },
	{ 30,2 },
	{ 31,20 },
	{ 31,3 },
	{ 31,2 },
};
TexAnim _PL_kick[] = {
	{ 40,5 },
	{ 41,20 },
	{ 40,3 },
	{ 40,2 },
};
TexAnim _PL_damage[] = {
	{ 50,40 },
};
TexAnim _PL_fall[] = {
	{ 50,20 },
	{ 51,5 },
	{ 52,80 },
	{ 51,10 },
};
TexAnim _PL_jamp[] = {
	{ 60,5 },
	{ 61,5 },
	{ 62,5 },
};
TexAnim _PL_dash[] = {
	{ 80,5 },
	{ 81,5 },
	{ 82,5 },
	{ 83,5 },
	{ 84,5 },
	{ 85,5 },
};
TexAnim _PL_squat[] = {
	{ 90,5 },
	{ 91,5 },
};
TexAnim _PL_Deathblow[] = {
	{ 10,60 * 4 },
	{ 11,60 * 4 },
};

TexAnimData player_AnimData[] = {
	ANIMDATA(_PL_idol),
	ANIMDATA(_PL_bill),
	ANIMDATA(_PL_punch),
	ANIMDATA(_PL_kick),
	ANIMDATA(_PL_damage),
	ANIMDATA(_PL_fall),
	ANIMDATA(_PL_jamp),
	ANIMDATA(_PL_dash),
	ANIMDATA(_PL_squat),
	ANIMDATA(_PL_Deathblow),
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
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
	{ 4,5 },
	{ 5,5 },
};
TexAnimData fire_Animdata[] = {
	ANIMDATA(_GI_fire),
};

TexAnim _GI_ItemBox[] = {
	{ 0,10 },
	{ 1,10 },
};
TexAnim _GI_ItemBox2[] = {
	{ 2,10 },
};
TexAnim _GI_EnemyBox[] = {
	{ 5,10 },
	{ 6,10 },
};
TexAnim _GI_EnemyBox2[] = {
	{ 7,10 },
	{ 8,10 },
	{ 9,10 },
};
TexAnimData itembox_Animdata[] = {
	ANIMDATA(_GI_ItemBox),
	ANIMDATA(_GI_ItemBox2),
	ANIMDATA(_GI_EnemyBox),
	ANIMDATA(_GI_EnemyBox2),
};

TexAnim _GI_bill[] = {
	{ 11,5 },
	{ 12,5 },
};
TexAnimData bill_Animdata[] = {
	ANIMDATA(_GI_bill),
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
	{ 2,10 },
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
	{ 2,10 },
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


TexAnim _Boss_Head_anim[] = {
	{ 0,10 },
	{ 1,10 },
	{ 2,10 },
	{ 3,10 },
	{ 4,10 },
	{ 5,10 },
	{ 6,10 },
	{ 7,10 },
};
TexAnim _Boss_Tail_anim[] = {
	{ 8,10 },
	{ 9,10 },
	{ 10,10 },
	{ 11,10 },
	{ 12,10 },
	{ 13,10 },
	{ 14,10 },
	{ 15,10 },

};
TexAnim _Boss_Arm_anim[] = {
	{ 16,10 },
	

};

TexAnim _Boss_Arm2_anim[] = {
	{ 17,10 },
	


};



TexAnim _Boss_TailAttack_anim[] = {
	{ 24,10 },
	{ 25,10 },
	{ 26,10 },
	{ 27,10 },
	{ 27,1 },
	

};
TexAnim _Boss_Bless_anim[] = {
	{ 32,1 },
	{ 32,60*2 },
	{ 33,1 },
	{ 33,60*5 },
	{ 33,1 },


};

TexAnim _Boss_ShowerLaser_anim[] = {
	{ 40,10 },


};

TexAnim _Boss_Down_anim[] = {
	{ 48,10 },
	{ 48,10 },
	{ 48,10 },


};
TexAnimData boss_AnimData[] = {
	ANIMDATA(_Boss_Head_anim),
	ANIMDATA(_Boss_Tail_anim),
	ANIMDATA(_Boss_Arm2_anim),
	ANIMDATA(_Boss_Arm_anim),
	ANIMDATA(_Boss_TailAttack_anim),
	ANIMDATA(_Boss_Bless_anim),
	ANIMDATA(_Boss_ShowerLaser_anim),
	ANIMDATA(_Boss_Down_anim),
};


TexAnim _Attack1_anim[] = {
	{ 0,5 },
	{ 1,600 },
};
TexAnim _Attack2_anim[] = {
	{ 3,5 },
	{ 4,600 },
};

TexAnim _Attack3_anim[] = {
	{ 6,5 },
	{ 7,600 },
};


TexAnimData attack_ef_AnimData[] = {
	ANIMDATA(_Attack1_anim),
	ANIMDATA(_Attack2_anim),
	ANIMDATA(_Attack3_anim),
};

TexAnim _Aura_anim[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
	{ 4,5 },
	{ 5,5 },
	{ 6,5 },
	{ 7,5 },
	{ 8,5 },
	{ 9,5 },
};
TexAnim _MagaMax_anim[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
	{ 4,5 },
	{ 5,5 },
	{ 6,5 },
	{ 7,5 },
	{ 8,5 },
	{ 9,5 },
	{ 10,5 },
	{ 11,5 },
	{ 12,5 },
	{ 13,5 },
	{ 14,5 },
};


TexAnimData aura_ef_AnimData[] = {
	ANIMDATA(_Aura_anim),
	ANIMDATA(_MagaMax_anim),
};

TexAnim _Charge_anim[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
	{ 4,5 },
	{ 5,5 },
	{ 6,5 },
	{ 7,5 },
	{ 8,5 },
	{ 9,5 },
	{ 10,5 },
};


TexAnimData charge_ef_AnimData[] = {
	ANIMDATA(_Charge_anim),
};

TexAnim _Bress_anim[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
	{ 4,5 },
	{ 5,5 },
	{ 6,5 },
	{ 7,5 },
	{ 8,5 },
	{ 9,5 },
	{ 10,5 },
	{ 11,5 },
	{ 12,5 },
	{ 13,5 },
	{ 14,5 },
	{ 15,5 },
	{ 16,5 },
	{ 17,5 },
	{ 18,5 },
	{ 19,5 },
};


TexAnimData bress_ef_AnimData[] = {
	ANIMDATA(_Bress_anim),
};