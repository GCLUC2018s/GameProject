#ifndef ENEMYBASEGUARD
#define ENEMYBASEGUARD

//敵のサイズ
#define ENEMY_SIZ_X 213
#define ENEMY_SIZ_Y 256

//ノックバックする速度
#define KNOCKBACK_SPEED 8

#include "../GameProject/GAME/CObjectBase/CObjectBase.h"
#include "../GameProject/stdafx.h"

//此処ではエネミー全体（ボスを除く）に共通するものを書く

class CEnemyBase : public CObjectBase
{
protected:
	bool m_damage;
	bool m_end_flag;
	enum {
		eDaruma,
		eChouchin,
		eHi,
		eKamaitachi,
		eNiku,
	};
public:
	CEnemyBase();
	void DropItem();
	void Nutral(const int *enemy_id);
	void Move(const int *enemy_id);
	void Attack(const int *enemy_id);
	void KnockBack(const int *enemy_id);
	void Fall(const int *enemy_id);
	void Damage(const int *enemy_id);
	void Draw();
};

#endif // !ENEMYBASEGUARD

