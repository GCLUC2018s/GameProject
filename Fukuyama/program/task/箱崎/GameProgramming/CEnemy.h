#ifndef CENEMY_H
#define CENEMY_H
#include"CRectangle.h"
class CEnemy :public CRectangle{
	void Init();
	void Update();
	void Draw();
};