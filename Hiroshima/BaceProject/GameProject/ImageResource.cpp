#include "ImageResource.h"

CImage g_image[eImageMax];


static TexAnim playerIdle[] = {
	{ 0,32 },
	{ 1,16 },
	{ 2,16 },
	{ 1,16 },
};
static TexAnim playerRun[] = {
	{ 16,8 },
	{ 17,8 },
	{ 18,8 },
	{ 19,8 },
	{ 20,8 },
	{ 21,8 },
	{ 22,8 },
	{ 23,8 },
};
static TexAnim playerJumpUp[] = {
	{ 32,8 },
	{ 33,8 },
	{ 34,8 },
	{ 35,8 },

};
static TexAnim playerJumpDown[] = {
	{ 36,8 },
	{ 37,8 },
	{ 38,8 },

};
static TexAnim playerAttack01[] = {
	{ 40,3 },
	{ 41,3 },
	{ 42,3 },
	{ 43,2 },
	{ 44,2 },
	{ 45,3 },
	{ 46,4 },
};
static TexAnim playerAttack01End[] = {
	{ 48,4 },
	{ 49,4 },
	{ 50,4 },
	{ 51,4 },
	{ 52,4 },
};
static TexAnim playerAttack02[] = {
	{ 56,6 },
	{ 57,6 },
	{ 58,4 },
	{ 59,2 },
	{ 60,2 },
	{ 61,2 },
	{ 62,4 },
};
static TexAnim playerAttack02End[] = {
	{ 64,4 },
	{ 65,4 },
	{ 66,4 },
	{ 67,4 },
	{ 68,4 },
};
static TexAnim playerAttack03[] = {
	{ 72,6 },
	{ 73,6 },
	{ 74,4 },
	{ 75,4 },
	{ 76,3 },
	{ 77,2 },
	{ 78,2 },
	{ 79,4 },
};
static TexAnim playerAttack03End[] = {
	{ 80,4 },
	{ 81,4 },
	{ 82,4 },
	{ 83,4 },
};

static TexAnim playerDamage[] = {
	{ 88,2 },
	{ 89,2 },
	{ 90,2 },
	{ 91,2 },
};
static TexAnim playerDamageEnd[] = {
	{ 92,2 },
	{ 93,2 },
	{ 94,2 },
	{ 95,2 },
};
static TexAnim playerDeath[] = {
	{ 48,8 },
	{ 49,8 },
	{ 50,8 },
	{ 51,8 },
	{ 52,8 },
	{ 53,8 },
	{ 54,8 },
	{ 55,8 },
};

static TexAnim playerDown[] = {
	{ 104,4 },
	{ 105,4 },
	{ 106,4 },
	{ 107,4 },
	{ 108,4 },
};
static TexAnim playerDownGround[] = {
	{ 109,4 },
	{ 110,4 },
	{ 111,4 },
};
static TexAnim playerWakeup[] = {
	{ 112,4 },
	{ 113,4 },
	{ 114,4 },
	{ 115,4 },
	{ 116,4 },
	{ 117,4 },
	{ 118,4 },
};
static TexAnim playerGuard[] = {
	//	{ 120,4 },
	//	{ 121,4 },
	{ 122,4 },
};
static TexAnim playerGuardEnd[] = {
	{ 122,4 },
	{ 121,4 },
	{ 120,4 },
};
static TexAnim playerCrash[] = {
	{ 128,4 },
	{ 129,4 },
	{ 130,4 },
	{ 131,90 },
};
static TexAnim playerCrash01End[] = {
	{ 131,4 },
	{ 130,4 },
	{ 129,4 },
	{ 128,4 },
};
static TexAnim playerExtAttack01[] = {
	{ 144,4 },
	{ 145,4 },
	{ 146,12 },
	{ 147,2 },
	{ 148,2 },
	{ 149,2 },
	{ 150,16 },
};
static TexAnim playerExtAttack01End[] = {
	{ 151,4 },
	{ 152,4 },
};
static TexAnim playerExtAttack02[] = {
	{ 160,2 },
	{ 161,2 },
	{ 162,2 },
	{ 163,2 },
	{ 164,2 },
	{ 165,2 },
	{ 166,2 },
	{ 167,2 },
	{ 168,2 },
};
static TexAnim playerExtAttack02End[] = {
	{ 169,16 },
	{ 170,4 },
	{ 171,4 },
};
static TexAnim playerStep[] = {
	{ 120,4 },
	{ 121,4 },
	{ 122,4 },
};
TexAnimData playerAnimData[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerAttack01),
	ANIMDATA(playerAttack01End),
	ANIMDATA(playerAttack02),
	ANIMDATA(playerAttack02End),
	ANIMDATA(playerAttack03),
	ANIMDATA(playerAttack03End),
	ANIMDATA(playerDamage),
	ANIMDATA(playerDamageEnd),
	ANIMDATA(playerDeath),
	ANIMDATA(playerDown),
	ANIMDATA(playerDownGround),
	ANIMDATA(playerWakeup),
	ANIMDATA(playerGuard),
	ANIMDATA(playerGuardEnd),
	ANIMDATA(playerCrash),
	ANIMDATA(playerCrash01End),
	ANIMDATA(playerExtAttack01),
	ANIMDATA(playerExtAttack01End),
	ANIMDATA(playerExtAttack02),
	ANIMDATA(playerExtAttack02End),
	ANIMDATA(playerStep),
};

