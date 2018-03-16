#include"CEnemy.h"
#include"task\CTaskManager.h"
#include"chara\C_Player.h"
#include"random"
int EnemyCount = 0;
void CEnemy::Init(){
	srand((unsigned)time(NULL));
	m_EnemySet = rand() % 12;
	switch (m_EnemySet)
	{
	case 0:
		C_Vector3(700,0,35);
		m_EnemyKind = E_KIN;
		break;
	case 1:
		C_Vector3(700, 0, -105);
		m_EnemyKind = E_KIN;
		break;
	case 2:
		C_Vector3(700, 0, -235);
		m_EnemyKind = E_KIN;
		break;
	case 3:
		C_Vector3(700, 0, -365);
		m_EnemyKind = E_KIN;
		break;
	case 4:
		C_Vector3(-700, 0, 35);
		m_EnemyKind = E_KIN;
		break;
	case 5:
		C_Vector3(-700, 0, -105);
		m_EnemyKind = E_KIN;
		break;
	case 6:
		C_Vector3(-700, 0,-235);
		m_EnemyKind = E_KIN;
		break;
	case 7:
		C_Vector3(-700, 0, -365);
		m_EnemyKind = E_KIN;
		break;
	case 8:
		C_Vector3(700, 0, 35);
		m_EnemyKind = E_ESCAPE;
		break;
	case 9:
		C_Vector3(700, 0, -105);
		m_EnemyKind = E_ESCAPE;
		break;
	case 10:
		C_Vector3(700, 0, -235);
		m_EnemyKind = E_ESCAPE;
		break;
	case 11:
		C_Vector3(700, 0, -365);
		m_EnemyKind = E_ESCAPE;
		break;
		m_EnemyCount += 1;
	}
}
void CEnemy::Update(){
	//近距離戦闘型の敵の処理
	if (m_EnemyKind == E_KIN){

	}
	//逃走型の敵の処理
	if (m_EnemyKind==E_ESCAPE){
		if (m_Position.x<=700){
			
		}
	}
	m_Target = C_Player::m_Playerpoint;
	C_Vector3 diaPlayer =
		m_Target->m_Position - m_Position;
	//左側にいるときの追跡処理
	if (m_Position.x < m_Target->m_Position.x){
		m_Position.x = m_Position.x + (diaPlayer.x + 90 / ENEMY_LR_SPEED);
	}
	//右側にいるときの追跡処理
	else{
		m_Position.x = m_Position.x + (diaPlayer.x - 90 / ENEMY_LR_SPEED);
	}

	m_Position.z = m_Position.z + (diaPlayer.z / ENEMY_UD_SPEED);

}
void CEnemy::Draw(){
	//
	glBegin(GL_TRIANGLES);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Left, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Top);
	glEnd();
	//
	CTaskManager::GetInstance()->ChangeDrawPrio(this, -m_Position.z);
}

