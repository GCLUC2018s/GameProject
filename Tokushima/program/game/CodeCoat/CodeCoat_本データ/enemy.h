#ifndef ENEMY_H
#define ENEMY_H

#include "Task\CTask.h"
#include "myLib.h"

const float ENEMY_INIT_X = 500;
const float ENEMY_INIT_Y = 300;
const float E_SPEED = 400;
const float E_INITDIS = 0;
const int ENEMY_NUM = 20;		//Excel�̃G�l�~�[���ɉ����ĕω��@����20
const int ENEMY_LOWER_SIZE = 60;//�����蔻��(����)�v�Z�p
const int ENEMY_SHADOW_POS = 150;//�e�̈ʒu
const int ENEMY_CENTER = 80;	//�̂̒��S����o���p
const float ENEMY_COLLISION = 45;//�G�̓����蔻�蔼�a
const int ENEMY_POINT = 100;


class CEnemy :public CTask{
private:
	int m_hp;
	int m_type;
	int m_img;
	int m_distance;
	int m_attackrate;
	bool m_living;
	CVector3D m_pos;
public:
	CEnemy();
	CEnemy(CEnemy* enemy);
	~CEnemy();
	void Update();
	void Draw();
	void Move();
	CVector3D GetPos()const{ return m_pos; };
	int GetHp()const{ return m_hp; }				//�ǉ�enmey��hp��ԋp
	bool GetLive()const{ return m_living; }			//�ǉ������Ă��邩�Ԃ�
	void SetHp(int hp){ m_hp = hp; };
	void SetType(int type){ m_type = type; };
	void SetDistance(int dist){ m_distance = dist; };
	void SetPosX(float x){ m_pos.setX(x); };
	void SetPosY(float y){ m_pos.setY(y); };
	void SetLive(bool live){ m_living = live; }
};


#endif ENEMY_H