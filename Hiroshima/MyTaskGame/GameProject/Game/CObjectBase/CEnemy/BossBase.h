#ifndef BOSSBASEGUARD
#define BOSSBASEGUARD

//ボスの各部位のサイズ
#define BOSS_SIZ_X 500
#define BOSS_SIZ_Y 500

//ノックバックする速度
#define KNOCKBACK_SPEED 8

#define BOSS_FLOAT_HEAD 0.1f
#define BOSS_FLOAT_ARM 0.02f
#define BOSS_FLOAT_TAIL 0.01f

#define BOSS_DOWN_SPEED 0.01f

#define BOSS_POS_Y 0 
#define BOSS_POS_DOWN_Y 200  

#define BOSS_DOWN_TIME  200

#include "../GameProject/GAME/CObjectBase/CObjectBase.h"


//此処ではボス全体に共通するものを書く

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
	CVector3D m_headvec3D;
	CVector3D m_armvec3D;
	CVector3D m_arm2vec3D;
	CVector3D m_tailvec3D;
	CVector3D m_playervec;
	float m_shaking_head;
	float m_shaking_arm;
	float m_shaking_tail;
	int m_parts_head;
	int m_parts_arm;
	int m_parts_arm2;
	int m_parts_tail;
	enum {
		eHead,
		eArm,
		eArm2,
		eTail,
	};
	CVector3D m_headoldpos3D;
	CVector3D m_armoldpos3D;
	CVector3D m_arm2oldpos3D;
	CVector3D m_tailoldpos3D;
	bool m_down;
	int m_downtime;
	CRect m_headrect;
	CRect m_armrect;
	CRect m_arm2rect;
	CRect m_tailrect;
public:
	CBossBase();
	void Nutral(int boss_id);
	void Move(int boss_id);
	void Attack(int boss_id);
	void Fall();
	void Damage(int boss_id);
	void Down(int boss_id);
	void Draw();
	void Hit(CObjectBase * t);
	void BossBress();
	void BossJump();
	void BossDescent();
	void BossLaser();
	//重なり確認
	void BossCheckOverlap() {
		if (m_headpos3D.z <= 0) {
			CTaskManager::GetInstance()->ChangeDrawPrio(this, SCREEN_HEIGHT + m_headpos3D.z);
		}

		if (m_armpos3D.z <= 0) {
			CTaskManager::GetInstance()->ChangeDrawPrio(this, SCREEN_HEIGHT + m_armpos3D.z);
		}

		if (m_arm2pos3D.z <= 0) {
			CTaskManager::GetInstance()->ChangeDrawPrio(this, SCREEN_HEIGHT + m_arm2pos3D.z);
		}

		if (m_tailpos3D.z <= 0) {
			CTaskManager::GetInstance()->ChangeDrawPrio(this, SCREEN_HEIGHT + m_tailpos3D.z);
		}
	}
private:
	enum {
		eIdol,
		eMove,
		eBlessAttack,
		eTailAttack,
		eBress,
		eLaserShower,
		eDown,
		eDamage,
		eFall,
		eJump,
		eDescent,
	};
};

#endif // !BOSSBASEGUARD

