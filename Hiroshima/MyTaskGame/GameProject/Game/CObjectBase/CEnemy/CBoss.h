#ifndef BOSSGUARD
#define BOSSGUARD

#define BOSS_HP 100
#define BOSS_AT 20
#define BOSS_SPEED 5

//#include"../CObjectBase.h"
#include"BossBase.h"
/*

êªçÏé“Å@ê¬ñÿ

*/


class CBoss :public CBossBase {
protected:
	int m_test;
	int m_motiontest;
public:
	CBoss(const CVector3D *headpos, const CVector3D *armpos, const CVector3D *arm2pos, const CVector3D *tailpos);
	~CBoss();
	void Update();
	void Draw();
	void Head();
	void Arm();
	void Arm2();
	void Tail();
	void AttackPattern();

};




#endif // !BOSSGUARD
