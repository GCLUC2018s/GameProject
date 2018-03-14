#ifndef ENEMY5GUARD
#define ENEMY5GUARD

//#include"../CObjectBase.h"
#include "CEnemyBase.h"

#define NIKU_HP 20
#define NIKU_AT 20
#define NIKU_SPEED 2
/*

»ìÒ@Â–Ø

*/
//“÷‰ò
class CEnemy5 :public CEnemyBase {
public:
	CEnemy5(CVector3D *pos);
	~CEnemy5();
	void Update();
};




#endif // !ENEMY1GUARD