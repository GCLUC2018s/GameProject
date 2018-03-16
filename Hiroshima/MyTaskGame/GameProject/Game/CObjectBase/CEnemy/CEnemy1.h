#ifndef ENEMY1GUARD
#define ENEMY1GUARD

#define DARUMA_HP 10
#define DARUMA_AT 5
#define DARUMA_SPEED 3

#define DARUMA_KNOCKBACK_SPEED 8

//#include"../CObjectBase.h"
#include"CEnemyBase.h"
/*

製作者　青木

*/
class CEnemy1 :public CEnemyBase {
public:
	//だるま
	CEnemy1(const CVector3D *pos);
	~CEnemy1();
	void Update();
	void Nutral(); //通常状態
	void Move();    //移動状態
	void Attack();  //攻撃状態
	void KnockBack(); //のけぞり状態
	void Fall();       //倒された状態
	void Damage();    //ダメージ処理
};




#endif // !ENEMY1GUARD