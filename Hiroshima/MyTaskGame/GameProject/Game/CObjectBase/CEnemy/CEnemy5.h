#ifndef ENEMY5GUARD
#define ENEMY5GUARD

//#include"../CObjectBase.h"
#include "CEnemyBase.h"

#define NIKU_HP 15
#define NIKU_AT 15
#define NIKU_SPEED 2

#define NIKU_KNOCKBACK_SPEED 8

/*

����ҁ@��

*/
//����
class CEnemy5 :public CEnemyBase {
public:
	CEnemy5(const CVector3D *pos);
	~CEnemy5();
	void Update();
	void Nutral(); //�ʏ���
	void Move();    //�ړ����
	void Attack();  //�U�����
	void KnockBack(); //�̂�������
	void Fall();       //�|���ꂽ���
	void Damage();    //�_���[�W����
};




#endif // !ENEMY1GUARD