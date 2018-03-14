#ifndef ENEMY1GUARD
#define ENEMY1GUARD

#define DARUMA_HP 10
#define DARUMA_AT 5
#define DARUMA_SPEED 3

#include"../CObjectBase.h"
#include"CEnemyBase.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//ÇæÇÈÇ‹
class CEnemy1 :public CEnemyBase {
public:
	CEnemy1(const CVector3D *pos);
	~CEnemy1();
	void Update();
};




#endif // !ENEMY1GUARD