static TexAnim enemy01Idle[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
	{ 5,2 },
	{ 6,2 },
	{ 7,2 },
	{ 8,2 },
	{ 9,2 },
	{ 10,2 },
	{ 11,2 },
	{ 12,2 },
	{ 13,2 },
	{ 14,2 },
};
static TexAnim enemy01Run[] = {
	{ 16,2 },
	{ 17,2 },
	{ 18,2 },
	{ 19,2 },
	{ 20,2 },
	{ 21,2 },
	{ 22,2 },
	{ 23,2 },
	{ 24,2 },
	{ 25,2 },
	{ 26,2 },
	{ 27,2 },
	{ 28,2 },
	{ 29,2 },
	{ 30,2 },
};
static TexAnim enemy01JumpUp[] = {
	{ 0,0 },
};
static TexAnim enemy01JumpDown[] = {
	{ 0,0 },
};

static TexAnim enemy01Attack01[] = {
	{ 40,4 },
	{ 41,4 },
	{ 42,4 },
	{ 43,8 },
	{ 44,2 },
	{ 45,3 },
	{ 46,3 },
	{ 47,3 },
};
static TexAnim enemy01Attack01End[] = {
	{ 48,2 },
	{ 49,2 },
	{ 50,2 },
	{ 51,2 },
	{ 52,2 },
};
static TexAnim enemy01Attack02[] = {
	{ 0,0 },
};
static TexAnim enemy01Attack02End[] = {
	{ 0,0 },
};
static TexAnim enemy01Attack03[] = {
	{ 0,0 },
};
static TexAnim enemy01Attack03End[] = {
	{ 0,0 },
};
static TexAnim enemy01Damage[] = {
	{ 88,2 },
	{ 89,2 },
	{ 90,2 },
	{ 91,2 },
};
static TexAnim enemy01DamageEnd[] = {
	{ 92,2 },
	{ 93,2 },
	{ 94,2 },
	{ 95,2 },
};
static TexAnim enemy01Death[] = {
	{ 96,4 },
	{ 97,4 },
	{ 98,8 },
	{ 99,4 },
	{ 100,4 },
	{ 101,4 },
	{ 102,4 },
	{ 103,4 },
};

