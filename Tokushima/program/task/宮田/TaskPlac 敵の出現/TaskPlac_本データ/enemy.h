#ifndef ENEMY_H
#define ENEMY_H

#include "task.h"

//class Player :public Task{
//virtual void update();
//};


class CEnemy : public CTask{
private:
	int x;
	int y;
	int m_img;
	void Update();
	void Draw();
public:
	CEnemy();
	~CEnemy();
};


#endif ENEMY_H