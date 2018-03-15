#ifndef ENEMYMANAGER
#define ENEMYMANAGER

#include"CEnemyBase.h"
#include"../GameProject/Source/Gamesource.h"


class CEnemyManager :public CEnemyBase {
protected:
	int x, i;
public:
	CEnemyManager();
	void Update();
	void PushEnemy(const int *id);
};
















#endif // !ENEMYMANAGER