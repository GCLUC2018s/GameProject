#ifndef ENEMYBASEGUARD
#define ENEMYBASEGUARD

//�G�̃T�C�Y
#define ENEMY_SIZ_X 213
#define ENEMY_SIZ_Y 256

//�m�b�N�o�b�N���鑬�x
#define KNOCKBACK_SPEED 8

#include "../GameProject/GAME/CObjectBase/CObjectBase.h"


//�����ł̓G�l�~�[�S�́i�{�X�������j�ɋ��ʂ�����̂�����


class CEnemyBase : public CObjectBase
{
protected:
	static 	int m_enemy_cnt;
	bool m_damage;
	bool m_end_flag;
	CVector2D damage_vec;
	enum {
		eDaruma,
		eChouchin,
		eHi,
		eKamaitachi,
		eNiku,
	};
public:
	CEnemyBase();
	~CEnemyBase();
	CVector3D Blow(CVector3D vec);
	void DropItem();
	void Nutral(const int *enemy_id);
	void Move(const int *enemy_id);
	void Attack(const int *enemy_id);
	void KnockBack(const int *enemy_id);
	void Fall();
	void Damage();
	void Draw();
	void Hit(CObjectBase * t);
};

#endif // !ENEMYBASEGUARD

