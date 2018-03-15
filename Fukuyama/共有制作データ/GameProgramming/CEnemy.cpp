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