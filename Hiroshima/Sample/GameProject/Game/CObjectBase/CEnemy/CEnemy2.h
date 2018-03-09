#ifndef ENEMY2GUARD
#define ENEMY2GUARD

#include"../CObjectBase.h"

class CEnemy2 :public CObjectBase {
public:
	CEnemy2(CVector2D pos);
	~CEnemy2();
	virtual void Update();
};

#endif // !ENEMY2GUARD