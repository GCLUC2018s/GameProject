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
, m_cursor(0)
{
	for (int i = 0; i < 3; i++){
		m_sell_item[i].m_img = 0;
		m_sell_item[i].m_name = NONE;
		m_sell_item[i].m_type = (ItemType)0;
		m_sell_item[i].m_useful = 0;
		m_sell_item[i].m_attack_rate = 0;
	}

	m_shadowimg = LoadGraph("media\\img\\Pshadow.png", TRUE);
	LoadDivGraph("media\\img\\item-frame.png", 4, 2, 2, 100, 100, m_flame, TRUE);
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
				srand((unsigned int)time(NULL));
				for (int i = 0; i < 3; i++){
					if (m_sell_item[i].m_name == NONE){
						
						int _num = rand() % ITEMCOUNT;
						CItemData* item = CItemManager::GetInstance()->makeItem(_num);
						m_sell_item[i].m_img = item->m_img;
						m_sell_item[i].m_name = item->m_name;
						m_sell_item[i].m_type = item->m_type;
						m_sell_item[i].m_useful = item->m_useful;
						m_sell_item[i].m_attack_rate = item->m_attack_rate;
					}
				}
			}
		}
		m_pos.setX(_x);
		if (mv_ratio > 5 && mv_ratio < 95)
			m_dash_flag = false;

	}
	else{
		float _x = m_pos.getX();
		_x -= N_MOVEING_SPEED * FRAMETIME;
		if (_x > -200.0f){
			_x = -200.0f;
		}
		m_pos.setX(_x);
	}

	//ショップフラグが建つとアイテムとイグジットを表示する 操作できるようにする
	if (m_shop_flag){
		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (IsLeftKeyTrigger(key)){
			
		}
		if (IsRightKeyTrigger(key)){
		}
		if (IsZKeyTrigger(key)){
		}

	}

}

void CNpc::Draw(){
	clsDx();
	DrawGraph(m_pos.getX(), m_pos.getY(), m_shadowimg, TRUE);
	if (m_shop_flag){
		for (int i = 0; i < 3; i++){
			printfDx("%d", (int)m_sell_item);
			DrawGraph(i * 300, 300, m_sell_item[i].m_img, TRUE);
		}
	}
}



bool IsLeftKeyTrigger(int key){
	static int g_akey_prev;
	if (key & PAD_INPUT_LEFT){
		if (g_akey_prev == false){
			g_akey_prev = true;
			return true;
		}
	}
	else{
		g_akey_prev = false;
	}
	return false;
}

bool IsRightKeyTrigger(int key){
	static int g_akey_prev;
	if (key & PAD_INPUT_RIGHT){
		if (g_akey_prev == false){
			g_akey_prev = true;
			return true;
		}
	}
	else{
		g_akey_prev = false;
	}
	return false;
}

bool IsZKeyTrigger(int key){
	static int g_akey_prev;
	if (key & PAD_INPUT_1){
		if (g_akey_prev == false){
			g_akey_prev = true;
			return true;
		}
	}
	else{
		g_akey_prev = false;
	}
	return false;
}