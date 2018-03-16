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

製作者　青木

*/
//肉塊
class CEnemy5 :public CEnemyBase {
public:
	CEnemy5(const CVector3D *pos);
	~CEnemy5();
	void Update();
	void Nutral(); //通常状態
	void Move();    //移動状態
	void Attack();  //攻撃状態
	void KnockBack(); //のけぞり状態
	void Fall();       //倒された状態
	void Damage();    //ダメージ処理
};




#endif // !ENEMY1GUARD