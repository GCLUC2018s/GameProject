#ifndef ENEMY4GUARD
#define ENEMY4GUARD
#include"../CObjectBase.h"
#include  "CEnemyBase.h"

#define KAMAITACHI_HP 7
#define KAMAITACHI_AT 10
#define KAMAITACHI_SPEED 20

#define KAMAITACHI_KNOCKBACK_SPEED 8

#define KAMAITACHI_FLOAT 0.1f

#define KAMAITACHI_MOVE_TIME 130
#define KAMAITACHI_STOP_TIME 30
/*

製作者　青木

*/
class CEnemy4 :public CEnemyBase {
private:
	float m_a;
	int m_cnt;
	int m_move_cnt;
	bool m_stop;
public:
	//かまいたち
	CEnemy4(const CVector3D *pos);
	~CEnemy4();
	void Update();
	void Nutral(); //通常状態
	void Move();    //移動状態
	void Attack();  //攻撃状態
	void KnockBack(); //のけぞり状態
	void Fall();       //倒された状態
	void Damage();    //ダメージ処理
};




#endif // !ENEMY4GUARD
