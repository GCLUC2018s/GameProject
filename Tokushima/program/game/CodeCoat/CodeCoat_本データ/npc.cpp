#include "npc.h"
#include "npc_manager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include <DxLib.h>
#include <stdio.h>
#include "map_manager.h"
#include "player_manager.h"
#include "ui_manager.h"
#include "se_manager.h"

CNpc::CNpc()
:CTask(0, eUDP_Npc, eDWP_Npc)
, m_ac(0)
, m_animcounter(0)
, m_pos(N_START_POSX, 0, N_START_POSZ)
, m_shop_flag(false)
, m_dash_flag(false)
, m_cursor(0)
, m_chk_pt(DASH_START_POS)
, m_chk_pt_num(CHECK_POINT_NUMBER)
, m_movestate(false)
{
	for (int i = 0; i < 3; i++){
		m_sell_item[i].m_img = 0;
		m_sell_item[i].m_name = NONE;
		m_sell_item[i].m_type = (ItemType)0;
		m_sell_item[i].m_useful = 0;
		m_sell_item[i].m_attack_rate = 0;
	}

	m_shadowimg = LoadGraph("media\\img\\Pshadow.png", TRUE);
	LoadDivGraph("media\\img\\Armsdealer.png", 9, 4, 3, 167, 190, m_bodyimg, TRUE);
	LoadDivGraph("media\\img\\item-frame.png", 5, 2, 3, 100, 100, m_flame, TRUE);
	LoadDivGraph("media\\img\\score_number2.png", 12, 10, 2, 40, 40, m_scorenum_img);
	//CNpc ManagerにCNpcのアドレスを渡すための関数
	CNpcManager::GetInstance()->Init(this);
}

CNpc::~CNpc(){
}

void CNpc::Update(){
	float _total_mv = CMapManager::GetInstance()->GetMapAdress()->getTotalmovement();
	Ptype* _player_state = CPlayerManager::GetInstance()->GetPlayerAdress()->getPlayerState();
	BOOL _purge = CPlayerManager::GetInstance()->GetPlayerAdress()->getpurge();
	float _yscr = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getY();
	Ui* _ui = CUiManager::GetInstance()->GetPlayerAdress();
	float _p_pos_z = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getZ();

	m_animcounter++;
	m_animcounter %= MAXINT;
	m_ac = m_animcounter / ANIM_RATE;

	if (_yscr > 250.0f)
		_yscr = 250.0f;

	if (_total_mv > m_chk_pt && _purge != TRUE){			//一定地点に行ったら通るように変更する
		m_dash_flag = true;
		m_movestate = true;
		m_pos = CVector3D(N_START_POSX, 0, N_START_POSZ);
		m_leave_time = GetNowCount();
		if (m_chk_pt_num > 0)
			m_chk_pt += DASH_START_POS;
		m_chk_pt_num--;
	}
	if (m_dash_flag){
		float _x = m_pos.getX();
		_x += N_MOVEING_SPEED * FRAMETIME;
		if (_x > 200.0f){
			_x = 200.0f;
			if (*_player_state == Stand && m_shop_flag == false){
				//アイテム作成
				m_shop_flag = true;
				m_cursor = 0;
				m_movestate = false;
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
		m_pos.setY(-1 * _yscr);
		//十秒間ショップに立ち寄らなければ立ち去る
		if (GetNowCount() - m_leave_time > N_WAIT_TIME && !m_shop_flag){
			m_dash_flag = false;
			m_movestate = true;
		}

	}
	else{
		float _x = m_pos.getX();
		_x -= N_MOVEING_SPEED * FRAMETIME;
		if (_x < -200.0f){
			_x = -200.0f;
		}
		m_pos.setX(_x);
		m_pos.setY(-1 * _yscr);
	}

	//ショップフラグが建つとアイテムとイグジットを表示する 操作できるようにする
	if (m_shop_flag){
		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (IsLeftKeyTrigger(key)){
			PlaySoundMem(CSeManager::GetInstance()->getsnd(ITEM_SE), DX_PLAYTYPE_BACK);
			m_cursor--;
			if (m_cursor < 0)
				m_cursor = 0;
		}
		if (IsRightKeyTrigger(key)){
			PlaySoundMem(CSeManager::GetInstance()->getsnd(ITEM_SE), DX_PLAYTYPE_BACK);
			m_cursor++;
			if (m_cursor > 3)
				m_cursor = 3;
		}
		if (IsHitKeyTrigger(key, PAD_INPUT_4)){
			if (m_cursor != 3){
				if (m_sell_item[m_cursor].m_name != NONE){
					if (_ui->getTotalScore() > CItemManager::GetInstance()->get_itemprice(m_sell_item[m_cursor].m_name)){
						CPlayerManager::GetInstance()->GetPlayerAdress()->setEquipment(&m_sell_item[m_cursor]);
						_ui->scoreFluctuation((int)(-1 * CItemManager::GetInstance()->get_itemprice(m_sell_item[m_cursor].m_name)));
						m_sell_item[m_cursor].m_img = 0;
						m_sell_item[m_cursor].m_name = NONE;
						m_sell_item[m_cursor].m_useful = 0;
						m_sell_item[m_cursor].m_attack_rate = 0;
					}

				}
			}
			else{
				for (int i = 0; i < 3; i++){
					m_sell_item[i].m_name = NONE;
				}
				m_shop_flag = false;
				m_dash_flag = false;
				m_movestate = true;
			}
		}

	}

	if (_p_pos_z < m_pos.getZ()){
		CNpc::ChangeDrawPriority(eDWP_FNpc);
	}
	else{
		CNpc::ChangeDrawPriority(eDWP_Npc);
	}

}

void CNpc::Draw(){
	DrawGraph(m_pos.getX() + NPC_SHADOW_WIDTH_POS, m_pos.getY() + m_pos.getZ() + NPC_SHADOW_HEIGHT_POS, m_shadowimg, TRUE);
	if (m_movestate)
		DrawGraph(m_pos.getX(), m_pos.getY() + m_pos.getZ(), m_bodyimg[m_ac % 8], TRUE);
	else
		DrawGraph(m_pos.getX(), m_pos.getY() + m_pos.getZ(), m_bodyimg[8], TRUE);
	if (m_shop_flag){
		float num;
		char buf[100];
		for (int i = 0; i < 3; i++){
			DrawGraph(i * FLAME_INTERVAL + FLAME_INTERVAL, FLAME_YPOS, m_flame[m_sell_item[i].m_type], TRUE);
			if (m_sell_item[i].m_name != NONE){
				DrawRotaGraph(i * FLAME_INTERVAL + FLAME_INTERVAL + 50, FLAME_YPOS + 50, 0.4, 3.141592 / 180 * -30, m_sell_item[i].m_img, TRUE, FALSE);
				num = sprintf_s(buf, 100, "%d", (int)CItemManager::GetInstance()->get_itemprice(m_sell_item[i].m_name));
				for (int t = 0; t < num; t++){
					DrawGraph(PRICENUM_INIT_X + t * 25 + i * FLAME_INTERVAL,
						PRICENUM_INIT_Y, m_scorenum_img[(buf[t] - '0')], TRUE);		//'0'
				}
			}
		}
		DrawGraph(FLAME_INTERVAL * 4, FLAME_YPOS, m_flame[3], TRUE);
		DrawGraph(m_cursor * FLAME_INTERVAL + FLAME_INTERVAL, FLAME_YPOS, m_flame[4], TRUE);

		
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