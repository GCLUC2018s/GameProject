#ifndef ENEMY4GUARD
#define ENEMY4GUARD
//#include"../CObjectBase.h"
#include  "CEnemyBase.h"

#define KAMAITACHI_HP 7
#define KAMAITACHI_AT 10
#define KAMAITACHI_SPEED 20

#define KAMAITACHI_KNOCKBACK_SPEED 8

#define KAMAITACHI_FLOAT 0.1f

#define KAMAITACHI_MOVE_TIME 130
#define KAMAITACHI_STOP_TIME 30
/*

»ìÒ@Â–Ø

*/
class CEnemy4 :public CEnemyBase {
private:
	float m_a;
	int m_cnt;
	int m_move_cnt;
	bool m_stop;
public:
	//‚©‚Ü‚¢‚½‚¿
	CEnemy4(const CVector3D *pos);
	void Update();
	void Nutral(); //’Êíó‘Ô
	void Move();    //ˆÚ“®ó‘Ô
	void Attack();  //UŒ‚ó‘Ô
	void KnockBack(); //‚Ì‚¯‚¼‚èó‘Ô
};




#endif // !ENEMY4GUARD
