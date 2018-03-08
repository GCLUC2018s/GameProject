#ifndef ENEMY_GUARD
#define ENEMY_GUARD

#include "../GameProject/Task/CTask.h"

class CEnemy :public CTask
{
public:
	CEnemy();
	~CEnemy();
	void Update();


};
#endif // !ENEMY_GUARD
