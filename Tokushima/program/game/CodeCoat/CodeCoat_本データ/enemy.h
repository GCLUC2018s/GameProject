#ifndef ENEMY_H
#define ENEMY_H

#include "Task\CTask.h"
#include "myLib.h"

const float ENEMY_INIT_X = 500;
const float ENEMY_INIT_Y = 300;
const float E_SPEED = 400;
const float E_INITDIS = 0;
const int ENEMY_NUM = 20;		//Excelのエネミー数に応じて変化　現在20
const int ENEMY_LOWER_SIZE = 60;//当たり判定(腹部)計算用
const int ENEMY_SHADOW_POS = 150;//影の位置
const int ENEMY_CENTER = 80;	//体の中心割り出し用
const float ENEMY_COLLISION = 45;//敵の当たり判定半径
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
	int GetHp()const{ return m_hp; }				//追加enmeyのhpを返却
	bool GetLive()const{ return m_living; }			//追加生きているか返す
	void SetHp(int hp){ m_hp = hp; };
	void SetType(int type){ m_type = type; };
	void SetDistance(int dist){ m_distance = dist; };
	void SetPosX(float x){ m_pos.setX(x); };
	void SetPosY(float y){ m_pos.setY(y); };
	void SetLive(bool live){ m_living = live; }
};


#endif ENEMY_H