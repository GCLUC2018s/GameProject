#ifndef CPLAYERBULLET_H
#define CPLAYERBULLET_H

#include "CRectangle.h"

class CPlayerBullet :public CRectangle{
public:
	void Draw();
	void Update();
};

#endif