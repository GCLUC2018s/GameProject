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

����ҁ@��

*/
//����
class CEnemy5 :public CEnemyBase {
public:
	CEnemy5(const CVector3D *pos);
	void Update();
	void Nutral(); //�ʏ���
	void Move();    //�ړ����
	void Attack();  //�U�����
	void KnockBack(); //�̂�������
};




#endif // !ENEMY1GUARD