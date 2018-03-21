#include"CEnemy.h"
#include"task\CTaskManager.h"
#include"chara\C_Player.h"
#include"random"
#include"math.h"
#include"stdio.h"
struct EnemyTable{
	float x, y, z;
	int m_EnemyKind;
};
EnemyTable s_enemy_table[] = {
	{//0
		700, 0, 35,
		E_KIN, },
	{//1
		700, 0, -105,
			E_KIN, },
	{//2
		700, 0, -235,
			E_KIN, },
	{//3
		700, 0, -365,
			E_KIN, },
	{//4
		-700, 0, 35,
			E_KIN, },
	{//5
		-700, 0, -105,
			E_KIN, },
	{//6
		-700, 0, -235,
			E_KIN, },
	{//7
		-700, 0, -365,
			E_KIN, },
	{//8
		700, 0, 35,
		E_ESCAPE, },
	{//9
		700, 0, -105,
		E_ESCAPE, },
	{//10
		700, 0, -235,
		E_ESCAPE, },
	{//11
		700, 0, -365,
			E_ESCAPE, },

};
void CEnemy::Init(){
	m_ActionInterval = ACTION_INTERVAL;
	m_EnemySet = rand()/100 % 12;
	EnemyTable *data = &s_enemy_table[m_EnemySet];
	m_Position=C_Vector3(data->x, data->y, data->z);
	m_EnemyKind = data->m_EnemyKind;
	m_EnemyMode = E_NORMAL;
}
void CEnemy::Update(){
	m_Target = C_Player::m_Playerpoint->i_JumpPoint;
	float m_Long = sqrtf((m_Target.x - m_Position.x)*(m_Target.x - m_Position.x)
		+ (m_Target.z - m_Position.z)*(m_Target.z - m_Position.z));
	C_Vector3 diaPlayer =
		m_Target- m_Position;
	//�ߋ����퓬�^�̓G�̏���
	if (m_EnemyKind == E_KIN){
	}
	//�����^�̓G�̏���
	if (m_EnemyKind==E_ESCAPE){
		if (m_Position.x<=150){

			m_EnemyMode = E_ACTION;
		}
		if (m_EnemyMode == E_ACTION){
			if (m_ActionInterval >= 0){
				m_ActionInterval--;
			}
			if (m_ActionInterval <= 0){
				m_Position.x += ENEMY_LR_SPEED;
			}
			//if(m_Position.x >= 700){
			//	CTaskManager::GetInstance()->Kill(this);
			//	new CEnemy();
			//	Init();

			}
		}
	}
	if (m_EnemyMode == E_NORMAL){
		//�����ɂ���Ƃ��̒ǐՏ���
		if (m_Position.x< m_Target.x){
			m_Position.x += diaPlayer.x / m_Long * ENEMY_LR_SPEED;
			m_Turn = E_RIGHT;

		}
		//�E���ɂ���Ƃ��̒ǐՏ���
		else{
			m_Position.x += diaPlayer.x / m_Long * ENEMY_LR_SPEED;
			m_Turn = E_LEFT;
		}

		m_Position.z += diaPlayer.z / m_Long * ENEMY_UD_SPEED;
	}
	//�`�揇�Ԃ̕ύX
	CTaskManager::GetInstance()->ChangeDrawPrio(this, -m_Position.z);
	C_Object::Scroll(&m_Position, m_Scroll);
	C_Object::Rect(&m_image, &m_Position);
}
void CEnemy::Draw(){
	//
	RunAnime(&i_Enemy_Run, E_ENEMY);
	//
}

