#include "ImageResource.h"

CImage g_image[eImageMax];


static TexAnim playerIdle[] = {
	{ 0,2 },
	{ 1,2 },
};
TexAnimData playerAnimData[] = {
	ANIMDATA(playerIdle),
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
	{ 0,8 },
	{ 1,8 },
	{ 2,8 },
	{ 3,8 },
	{ 4,8 },
	{ 5,8 },
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