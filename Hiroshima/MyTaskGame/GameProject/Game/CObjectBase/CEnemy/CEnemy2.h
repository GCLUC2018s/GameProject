#ifndef ENEMY2GUARD
#define ENEMY2GUARD
//#include"../CObjectBase.h"
#include "CEnemyBase.h"

#define CHOCHIN_HP 5
#define CHOCHIN_AT 3
#define CHOCHIN_SPEED 4

#define CHOCHIN_KNOCKBACK_SPEED 8

#define CHOCHIN_FLOAT 0.3f
/*

製作者　青木

*/
//提灯
class CEnemy2 :public CEnemyBase {
private:
	float m_a;	//浮遊用
public:
	CEnemy2(const CVector3D *pos);
	~CEnemy2();
	void Update();
	void Nutral(); //通常状態
	void Move();    //移動状態
	void Attack();  //攻撃状態
	void KnockBack(); //のけぞり状態
	void Fall();       //倒された状態
	void Damage();    //ダメージ処理
};




#endif // !ENEMY4GUARD
