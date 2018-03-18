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
, m_chk_pt(DASH_START_POS)
, m_chk_pt_num(CHECK_POINT_NUMBER)
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
	float _total_mv = CMapManager::GetInstance()->GetPlayerAdress()->getTotalmovement();
	Ptype* _player_state = CPlayerManager::GetInstance()->GetPlayerAdress()->getPlayerState();
	if (_total_mv > m_chk_pt){			//一定地点に行ったら通るように変更する
		m_dash_flag = true;
		m_pos = CVector3D(-200, 500, 0);
		m_leave_time = GetNowCount();
		m_chk_pt_num--;
		if (m_chk_pt_num > 0)
			m_chk_pt += DASH_START_POS;
	}
	if (m_dash_flag){
		float _x = m_pos.getX();
		_x += N_MOVEING_SPEED * FRAMETIME;
		if (_x > 200.0f){
			_x = 200.0f;
			if (*_player_state == Stand && m_shop_flag == false){
				//アイテム作成
				m_shop_flag = true; 
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
		if (GetNowCount() - m_leave_time > N_WAIT_TIME && !m_shop_flag)
			m_dash_flag = false;

	}
	else{
		float _x = m_pos.getX();
		_x -= N_MOVEING_SPEED * FRAMETIME;
		if (_x < -200.0f){
			_x = -200.0f;
		}
		m_pos.setX(_x);
	}

	//ショップフラグが建つとアイテムとイグジットを表示する 操作できるようにする
	if (m_shop_flag){
		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (IsLeftKeyTrigger(key)){
			m_cursor--;
			if (m_cursor < 0)
				m_cursor = 0;
		}
		if (IsRightKeyTrigger(key)){
			m_cursor++;
			if (m_cursor > 3)
				m_cursor = 3;
		}
		if (IsHitKeyTrigger(key,PAD_INPUT_4)){
			if (m_cursor != 3){
				if (m_sell_item[m_cursor].m_name != NONE){
					CPlayerManager::GetInstance()->GetPlayerAdress()->setEquipment(&m_sell_item[m_cursor]);
					m_sell_item[m_cursor].m_img = 0;
					m_sell_item[m_cursor].m_name = NONE;
					m_sell_item[m_cursor].m_useful = 0;
					m_sell_item[m_cursor].m_attack_rate = 0;

				}
			}
			else{
				m_shop_flag = false;
				m_dash_flag = false;
			}
		}
		
	}

}

void CNpc::Draw(){
	DrawGraph(m_pos.getX(), m_pos.getY(), m_shadowimg, TRUE);
	if (m_shop_flag){
		for (int i = 1; i < 4; i++){
			DrawGraph(i * FLAME_INTERVAL, 200, m_flame[m_sell_item[i - 1].m_type], TRUE);
			DrawRotaGraph(i * FLAME_INTERVAL + 50, FLAME_YPOS + 50, 0.4, 3.141592 / 180 * -30, m_sell_item[i - 1].m_img, TRUE, FALSE);
			DrawGraph(m_cursor * FLAME_INTERVAL + FLAME_INTERVAL, 200, m_flame[3], TRUE);
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

bool IsHitKeyTrigger(int key, int chk){
	static int g_akey_prev;
	if (key & chk){
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