#ifndef ENEMY2GUARD
#define ENEMY2GUARD

#include "CBase.h"

class CEnemy2 :public CBase {
public:
	CEnemy2(CVector2D pos);
	~CEnemy2();
	virtual void Update();
};

#endif // !ENEMY2GUARD