#ifndef ENEMY3GUARD
#define ENEMY3GUARD
//#include"../CObjectBase.h"
#include"CEnemyBase.h"

#define HI_HP 3
#define HI_AT 7
#define HI_SPEED 5

#define HI_KNOCKBACK_SPEED 8

#define HI_FLOAT 0.1f
/*

»ìÒ@Â–Ø

*/
class CEnemy3 :public CEnemyBase {
private:
	float m_a;	//•‚—V—p
public:
	//‰Î‚Ì‹Ê
	CEnemy3(const CVector3D *pos);
	void Update();
	void Nutral(); //’Êíó‘Ô
	void Move();    //ˆÚ“®ó‘Ô
	void Attack();  //UŒ‚ó‘Ô
	void KnockBack(); //‚Ì‚¯‚¼‚èó‘Ô
};




#endif // !ENEMY3GUARD
