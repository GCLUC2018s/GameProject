#ifndef ENEMY_GUARD
#define ENEMY_GUARD

#include "CBase.h"
/*

»ìÒ@Â–Ø

*/
class CEnemy :public CBase {
public:
	CEnemy(CVector2D pos);
	~CEnemy();
	virtual void Update();
};

#endif // !ENEMY_GUARD