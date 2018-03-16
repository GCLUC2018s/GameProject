#include"CEnemy.h"
#include"task\CTaskManager.h"
#include"chara\C_Player.h"
#include"random"
void CEnemy::Init(){
	m_ActionInterval = ACTION_INTERVAL;
	srand((unsigned)time(NULL));
	m_EnemySet = rand() % 12;
	switch (m_EnemySet)
	{
	case 0:
		m_Position=C_Vector3(700,0,35);
		m_EnemyKind = E_KIN;
		break;
	case 1:
		m_Position = C_Vector3(700, 0, -105);
		m_EnemyKind = E_KIN;
		break;
	case 2:
		m_Position = C_Vector3(700, 0, -235);
		m_EnemyKind = E_KIN;
		break;
	case 3:
		m_Position = C_Vector3(700, 0, -365);
		m_EnemyKind = E_KIN;
		break;
	case 4:
		m_Position = C_Vector3(-700, 0, 35);
		m_EnemyKind = E_KIN;
		break;
	case 5:
		m_Position = C_Vector3(-700, 0, -105);
		m_EnemyKind = E_KIN;
		break;
	case 6:
		m_Position = C_Vector3(-700, 0, -235);
		m_EnemyKind = E_KIN;
		break;
	case 7:
		m_Position = C_Vector3(-700, 0, -365);
		m_EnemyKind = E_KIN;
		break;
	case 8:
		m_Position = C_Vector3(700, 0, 35);
		m_EnemyKind = E_ESCAPE;
		break;
	case 9:
		m_Position = C_Vector3(700, 0, -105);
		m_EnemyKind = E_ESCAPE;
		break;
	case 10:
		m_Position = C_Vector3(700, 0, -235);
		m_EnemyKind = E_ESCAPE;
		break;
	case 11:
		m_Position = C_Vector3(700, 0, -365);
		m_EnemyKind = E_ESCAPE;
		break;
	}
	m_EnemyMode = E_NORMAL;
}
void CEnemy::Update(){
	m_Target = C_Player::m_Playerpoint;
	C_Vector3 diaPlayer =
		m_Target->m_Position - m_Position;
	//‹ß‹——£í“¬Œ^‚Ì“G‚Ìˆ—
	if (m_EnemyKind == E_KIN){
	}
	//“¦‘–Œ^‚Ì“G‚Ìˆ—
	if (m_EnemyKind==E_ESCAPE){
		if (m_Position.x<=150){

			m_EnemyMode = E_ACTION;
		}
		if (m_EnemyMode == E_ACTION){
			if (m_ActionInterval >= 0){
				m_ActionInterval--;
			}
			if (m_ActionInterval <= 0){
				m_Position.x += 3;
			}
		}
	}
	if (m_EnemyMode == E_NORMAL){
		//¶‘¤‚É‚¢‚é‚Æ‚«‚Ì’ÇÕˆ—
		if (m_Position.x < m_Target->m_Position.x){
			m_Position.x += diaPlayer.x / ENEMY_LR_SPEED;

		}
		//‰E‘¤‚É‚¢‚é‚Æ‚«‚Ì’ÇÕˆ—
		else{
			m_Position.x = m_Position.x + (diaPlayer.x / ENEMY_LR_SPEED);
		}

		m_Position.z += diaPlayer.z / ENEMY_UD_SPEED;
	}
	C_Object::Rect(&m_image, &m_Position);
}
void CEnemy::Draw(){
	CTaskManager::GetInstance()->ChangeDrawPrio(this, m_Position.z);
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
}

