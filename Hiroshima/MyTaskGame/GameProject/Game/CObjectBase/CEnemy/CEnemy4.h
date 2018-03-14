#ifndef ENEMY4GUARD
#define ENEMY4GUARD
#include"../CObjectBase.h"
#include  "CEnemyBase.h"

#define KAMAITACHI_HP 3
#define KAMAITACHI_AT 10
#define KAMAITACHI_SPEED 20

#define KAMAITACHI_KNOCKBACK_SPEED 8

#define KAMAITACHI_FLOAT 0.1f

#define KAMAITACHI_MOVE_TIME 130
#define KAMAITACHI_STOP_TIME 30
/*

êªçÏé“Å@ê¬ñÿ

*/
//Ç©Ç‹Ç¢ÇΩÇø
class CEnemy4 :public CEnemyBase {
private:
	float m_a;
	int m_cnt;
	int m_move_cnt;
	bool m_stop;
	bool m_damage;
	bool m_end_flag;
public:
	CEnemy4(const CVector3D *pos);
	~CEnemy4();
	void Update();
	void Neutral();
	void Move();
	void Attack();
	void KnockBack();
	void Fall();
	void Damage();
};




#endif // !ENEMY4GUARD
