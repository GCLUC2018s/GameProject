#include "enemy.h"
#include "Task/CTaskManager.h"
#include "map_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "bullet_manager.h"

CEnemy::CEnemy() :
m_hp(0),
m_type(0),
m_pos(0, 0, 0),
m_distance(0)
, m_living(true)
{
}

CEnemy::CEnemy(CEnemy* enemy) :
CTask(0, eUDP_Enemy, eDWP_Enemy),
m_hp(enemy->m_hp),
m_type(enemy->m_type),
m_pos(enemy->m_pos.getX(), 0, enemy->m_pos.getY()),	//���������Ă��� z�ԂԂ��y������悤�ɂ�������������
m_distance(enemy->m_distance),
m_attackrate(0),
m_animframe(3), //�ǉ�
m_animcounter(18),	//�ǉ�
m_animflag(false),	//�ǉ�
m_living(true)
{
	switch (enemy->m_type)	//�ǉ�
	{
	case 0:
		LoadDivGraph("media\\img\\hitman.png", 7, 4, 2, 172, 190, m_img, TRUE);
		break;
	case 1:
		LoadDivGraph("media\\img\\knifeman.png", 4, 4, 1, 172, 190, m_img, TRUE);
		m_animframe = 0;
		m_animcounter = 0;
		break;
	default:
		break;
	}
}

CEnemy::~CEnemy(){

}

void CEnemy::Update(){
	float l_t_move = CMapManager::GetInstance()->GetMapAdress()->getTotalmovement();
	float Amount = CPlayerManager::GetInstance()->GetPlayerAdress()->getMoveAmount();
	float _yscr = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getY();
	//�v���C���[��Z���W
	float _p_pos_z = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getZ()+PLAYER_LOWER_SIZE;

	if (_yscr > 250.0f)
		_yscr = 250.0f;

	//�ړ�����
	if (m_distance < l_t_move){
		m_pos.setX(m_pos.getX() - Amount);
		m_pos.setY(-1 * _yscr);
	}

	//�U����i����
	switch (m_type)
	{
	case 0:
		if (m_attackrate > 100){
			m_attackrate = 0;
			m_animflag = true;
			CBulletManager::GetInstance()->Create(&CVector3D(m_pos.getX(),m_pos.getY(),m_pos.getZ()+29), &CVector3D(-8, 0, 0), 3000, ENEMY);
		}
		//�A�j���[�V��������	�ǉ�
		if (m_animflag == true){
			m_animcounter++;
			m_animframe = m_animcounter / 6 % 8;	//6�t���[�����ƂɂP�ς��
			if (m_animframe == 7){		//�摜��3�`6�܂ł̌v4��
				m_animflag = false;
				m_animcounter = 18;
				m_animframe = 3;
			}
		}
		break;
	case 1:
		//�A�j���[�V��������	�ǉ�
		m_animcounter++;
		m_animframe = m_animcounter / 20 % 4;		//18�t���[�����ƂɂP�ς��
		if (m_animframe == 3){			//�摜��0�`2�܂ł̌v3��
			m_animcounter = 0;
			m_animframe = 0;
		}
		break;
	default:
		break;
	}

	//��ʂ͈̔͊O�Ȃ����
	if (m_pos.getX() < -200){
		m_living = false;
	}
	else if (m_pos.getX() < SCREEN_SIZE_X){
		m_attackrate++;
	}


	if (m_living == false){
		if (!m_destroyFlg){
			CEnemyManager::getInstance()->Remove(this);
			//�^�X�N�L��
			SetKill();
			//CUiManager::GetInstance()->GetPlayerAdress()->scoreAddition();
		}
	}

	if (_p_pos_z < m_pos.getZ()){
		CEnemy::ChangeDrawPriority(eDWP_FEnemy);
	}
	else{
		CEnemy::ChangeDrawPriority(eDWP_Enemy);
	}
}

void CEnemy::Draw(){
	DrawRotaGraph2(m_pos.getX(), m_pos.getY() + m_pos.getZ(),
		0, 0, 1, 0, m_img[m_animframe], TRUE, FALSE);
}
