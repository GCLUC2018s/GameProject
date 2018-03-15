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
	int m_hp;			//体力
	int m_type;			//種類
	int m_img;			//画像
	int m_distance;		//出現距離
	bool m_living;		//生きているか
	CVector2D m_pos;	//座標
public:
	CEnemy();
	CEnemy(CEnemy* enemy);
	~CEnemy();
	void Update();
	void Draw();
	void Move();		//移動？
	CVector2D GetPos()const{ return m_pos; };			//座標の取得
	void SetHp(int hp){ m_hp = hp; };					//体力を保存
	void SetType(int type){ m_type = type; };			//種類の保存
	void SetDistance(int dist){ m_distance = dist; };	//出現距離の保存
	void SetPosX(float x){ m_pos.setX(x); };			//座標Xの保存
	void SetPosY(float y){ m_pos.setY(y); };			//座標Yの保存
};

#endif ENEMY_H