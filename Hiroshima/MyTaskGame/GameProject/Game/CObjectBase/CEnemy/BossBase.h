#ifndef BOSSBASEGUARD
#define BOSSBASEGUARD

//ボスの各部位のサイズ
#define BOSS_SIZ_X 213
#define ENEMY_SIZ_Y 256

//ノックバックする速度
#define KNOCKBACK_SPEED 8

#include "../GameProject/GAME/CObjectBase/CObjectBase.h"


//此処ではボス全体に共通するものを書く

class CBossBase : public CObjectBase
{
protected:
	bool m_damage;
	bool m_end_flag;
	enum {
		eHead,
		eArm,
		eArm2,
		eTail,
	};
public:
	CBossBase();
	void Nutral(const int *boss_id);
	void Move(const int *boss_id);
	void Attack(const int *boss_id);
	void KnockBack(const int *boss_id);
	void Fall(const int *boss_id);
	void Damage(const int *boss_id);
	void Draw();
};

#endif // !BOSSBASEGUARD

