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
	std::vector<CEnemy*> getEnemyList() const;
	void Remove(CEnemy* enemy);					//追加enemylistから引数アドレスを削除
};

#endif ENEMY_MANAGER