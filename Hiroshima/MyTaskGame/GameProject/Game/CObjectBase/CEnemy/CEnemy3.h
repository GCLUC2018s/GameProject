#ifndef ENEMY3GUARD
#define ENEMY3GUARD
#include"../CObjectBase.h"
#include"CEnemyBase.h"

#define HI_HP 3
#define HI_AT 7
#define HI_SPEED 5

#define HI_KNOCKBACK_SPEED 8

#define HI_FLOAT 0.1f
/*

製作者　青木

*/
class CEnemy3 :public CEnemyBase {
private:
	float m_a;	//浮遊用
public:
	//火の玉
	CEnemy3(const CVector3D *pos);
	~CEnemy3();
	void Update();
	void Nutral(); //通常状態
	void Move();    //移動状態
	void Attack();  //攻撃状態
	void KnockBack(); //のけぞり状態
	void Fall();       //倒された状態
	void Damage();    //ダメージ処理
};




#endif // !ENEMY3GUARD
