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

����ҁ@��

*/
class CEnemy3 :public CEnemyBase {
private:
	float m_a;	//���V�p
public:
	//�΂̋�
	CEnemy3(const CVector3D *pos);
	~CEnemy3();
	void Update();
	void Nutral(); //�ʏ���
	void Move();    //�ړ����
	void Attack();  //�U�����
	void KnockBack(); //�̂�������
	void Fall();       //�|���ꂽ���
	void Damage();    //�_���[�W����
};




#endif // !ENEMY3GUARD
