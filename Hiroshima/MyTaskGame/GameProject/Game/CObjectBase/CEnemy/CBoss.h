#ifndef BOSSGUARD
#define BOSSGUARD

#define BOSS_HP 100
#define BOSS_AT 20
#define BOSS_SPEED 5

#include"../CObjectBase.h"
/*

����ҁ@��

*/
class CBoss :public CObjectBase {
public:
	CBoss(CVector3D *pos);
	~CBoss();
	void Update();
};




#endif // !EBEMY1GUARD
