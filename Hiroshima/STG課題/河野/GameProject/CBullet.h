#ifndef BULLET_GUARD
#define BULLET_GUARD

#include "Task\CTask.h"

class CBullet : public CTask {
public:
	CBullet(CVector2D pos);
	void Update();
	void Draw();
};
#endif // !BULLET_GUARD
