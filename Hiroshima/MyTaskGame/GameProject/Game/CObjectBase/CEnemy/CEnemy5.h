#ifndef ENEMY5GUARD
#define ENEMY5GUARD

//#include"../CObjectBase.h"
#include "CEnemyBase.h"

#define NIKU_HP 15
#define NIKU_AT 15
#define NIKU_SPEED 2

#define NIKU_KNOCKBACK_SPEED 8

#define NIKU_SIZ_X 384
#define NIKU_SIZ_Y 384

/*

»ìÒ@Â–Ø

*/
//“÷‰ò
class CEnemy5 :public CEnemyBase {
public:
	CEnemy5(const CVector3D *pos);
	void Update();
	void Nutral(); //’Êíó‘Ô
	void Move();    //ˆÚ“®ó‘Ô
	void Attack();  //UŒ‚ó‘Ô
	void KnockBack(); //‚Ì‚¯‚¼‚èó‘Ô
};




#endif // !ENEMY1GUARD