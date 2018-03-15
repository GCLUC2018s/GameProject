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

����ҁ@��

*/
class CEnemy4 :public CEnemyBase {
private:
	float m_a;
	int m_cnt;
	int m_move_cnt;
	bool m_stop;
public:
	//���܂�����
	CEnemy4(const CVector3D *pos);
	~CEnemy4();
	void Update();
	void Nutral(); //�ʏ���
	void Move();    //�ړ����
	void Attack();  //�U�����
	void KnockBack(); //�̂�������
	void Fall();       //�|���ꂽ���
	void Damage();    //�_���[�W����
};




#endif // !ENEMY4GUARD
