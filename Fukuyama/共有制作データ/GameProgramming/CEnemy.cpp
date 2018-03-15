#include"CEnemy.h"
#include"task\CTaskManager.h"
#include"chara\C_Player.h"
C_Player *Player;
int EnemyCount = 0;
void CEnemy::Init(){
	m_Target = Player;
}
void CEnemy::Update(){
	C_Vector3 diaPlayer =
		m_Target->m_Position - m_Position;
}
void CEnemy::Draw(){
	CTaskManager::GetInstance()->ChangeDrawPrio(this, -m_Position.z);
}