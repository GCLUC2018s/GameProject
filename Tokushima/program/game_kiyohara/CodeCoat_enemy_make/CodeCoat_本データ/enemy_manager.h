#ifndef ENEMY_MANAGER
#define ENEMY_MANAGER

#include <math.h>
#include <vector>
#include "enemy.h"

class CEnemyManager{
private:
	static CEnemyManager*	mp_instance;
	std::vector<CEnemy*>	m_enemy_list;

	//コンストラクタ
	CEnemyManager();

public:
	~CEnemyManager();
	static CEnemyManager* getInstance();
	static void clearInstance();
	void Update();
	void Draw();
	void LoadFile();
};

#endif ENEMY_MANAGER