static TexAnim enemy01Down[] = {
	{ 104,4 },
	{ 105,4 },
	{ 106,4 },
	{ 107,4 },
	{ 108,4 },
};
static TexAnim enemy01DownGround[] = {
	{ 109,4 },
	{ 110,4 },
	{ 111,4 },
};
static TexAnim enemy01Wakeup[] = {
	{ 112,4 },
	{ 113,4 },
	{ 114,4 },
	{ 115,4 },
	{ 116,4 },
	{ 117,4 },
	{ 118,4 },
};
static TexAnim enemy01Guard[] = {
	{ 0,4 },
};
static TexAnim enemy01GuardEnd[] = {
	{ 0,4 },
};
static TexAnim enemy01Crash[] = {
	{ 128,4 },
	{ 129,4 },
	{ 130,4 },
	{ 131,60 },
};
static TexAnim enemy01Crash01End[] = {
	{ 131,4 },
	{ 130,4 },
	{ 129,4 },
	{ 128,4 },
};
static TexAnim enemy01Ext01Attack[] = {
	{ 0,4 },
};
static TexAnim enemy01ExtAttack01End[] = {
	{ 0,4 },
};
TexAnimData enemy01AnimData[] = {
	ANIMDATA(enemy01Idle),
	ANIMDATA(enemy01Run),
	ANIMDATA(enemy01JumpUp),
	ANIMDATA(enemy01JumpDown),
	ANIMDATA(enemy01Attack01),
	ANIMDATA(enemy01Attack01End),
	ANIMDATA(enemy01Attack02),
	ANIMDATA(enemy01Attack02End),
	ANIMDATA(enemy01Attack03),
	ANIMDATA(enemy01Attack03End),
	ANIMDATA(enemy01Damage),
	ANIMDATA(enemy01DamageEnd),
	ANIMDATA(enemy01Death),
	ANIMDATA(enemy01Down),
	ANIMDATA(enemy01DownGround),
	ANIMDATA(enemy01Wakeup),
	ANIMDATA(enemy01Guard),
	ANIMDATA(enemy01GuardEnd),
	ANIMDATA(enemy01Crash),
	ANIMDATA(enemy01Crash01End),
	ANIMDATA(enemy01Ext01Attack),
	ANIMDATA(enemy01ExtAttack01End),
};

static TexAnim EffectBomb[] = {
	{ 0,3 },
	{ 1,3 },
	{ 2,3 },
	{ 3,3 },
	{ 4,3 },
};
TexAnimData Effect_Bomb_AnimData[] = {
	ANIMDATA(EffectBomb),
};

static TexAnim EffectSlash[] = {
	{ 0,3 },
	{ 1,3 },
	{ 2,3 },
	{ 3,3 },
	{ 4,3 },
};
TexAnimData Effect_Slash_AnimData[] = {
	ANIMDATA(EffectSlash),
};

static TexAnim EffectBlood[] = {
	{ 0,3 },
	{ 1,3 },
	{ 2,3 },
	{ 3,3 },
	{ 4,3 },
};
TexAnimData Effect_Blood_AnimData[] = {
	ANIMDATA(EffectBlood),
};

static TexAnim EffectShotHit[] = {
	{ 0,3 },
	{ 1,3 },
	{ 2,3 },
};
TexAnimData Effect_ShotHit_AnimData[] = {
	ANIMDATA(EffectShotHit),
};

static TexAnim EffectSmoke[] = {
	{ 0,3 },
	{ 1,3 },
	{ 2,3 },
	{ 3,3 },
	{ 4,3 },
};
TexAnimData Effect_Smoke_AnimData[] = {
	ANIMDATA(EffectSmoke),
};
static TexAnim EffectItem[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 2,2 },
	{ 1,2 },
};
TexAnimData Item01AnimData[] = {
	ANIMDATA(EffectItem),
};

static TexAnim _bullet1[] = {
	{ 0,4 },
	{ 1,4 },
};
static TexAnim _bullet2[] = {
	{ 18,4 },
	{ 19,4 },
};

TexAnimData bullet_anim_Data[] = {
	ANIMDATA(_bullet1),
	ANIMDATA(_bullet2),
};

static TexAnim Arrow_Down[] = {
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
};
static TexAnim Arrow_Up[] = {
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
};
TexAnimData Arrow_AnimData[] = {
	ANIMDATA(Arrow_Down),
	ANIMDATA(Arrow_Up),
};
static TexAnim _mark[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
};
TexAnimData Mark_AnimData[] = {
	ANIMDATA(_mark),
};

static TexAnim _panel[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,8 },
	{ 3,2 },
	{ 4,2 },
	{ 5,4 },
	{ 6,2 },
	{ 7,4 },
};
TexAnimData Panel_AnimData[] = {
	ANIMDATA(_panel),
};