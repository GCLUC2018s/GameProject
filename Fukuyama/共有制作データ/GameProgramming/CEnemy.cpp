<<<<<<< HEAD
#include"CEnemy.h"
#include"task\CTaskManager.h"
#include"chara\C_Player.h"
#include"random"
C_Player *ip_Player;
int EnemyCount = 0;
void CEnemy::Init(){
	srand((unsigned)time(NULL));
	m_EnemySet = rand() % 12;
	switch (m_EnemySet)
	{
	case 0:
		C_Vector3(700,0,35);
		m_EnemyKind = 0;
		break;
	case 1:
		C_Vector3(700, 0, -105);
		m_EnemyKind = 0;
		break;
	case 2:
		C_Vector3(700, 0, -235);
		m_EnemyKind = 0;
		break;
	case 3:
		C_Vector3(700, 0, -365);
		m_EnemyKind = 0;
		break;
	case 4:
		C_Vector3(-700, 0, 35);
		m_EnemyKind = 0;
		break;
	case 5:
		C_Vector3(-700, 0, -105);
		m_EnemyKind = 0;
		break;
	case 6:
		C_Vector3(-700, 0,-235);
		m_EnemyKind = 0;
		break;
	case 7:
		C_Vector3(-700, 0, -365);
		m_EnemyKind = 0;
		break;
	case 8:
		C_Vector3(700, 0, 35);
		m_EnemyKind = 1;
		break;
	case 9:
		C_Vector3(700, 0, -105);
		m_EnemyKind = 1;
		break;
	case 10:
		C_Vector3(700, 0, -235);
		m_EnemyKind = 1;
		break;
	case 11:
		C_Vector3(700, 0, -365);
		m_EnemyKind = 1;
		break;
		m_EnemyCount += 1;
	}
}
void CEnemy::Update(){
	//‹ß‹——£í“¬Œ^‚Ì“G‚Ìˆ—
	if (m_EnemyKind == 0){

	}
	//“¦‘–Œ^‚Ì“G‚Ìˆ—
	else{
		if (m_Position.x<=700){
			
		}
	}
	m_Target = ip_Player;
	C_Vector3 diaPlayer =
		m_Target->m_Position - m_Position;
	//¶‘¤‚É‚¢‚é‚Æ‚«‚Ì’ÇÕˆ—
	if (m_Position.x < ip_Player->m_Position.x){
		m_Position.x = m_Position.x + (diaPlayer.x + 90 / ENEMY_LR_SPEED);
	}
	//‰E‘¤‚É‚¢‚é‚Æ‚«‚Ì’ÇÕˆ—
	else{
		m_Position.x = m_Position.x + (diaPlayer.x - 90 / ENEMY_LR_SPEED);
	}

	m_Position.z = m_Position.z + (diaPlayer.z / ENEMY_UD_SPEED);

}
void CEnemy::Draw(){

	CTaskManager::GetInstance()->ChangeDrawPrio(this, -m_Position.z);
}
=======
//#include"CEnemy.h"
//#include"task\CTaskManager.h"
//#include"chara\C_Player.h"
//C_Player *ip_Player;
//int EnemyCount = 0;
//void CEnemy::Init(){
//	switch (m_EnemySet)
//	{
//	case 0:
//		C_Vector3(1300,0,35);
//		m_EnemyKind = 0;
//		break;
//	case 0:
//		C_Vector3(1300, 0, 35);
//		m_EnemyKind = 0;
//		break;
//	case 0:
//		C_Vector3(1300, 0, 35);
//		m_EnemyKind = 0;
//		break;
//	case 0:
//		C_Vector3(1300, 0, 35);
//		m_EnemyKind = 0;
//		break;
//	case 0:
//		C_Vector3(1300, 0, 35);
//		m_EnemyKind = 0;
//		break;
//	case 0:
//		C_Vector3(1300, 0, 35);
//		m_EnemyKind = 0;
//		break;
//	case 0:
//		C_Vector3(1300, 0, 35);
//		m_EnemyKind = 0;
//		break;
//	}
//}
//void CEnemy::Update(){
//	m_Target = ip_Player;
//	C_Vector3 diaPlayer =
//		m_Target->m_Position - m_Position;
//	m_Position.x = m_Position.x + (diaPlayer.x/ENEMY_LR_SPEED);
//	m_Position.z = m_Position.z + (diaPlayer.z / ENEMY_UD_SPEED);
//
//}
//void CEnemy::Draw(){
//	CTaskManager::GetInstance()->ChangeDrawPrio(this, -m_Position.z);
//}
>>>>>>> 214e5adb891a7dfca60e1a25a89896a1dda383fc
