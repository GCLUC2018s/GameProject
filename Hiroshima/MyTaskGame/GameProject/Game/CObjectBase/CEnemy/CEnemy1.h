#ifndef ENEMY1GUARD
#define ENEMY1GUARD

#define DARUMA_HP 10
#define DARUMA_AT 5
#define DARUMA_SPEED 3

#define DARUMA_KNOCKBACK_SPEED 8

//#include"../CObjectBase.h"
#include"CEnemyBase.h"
/*

����ҁ@��

*/
class CEnemy1 :public CEnemyBase {
public:
	//�����
	CEnemy1(const CVector3D *pos);
	~CEnemy1();
	void Update();
	void Nutral(); //�ʏ���
	void Move();    //�ړ����
	void Attack();  //�U�����
	void KnockBack(); //�̂�������
	void Fall();       //�|���ꂽ���
	void Damage();    //�_���[�W����
};




#endif // !ENEMY1GUARD