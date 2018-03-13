#ifndef ENEMY_H
#define ENEMY_H

#include "Task\CTask.h"
#include "myLib.h"

const float ENEMY_INIT_X = 500;
const float ENEMY_INIT_Y = 300;
const float E_SPEED = 400;
const float E_INITDIS = 0;
const int ENEMY_NUM = 20;		//Excelのエネミー数に応じて変化　現在20

class CEnemy :public CTask{
private:
	int m_hp;
	int m_type;
	int m_img;
	int m_distance;
	bool m_living;
	CVector2D m_pos;
public:
	CEnemy();
	CEnemy(CEnemy* enemy);
	~CEnemy();
	void Update();
	void Draw();
	void Move();
	CVector2D GetPos()const{ return m_pos; };
	void SetHp(int hp){ m_hp = hp; };
	void SetType(int type){ m_type = type; };
	void SetDistance(int dist){ m_distance = dist; };
	void SetPosX(float x){ m_pos.setX(x); };
	void SetPosY(float y){ m_pos.setY(y); };
};

#endif ENEMY_H