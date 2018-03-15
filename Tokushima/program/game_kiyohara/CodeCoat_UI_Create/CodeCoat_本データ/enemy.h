#ifndef ENEMY_H
#define ENEMY_H

#include "Task\CTask.h"
#include "myLib.h"

const float ENEMY_INIT_X = 500;
const float ENEMY_INIT_Y = 300;
const float E_SPEED = 400;
const float E_INITDIS = 0;
const int ENEMY_NUM = 20;		//Excel�̃G�l�~�[���ɉ����ĕω��@����20

class CEnemy :public CTask{
private:
	int m_hp;			//�̗�
	int m_type;			//���
	int m_img;			//�摜
	int m_distance;		//�o������
	bool m_living;		//�����Ă��邩
	CVector2D m_pos;	//���W
public:
	CEnemy();
	CEnemy(CEnemy* enemy);
	~CEnemy();
	void Update();
	void Draw();
	void Move();		//�ړ��H
	CVector2D GetPos()const{ return m_pos; };			//���W�̎擾
	void SetHp(int hp){ m_hp = hp; };					//�̗͂�ۑ�
	void SetType(int type){ m_type = type; };			//��ނ̕ۑ�
	void SetDistance(int dist){ m_distance = dist; };	//�o�������̕ۑ�
	void SetPosX(float x){ m_pos.setX(x); };			//���WX�̕ۑ�
	void SetPosY(float y){ m_pos.setY(y); };			//���WY�̕ۑ�
};

#endif ENEMY_H