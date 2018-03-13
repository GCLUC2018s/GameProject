#ifndef ENEMY4GUARD
#define ENEMY4GUARD
#include"../CObjectBase.h"

#define KAMAITACHI_HP 10
#define KAMAITACHI_AT 10
#define KAMAITACHI_SPEED 20
/*

êªçÏé“Å@ê¬ñÿ

*/
//Ç©Ç‹Ç¢ÇΩÇø
class CEnemy4 :public CObjectBase {
private:
	float m_a;
	int m_cnt;
	int m_move_cnt;
	bool m_stop;
public:
	CEnemy4(CVector3D *pos);
	~CEnemy4();
	void Update();
	void Neutral();
	void Move();
	void Attack();
};




#endif // !ENEMY4GUARD
