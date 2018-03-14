#ifndef BOSSGUARD
#define BOSSGUARD

#define BOSS_HP 100
#define BOSS_AT 20
#define BOSS_SPEED 5

#include"../CObjectBase.h"
/*

製作者　青木

*/

/*
宮﨑：
テスト作成しただけのクラスです
このコメントは、実際作り出したら消してね
*/
class CBoss :public CObjectBase {
protected:
	int m_test;
public:
	CBoss(CVector3D *pos);
	~CBoss();
	void Update();
};




#endif // !EBEMY1GUARD
