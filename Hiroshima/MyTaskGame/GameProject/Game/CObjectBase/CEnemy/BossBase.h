#ifndef BOSSBASEGUARD
#define BOSSBASEGUARD

//�{�X�̊e���ʂ̃T�C�Y
#define BOSS_SIZ_X 384
#define BOSS_SIZ_Y 384

//�m�b�N�o�b�N���鑬�x
#define KNOCKBACK_SPEED 8

#include "../GameProject/GAME/CObjectBase/CObjectBase.h"


//�����ł̓{�X�S�̂ɋ��ʂ�����̂�����

class CBossBase : public CObjectBase
{
protected:
	bool m_damage;
	bool m_end_flag;
	CAnimImage m_head;
	CAnimImage m_arm;
	CAnimImage m_arm2;
	CAnimImage m_tail;
	CVector3D m_headpos3D;
	CVector3D m_armpos3D;
	CVector3D m_arm2pos3D;
	CVector3D m_tailpos3D;
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

