#include"CEnemyManager.h"
#include"../CGo/CGo.h"

/*

制作者　青木

*/

#define END_CODE 999

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

Enemy_Push  push_enemy[32][32]{
	//第一ウェイヴ
	{
		{ 100	,eDaruma		,CVector3D(500, -20,-200) },
		{ 200	,eChouchin		,CVector3D(600, -80,-250) },
		{ 350	,eHi		,CVector3D(800, -40,-200) },
		{ 450	,eDaruma		,CVector3D(400, 0,	-300) },
		{ 600	,eChouchin		,CVector3D(800, -40,-200) },
		{ END_CODE }
	},{

		//第二ウェイブ
	{ 100,eDaruma,CVector3D(400 + SCREEN_WIDTH, 0, -300) },
	{ 250,eChouchin,CVector3D(  400 + SCREEN_WIDTH, 0, -300) },
	{ 400	,eHi	,CVector3D(500+SCREEN_WIDTH, -20,-200) },
	{ 500	,eHi	,CVector3D(600+SCREEN_WIDTH, -80,-250) },
	{ 500	,eChouchin	,CVector3D(800+SCREEN_WIDTH, -40,-200) },
	{ 650	,eDaruma	,CVector3D(400+SCREEN_WIDTH, 0,	-300) },
	{ 800	,eKamaitachi		,CVector3D(500+SCREEN_WIDTH, -20,-200) },
	{ 950	,eChouchin		,CVector3D(800+SCREEN_WIDTH, -40,-200) },
	{ 1000	,eKamaitachi		,CVector3D(200+SCREEN_WIDTH, 0,   -50) },
	{ END_CODE }
}

,{

	//第三ウェイブ
	{ 100 , eDaruma  ,CVector3D(400 + SCREEN_WIDTH * 2, 0, -300) },
	{ 250,eKamaitachi ,CVector3D(   500 + SCREEN_WIDTH * 2, -100, -200) },
	{ 400,eNiku ,CVector3D(		    600 + SCREEN_WIDTH * 2, 0, -250) },
	{ 500,eDaruma ,CVector3D(	    	800 + SCREEN_WIDTH * 2, 0, -200) },
	{ 600,eHi ,CVector3D(   800 + SCREEN_WIDTH * 2, -50, -200) },
	{ 600,eKamaitachi ,CVector3D(   200 + SCREEN_WIDTH * 2, 0, -50) },
	{ 700,eNiku ,CVector3D(		    400 + SCREEN_WIDTH * 2, 0, -300) },
	{ 800,eChouchin ,CVector3D(		600 + SCREEN_WIDTH * 2, -80, -250) },
	{ 950,eHi ,CVector3D(			800 + SCREEN_WIDTH * 2, 0, -200) },
	{ 1000,eNiku ,CVector3D(  200 + SCREEN_WIDTH * 2, 0, -50) },
	{ 1050,eKamaitachi ,CVector3D(200 + SCREEN_WIDTH * 2, 0, -50) },
	{ END_CODE }
	}

,{

	//第四ウェイブ
	{ 100, eHi  ,CVector3D(400 + SCREEN_WIDTH * 3, 0, -300) },
	{ 200, eNiku ,CVector3D( 500 + SCREEN_WIDTH * 3, 0, -200) },
	{ 350, eKamaitachi ,CVector3D( 600 + SCREEN_WIDTH * 3, 0, -250) },
	{ 500, eHi ,CVector3D( 800 + SCREEN_WIDTH * 3, 0, -200) },
	{ 600,eDaruma ,CVector3D(800 + SCREEN_WIDTH * 3, 0, -200) },
	{ 600,eDaruma ,CVector3D(200 + SCREEN_WIDTH * 3, 0, -50) },
	{ 780, eNiku ,CVector3D( 400 + SCREEN_WIDTH * 3, 0, -300) },
	{ 800, eChouchin ,CVector3D( 600 + SCREEN_WIDTH * 3, 0, -250) },
	{ END_CODE }
	}
};


CEnemyManager::CEnemyManager() :CEnemyBase() {
	//m_id = -1;
	m_timing = 0;
	m_wave = 0;
	m_push = 0;
	m_old = m_wave_flag;
	m_go_flag = false;
	m_enemy_cnt = 0;
	
	
}

CEnemyManager::~CEnemyManager()
{
}

void CEnemyManager::Update() {

	if (m_old == false && m_wave_flag) {
		m_timing = 0;
		m_push = 0;
		m_wave++;
		m_go_flag = false;
	}
	m_old = m_wave_flag;
	if (m_wave_flag) {
		const Enemy_Push& enemy_date = push_enemy[m_wave][m_push];


		if (enemy_date.time == m_timing) {
			printf("%d   %d\n", enemy_date.time, enemy_date.id);
			PushEnemy(enemy_date.id, &enemy_date.push_pos);
			m_push++;
			m_enemy_cnt++;


		}

		if (m_enemy_cnt <= 0 && m_push >= 1 && m_go_flag == false) {
			if (m_wave == 3)
				new CGo(true);
			else
				new CGo(false);
			m_go_flag = true;
		}
		if (m_push !=  END_CODE )
			m_timing++;
	}


}


void CEnemyManager::PushEnemy(int id,const CVector3D *pos) {

//	m_id = id;
	//m_id = Utility::Rand(1, 100);
	//if(m_id < 50)
	//	m_id = Utility::Rand(0, 3);
	//else if (51 < m_id && m_id < 80)
	//	m_id = 4;
	//else if (81 < m_id)
	//	m_id = 3;
	switch (id)
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