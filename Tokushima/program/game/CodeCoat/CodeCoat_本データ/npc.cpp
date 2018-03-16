#include "npc.h"
#include "npc_manager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include <DxLib.h>
#include <stdio.h>
#include "map_manager.h"
#include "player_manager.h"

CNpc::CNpc()
:CTask(0, eUDP_Npc, eDWP_Npc)
, m_shop_flag(false)
, m_dash_flag(false)
{
	m_shadowimg = LoadGraph("media\\img\\Pshadow.png", TRUE);
	//CNpc ManagerにCNpcのアドレスを渡すための関数
	CNpcManager::GetInstance()->Init(this);
}

CNpc::~CNpc(){
}

void CNpc::Update(){
	clsDx();
	printfDx("%f", m_pos.getX());
	float _total_mv = CMapManager::GetInstance()->GetPlayerAdress()->getTotalmovement();
	float _gear = CPlayerManager::GetInstance()->GetPlayerAdress()->getMoveAmount();
	_total_mv /= 40;
	int mv_ratio = (int)_total_mv % 100;//この100はuiの_move最大範囲を4で割ったもの
	if (mv_ratio > 95){
		m_dash_flag = true;
		m_pos = CVector3D(-200, 500, 0);
	}
	if (m_dash_flag){
		float _x = m_pos.getX();
		_x += N_MOVEING_SPEED * FRAMETIME;
		if (_x > 200.0f){
			_x = 200.0f;
			if (_gear == 0){
				//アイテム作成
				m_shop_flag = true;

			}
		}
		m_pos.setX(_x);
		if (mv_ratio > 5 && mv_ratio < 95)
			m_dash_flag = false;

	}
	else{
		m_pos.setX(m_pos.getX() - N_MOVEING_SPEED * FRAMETIME);
	}

	//ショップフラグが建つとアイテムとイグジットを表示する 操作できるようにする
	if (m_shop_flag){

	}

}

void CNpc::Draw(){
	DrawGraph(m_pos.getX(), m_pos.getY(), m_shadowimg, TRUE);
}