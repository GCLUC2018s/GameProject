#ifndef BULLET_GUARD
#define BULLET_GUARD

#include "../GameProject/Task/CTask.h"

class CBullet :public CTask
{
public:
	CBullet(CVector2D pos);
	void Update();
};

#endif // !BULLET_GUARD
