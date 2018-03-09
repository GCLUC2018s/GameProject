#ifndef CBULLET_H
#define CBULLET_H
#include "CRectangle.h"
class CBullet : public CRectangle{
public:
	void Init();
	void Update();
	void Draw();
}
#endif