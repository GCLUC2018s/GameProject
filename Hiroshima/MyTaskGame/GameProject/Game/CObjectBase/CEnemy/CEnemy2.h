#ifndef ENEMY2GUARD
#define ENEMY2GUARD
//#include"../CObjectBase.h"
#include"CEnemyBase.h"

#define CHOCHIN_HP 5
#define CHOCHIN_AT 3
#define CHOCHIN_SPEED 4

#define CHOCHIN_KNOCKBACK_SPEED 8

#define CHOCHIN_FLOAT 0.3f
/*

»ìÒ@Â–Ø

*/
class CEnemy2 :public CEnemyBase {
private:
	float m_a;	//•‚—V—p
public:
	//’ñ“”
	CEnemy2(const CVector3D *pos);
	void Update();
	void Nutral(); //’Êíó‘Ô
	void Move();    //ˆÚ“®ó‘Ô
	void Attack();  //UŒ‚ó‘Ô
	void KnockBack(); //‚Ì‚¯‚¼‚èó‘Ô
};




#endif // !ENEMY4GUARD
