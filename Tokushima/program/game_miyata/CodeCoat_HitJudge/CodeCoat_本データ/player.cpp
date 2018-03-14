#include "player.h"
#include "player_manager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include "DxLib.h"
#include <stdio.h>
#include "map_manager.h"

CPlayerControl::CPlayerControl()
:CTask(0, eUDP_Player, eDWP_Player)
, m_gear(0)
, m_BodyPos(START_POSX,0.0f,START_POSZ)
, m_ShadowPos(START_POSX,0.0f, START_POSZ + PLAYER_SHADOW_POS)
, m_attack_time(0)
, m_jumping(false)
, m_jumppower(0)
, m_purge(FALSE)
{
	for (int i = 0; i < 3; i++){
		m_Equipment[i].m_img = 0;
		m_Equipment[i].m_name = (ItemName)0;
		m_Equipment[i].m_type = (ItemType)0;
		m_Equipment[i].m_useful = 0;
	}
	m_heroUpperimg = LoadGraph("media\\img\\knife_run_top.png", TRUE);
	m_heroLowerimg = LoadGraph("media\\img\\knife_run_under.png", TRUE);
	m_shadowimg = LoadGraph("media\\img\\Pshadow.png", TRUE);
	//CPlayerManagerにCPlayerControlのアドレスを渡すための関数
	CPlayerManager::GetInstance()->Init(this);
}

CPlayerControl::~CPlayerControl(){
}

