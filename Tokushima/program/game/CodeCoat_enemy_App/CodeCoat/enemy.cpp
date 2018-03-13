#include "enemy.h"
#include "Task/CTaskManager.h"
#include "map_manager.h"
#include "player_manager.h"

CEnemy::CEnemy() :
m_hp(0),
m_type(0),
m_img(0),
m_pos(0, 0),
m_distance(0)
{
}

CEnemy::CEnemy(CEnemy* enemy) : 
CTask(0, eUDP_Enemy, eDWP_Enemy),
m_hp(enemy->m_hp),
m_type(enemy->m_type),
m_img(LoadGraph("media\\img\\coats.png", TRUE)),
m_pos(enemy->m_pos.getX(), enemy->m_pos.getY()),
m_distance(enemy->m_distance)
{
	//CTaskManager::GetInstance()->Add(this);
}

CEnemy::~CEnemy(){

}

void CEnemy::Update(){
	float l_t_move = CMapManager::GetInstance()->GetPlayerAdress()->getTotalmovement();
	float Amount = CPlayerManager::GetInstance()->GetPlayerAdress()->getMoveAmount();

	if (m_distance < l_t_move){
		m_pos.setX(m_pos.getX()-Amount);
	}
}

void CEnemy::Draw(){
	DrawRotaGraph2(m_pos.getX(),m_pos.getY(),
		0, 0, 1, 0, m_img, TRUE, TRUE);
}