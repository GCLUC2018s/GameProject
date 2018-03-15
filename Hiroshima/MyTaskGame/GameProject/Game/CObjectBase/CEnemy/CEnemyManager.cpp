#include"CEnemyManager.h"

/*



*/

struct Enemy_Push
{
	int time;
	int id;


};

Enemy_Push  push_enemy[10]{
	{ 100,1 },
	{ 120,2 },
	{ 150,3 },
	{ 160,1 },
	{ 200,4 },
	{ 300,3 },
	{ 500,0 },
};


CEnemyManager::CEnemyManager() :CEnemyBase() {
	//m_id = -1;
	i = 0, x = 0;
}

void CEnemyManager::Update() {

	if (push_enemy[x].time == i) {
		printf("%d   %d\n", push_enemy[x].time, push_enemy[x].id);
		PushEnemy(&push_enemy[x].id);
		x++;
		if (x > 6) {
			i = 0;
			x = 0;
		}
	}
	i++;
}


void CEnemyManager::PushEnemy(const int *id) {
	switch (*id)
	{
	case eDaruma:
		new CEnemy1(&(CVector3D(400, 0, -300)));
		break;
	case eChouchin:
		new CEnemy2(&(CVector3D(500, 100, -100)));
		break;
	case eHi:
		new CEnemy3(&(CVector3D(600, 100, -250)));
		break;
	case eKamaitachi:
		new CEnemy4(&(CVector3D(800, 50, -200)));
		break;
	case eNiku:
		new CEnemy5(&(CVector3D(200, 0, -130)));
		break;
	default:
		break;
	}
}