void CPlayerControl::Update(/*CMapControl *Map,CItemControl *Item*/){



	//if (Map->getGoalFlag() != true){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	float hx = m_BodyPos.getX();
	float hy = m_BodyPos.getY();
	float hz = m_BodyPos.getZ();

	if (m_jumping){
		m_jumppower -= GRAVITY;
		hy -= (m_jumppower * FRAMETIME);
	}

	float mv = P_SPEED * FRAMETIME;		//270pixel/s
	if (key & PAD_INPUT_LEFT){
		hx -= mv;
		m_gear = (m_BodyPos.getX() / (ONE_GEAR_SPACE));
		/*if (m_playerstate != Jump)
			m_playerstate = Move;*/
	}
	else if (key & PAD_INPUT_RIGHT){
		hx += mv;
		m_gear = (m_BodyPos.getX() / (ONE_GEAR_SPACE));
		/*if (m_playerstate != Jump)
			m_playerstate = Move;*/
	}
	if (key & PAD_INPUT_UP){
		hz -= mv;
		/*if (m_playerstate != Jump)
			m_playerstate = Move;*/
	}
	else if (key & PAD_INPUT_DOWN){
		hz += mv;
		/*if (m_playerstate != Jump)
		m_playerstate = Move;*/
	}

	if ((int)m_gear == 5){
		m_gear = m_gear + m_BodyPos.getX() / (ONE_GEAR_SPACE) / 3;
	}
	if ((int)m_gear == 0){
		m_gear = 0.0f;
	}


	//移動範囲外だと座標の移動を無効化
	if (hx < MOVEING_RANGE_LEFT)hx = m_BodyPos.getX();
	if (hx > MOVEING_RANGE_RIGHT) hx = m_BodyPos.getX();
	if (hz + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS > MOVEING_RANGE_DOWN) hz = m_BodyPos.getZ();
	if (hz + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS < MOVEING_RANGE_UP)hz = m_BodyPos.getZ();

	if (m_jumping == false){
		if (key & PAD_INPUT_1 && hy == 0){
			m_jumping = true;
			m_jumppower = JUMP_POWER;
		}
	}
	else {
		if (hy > 0){
			m_jumppower = 0;
			m_jumping = false;
			hy = 0;
		}
	}

		//攻撃
	if (m_Equipment[WEAPON].m_name != NONE){
		switch (m_Equipment[WEAPON].m_name){
		case KNIFE:
			m_attack_time++;
			m_Equipment[WEAPON].m_useful--;
			if (IsXKeyTrigger(key) && m_attack_time > m_Equipment[WEAPON].m_attack_rate){
				m_Equipment[WEAPON].m_useful = 5;					//攻撃ON
				m_attack_time = 0;
			}
			break;
		case PISTOL:
			if (IsXKeyTrigger(key)){
				if (m_Equipment[WEAPON].m_useful > 0){
					CVector3D _pos = m_BodyPos + CVector3D(50.0f, 30.0f,0.0f);
					CVector3D _vec(36.0f, 0.0f,0.0f);
					CBulletManager::GetInstance()->Create(&_pos, &_vec, 1200.0f,PLAYER);
					m_Equipment[WEAPON].m_useful--;
				}
			}
			break;
		case SHOTTOGAN:
			m_attack_time++;
			if (IsXKeyTrigger(key)){
				if (m_Equipment[WEAPON].m_useful > 0){
					
					if (m_attack_time > m_Equipment[WEAPON].m_attack_rate){
						CVector3D _pos = m_BodyPos + CVector3D(50.0f,30.0f,0.0f);
						CVector3D _vec(0.0f, 0.0f,0.0f);
						for (int i = -3; i < 3; i++){
							_vec = CVector3D(cos(i * 10 * PI / 180.0) * 15, sin(i * 10 * PI / 180.0) * 15,0.0f);
							CBulletManager::GetInstance()->Create(&_pos, &_vec, 300.0f,PLAYER);
						}
						m_Equipment[WEAPON].m_useful--;
					}
				}
			}
			break;
		case RIFLE:
			m_attack_time++;
			if (key & PAD_INPUT_2){
			if (m_Equipment[WEAPON].m_useful > 0){
				
				if (m_attack_time > m_Equipment[WEAPON].m_attack_rate){
					CVector3D _pos = m_BodyPos + CVector3D(50.0f, 30.0f,0.0f);
					CVector3D _vec(36.0f, 0.0f,0.0f);
					CBulletManager::GetInstance()->Create(&_pos, &_vec, 1200.0f,PLAYER);
					m_Equipment[WEAPON].m_useful--;
					m_attack_time = 0;
				}
			}
			}
			break;
		default:
			break;
		}
	}

		//影と体の場所を更新
		m_BodyPos = CVector3D(hx,hy,hz);
		m_ShadowPos = CVector3D(hx, 0,hz + PLAYER_SHADOW_POS);


	//}
	//else{
		//goalposが0になるまでに定位置についておく
		//goalposが0になるとアニメーション開始　animconterで動きを管理する
		//主人公が車と重なると姿を消し、クリア
		//もしくはkeyに特定の情報を入力し、動きをつける
	//}


}

void CPlayerControl::Draw(){
	//見た目の関係で影、下半身、上半身の順番で描画
	DrawGraph((int)m_ShadowPos.getX(), (int)m_ShadowPos.getY() + m_ShadowPos.getZ(), m_shadowimg, TRUE);
	DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroLowerimg, TRUE);
	DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg, TRUE);
	DrawGraph(100, 520, m_Equipment[0].m_img, TRUE);
	DrawGraph(300, 520, m_Equipment[1].m_img, TRUE);
	DrawGraph(500, 520, m_Equipment[2].m_img, TRUE);
}

float CPlayerControl::getMoveAmount(){
	//仮：移動量 = (ギア*基本速度-装備重量)*バフ効果
	return (m_gear * BASE_SCR_SPEED * 1.5f) * FRAMETIME;
}

void CPlayerControl::setEquipment(CItemData* item){
	m_Equipment[item->m_type].m_img = item->m_img;
	m_Equipment[item->m_type].m_name = item->m_name;
	m_Equipment[item->m_type].m_type = item->m_type;
	m_Equipment[item->m_type].m_useful = item->m_useful;
	m_Equipment[item->m_type].m_attack_rate = item->m_attack_rate;
}