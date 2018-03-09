#ifndef ENEMY_GUARD
#define ENEMY_GUARD

#include "CBase.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
class CEnemy :public CBase {
public:
	CEnemy(CVector2D pos);
	~CEnemy();
	void Update();
	void Draw();
};

#endif // !ENEMY_GUARD