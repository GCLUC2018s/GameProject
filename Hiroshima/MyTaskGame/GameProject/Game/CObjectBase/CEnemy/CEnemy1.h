#ifndef ENEMY1GUARD
#define ENEMY1GUARD

#define DARUMA_HP 3
#define DARUMA_AT 5
#define DARUMA_SPEED 3

#define DARUMA_KNOCKBACK_SPEED 8

#include"CEnemyBase.h"
#include"../CObjectBase.h"
/*

����ҁ@��

*/


class CEnemy1 :public CEnemyBase {
public:
	//�����
	CEnemy1(const CVector3D *pos);
	void Update();
	void Nutral(); //�ʏ���
	void Move();    //�ړ����
	void Attack();  //�U�����
	void KnockBack(); //�̂�������
};




#endif // !ENEMY1GUARD