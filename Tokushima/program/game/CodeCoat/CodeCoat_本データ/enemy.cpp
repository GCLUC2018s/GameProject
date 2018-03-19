#include "enemy.h"
#include "Task/CTaskManager.h"
#include "map_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "bullet_manager.h"

CEnemy::CEnemy() :
m_hp(0),
m_type(0),
m_img(0),
m_pos(0, 0, 0),
m_distance(0)
, m_living(true)
{
}

CEnemy::CEnemy(CEnemy* enemy) :
CTask(0, eUDP_Enemy, eDWP_Enemy),
m_hp(enemy->m_hp),
m_type(enemy->m_type),
m_img(LoadGraph("media\\img\\hitman_chk.png", TRUE)),
m_pos(enemy->m_pos.getX(), 0, enemy->m_pos.getY()),	//書き換えてくれ zぶぶんにyが入るようにしただけだから
m_distance(enemy->m_distance),
m_attackrate(0),
m_living(true)
{
}

CEnemy::~CEnemy(){

}

void CEnemy::Update(){
	float l_t_move = CMapManager::GetInstance()->GetPlayerAdress()->getTotalmovement();
	float Amount = CPlayerManager::GetInstance()->GetPlayerAdress()->getMoveAmount();
	float _yscr = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getY();
	//プレイヤーのZ座標
	float _p_pos_z = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getZ()+PLAYER_LOWER_SIZE;

	if (_yscr > 250.0f)
		_yscr = 250.0f;

	//移動処理
	if (m_distance < l_t_move){
		m_pos.setX(m_pos.getX() - Amount);
		m_pos.setY(-1 * _yscr);
	}

	//攻撃手段処理
	switch (m_type)
	{
	case 0:
		if (m_attackrate > 90){
			m_attackrate = 0;
			CBulletManager::GetInstance()->Create(&CVector3D(m_pos.getX(),m_pos.getY(),m_pos.getZ()+29), &CVector3D(-8, 0, 0), 3000, ENEMY);
		}
		break;
	default:
		break;
	}

	//画面の範囲外なら消す
	if (m_pos.getX() < -200){
		m_living = false;
	}
	else if (m_pos.getX() < SCREEN_SIZE_X){
		m_attackrate++;
	}


	if (m_living == false){
		if (!m_destroyFlg){
			CEnemyManager::getInstance()->Remove(this);
			//タスクキル
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
		0, 0, 1, 0, m_img, TRUE, FALSE);
}
