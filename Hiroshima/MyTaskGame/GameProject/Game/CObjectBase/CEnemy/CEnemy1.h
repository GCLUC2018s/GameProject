#ifndef ENEMY1GUARD
#define ENEMY1GUARD

#define DARUMA_HP 3
#define DARUMA_AT 5
#define DARUMA_SPEED 3

#define DARUMA_KNOCKBACK_SPEED 8

#include"CEnemyBase.h"
#include"../CObjectBase.h"
/*

»ìÒ@Â–Ø

*/


class CEnemy1 :public CEnemyBase {
public:
	//‚¾‚é‚Ü
	CEnemy1(const CVector3D *pos);
	void Update();
	void Nutral(); //’Êíó‘Ô
	void Move();    //ˆÚ“®ó‘Ô
	void Attack();  //UŒ‚ó‘Ô
	void KnockBack(); //‚Ì‚¯‚¼‚èó‘Ô
};




#endif // !ENEMY1GUARD