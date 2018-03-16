#include"CEnemyManager.h"

/*



*/

struct Enemy_Push
{
	int time;
	int id;


};

Enemy_Push  push_enemy[10]{
	{ 100,0 },
	{ 200,0 },
	{ 300,0 },
	{ 400,0 },
	{ 500,0 },
	{ 600,0 },
	{ 700,0 },
	{ 800,0 },
	{ 900,0 },
	{ 1000,0 },
};


CEnemyManager::CEnemyManager() :CEnemyBase() {
	//m_id = -1;
	i = 0, x = 0;
}

void CEnemyManager::Update() {

	if (push_enemy[x].time == i) {
		//printf("%d   %d\n", push_enemy[x].time, push_enemy[x].id);
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

	m_id = Utility::Rand(1, 100);
	if(m_id < 50)
		m_id = Utility::Rand(0, 3);
	else if (51 < m_id && m_id < 80)
		m_id = 4;
	else if (81 < m_id)
		m_id = 3;
	switch (m_id)
	{
	case eDaruma:
		new CEnemy1(&(CVector3D(400, 0, -300)));
		break;
	case eChouchin:
		new CEnemy2(&(CVector3D(500, -100, -200)));
		break;
	case eHi:
		new CEnemy3(&(CVector3D(600, -150, -250)));
		break;
	case eKamaitachi:
		new CEnemy4(&(CVector3D(800, -50, -200)));
		break;
	case eNiku:
		new CEnemy5(&(CVector3D(200, 0, -130)));
		break;
	default:
		break;
	}
}