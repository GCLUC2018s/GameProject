#include"CEnemyManager.h"
#include"../CGo/CGo.h"

/*

制作者　青木

*/


enum {
	eDaruma,
	eChouchin,
	eHi,
	eKamaitachi,
	eNiku,
};

struct Enemy_Push
{
	int time;  //敵の出現タイミング
	int id;    //敵の種類
	CVector3D push_pos; //敵の出現位置



};

Enemy_Push  push_enemy[10][10]{
	//第一ウェイヴ
	{{ 100,eDaruma,CVector3D(400, 0, -300) },
	{ 200,eDaruma ,CVector3D(500, 0, -200) },
	{ 300,eDaruma ,CVector3D(600, 0, -250) },
	{ 400,eDaruma ,CVector3D(800, 0, -200) },
	{ 500,eDaruma ,CVector3D(800, 0, -200) },
	{ 600,eDaruma ,CVector3D(200, 0, -50) },
	{ 700,eDaruma ,CVector3D(400, 0, -300) },
	{ 800,eDaruma ,CVector3D(600, 0, -250) },
	{ 900,eDaruma ,CVector3D(800, 0, -200) },
	{ 1000,eDaruma ,CVector3D(200, 0, -50) },
	},{

		//第二ウェイブ
	{ 100,eChouchin,CVector3D(  400 + SCREEN_WIDTH, 0, -300) },
	{ 200,eChouchin ,CVector3D( 500 + SCREEN_WIDTH, -100, -200) },
	{ 300,eChouchin ,CVector3D( 600 + SCREEN_WIDTH, -150, -250) },
	{ 400,eChouchin ,CVector3D( 800 + SCREEN_WIDTH, -50, -200) },
	{ 500,eChouchin ,CVector3D( 800 + SCREEN_WIDTH, -50, -200) },
	{ 600,eChouchin ,CVector3D( 200 + SCREEN_WIDTH, 0, -50) },
	{ 700,eChouchin ,CVector3D( 400 + SCREEN_WIDTH, 0, -300) },
	{ 800,eChouchin ,CVector3D( 600 + SCREEN_WIDTH, -150, -250) },
	{ 900,eChouchin ,CVector3D( 800 + SCREEN_WIDTH, -50, -200) },
	{ 1000,eChouchin ,CVector3D(200 + SCREEN_WIDTH, 0, -50) },
}

,{

	//第三ウェイブ
	{ 100 , eKamaitachi  ,CVector3D(400 + SCREEN_WIDTH * 2, 0, -300) },
	{ 200,eKamaitachi ,CVector3D(   500 + SCREEN_WIDTH * 2, -100, -200) },
	{ 300,eKamaitachi ,CVector3D(   600 + SCREEN_WIDTH * 2, -150, -250) },
	{ 400,eKamaitachi ,CVector3D(   800 + SCREEN_WIDTH * 2, -50, -200) },
	{ 500,eKamaitachi ,CVector3D(   800 + SCREEN_WIDTH * 2, -50, -200) },
	{ 600,eKamaitachi ,CVector3D(   200 + SCREEN_WIDTH * 2, 0, -50) },
	{ 700,eKamaitachi ,CVector3D(   400 + SCREEN_WIDTH * 2, 0, -300) },
	{ 800,eKamaitachi ,CVector3D(   600 + SCREEN_WIDTH * 2, -150, -250) },
	{ 900,eKamaitachi ,CVector3D(   800 + SCREEN_WIDTH * 2, -50, -200) },
	{ 1000,eKamaitachi ,CVector3D(  200 + SCREEN_WIDTH * 2, 0, -50) },
	}
};


CEnemyManager::CEnemyManager() :CEnemyBase() {
	//m_id = -1;
	m_timing = 0, m_wave = 0, m_push = 0;
	m_old = m_wave_flag;
	
	
}

void CEnemyManager::Update() {

	if (m_old == false && m_wave_flag) {
		m_timing = 0;
		m_push = 0;
		m_wave++;
		m_go_flag = false;
	}
	m_old = m_wave_flag;
	if(m_wave_flag){
		if (push_enemy[m_wave][m_push].time == m_timing) {
			printf("%d   %d\n", push_enemy[m_wave][m_push].time, push_enemy[m_wave][m_push].id);
			PushEnemy(&push_enemy[m_wave][m_push].id, &push_enemy[m_wave][m_push].push_pos);
			m_push++;
			m_enemy_cnt++;
		
		
		}
		
		if(m_push <= 6)
		m_timing++;

		if (m_enemy_cnt <= 0&&m_push >=1 && m_go_flag == false) {
			new CGo();
			m_go_flag = true;
		}
	}

	
}


void CEnemyManager::PushEnemy(const int *id,const CVector3D *pos) {

//	m_id = id;
	//m_id = Utility::Rand(1, 100);
	//if(m_id < 50)
	//	m_id = Utility::Rand(0, 3);
	//else if (51 < m_id && m_id < 80)
	//	m_id = 4;
	//else if (81 < m_id)
	//	m_id = 3;
	switch (*id)
	{
	case eDaruma:
		new CEnemy1(pos);
		break;
	case eChouchin:
		new CEnemy2(pos);
		break;
	case eHi:
		new CEnemy3(pos);
		break;
	case eKamaitachi:
		new CEnemy4(pos);
		break;
	case eNiku:
		new CEnemy5(pos);
		break;
	default:
		break;
	}
}