#ifndef BULLET_GUARD
#define BULLET_GUARD

#include "Task\CTask.h"

class CBullet : public CTask {
public:
	CBullet(CVector2D pos);
	void Update();
	void Draw();
private:
	CImage b_img;
	CVector2D b_pos;
	CVector2D b_vec;
};
#endif // !BULLET_GUARD
