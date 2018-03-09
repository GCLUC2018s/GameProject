#ifndef PLAYER_H
#define PLAYER_H

#include "task.h"

//class Player :public Task{
//virtual void update();
//};

const int P_SPEED  = 50;
const float FRAMETIME = 0.1666666;

class CBullet : public CTask{
private:
	int m_x;
	int m_y;
	int m_img;
	void Update();
	void Draw();
public:
	CBullet(int x,int y);
	~CBullet();
};


class CPlayer : public CTask{
private:
	int x;
	int y;
	int m_img;
	void Update();
	void Draw();
public:
	CPlayer();
	~CPlayer();
};


#endif PLAYER_H