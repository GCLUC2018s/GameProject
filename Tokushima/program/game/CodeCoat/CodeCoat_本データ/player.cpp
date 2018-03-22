#include "player.h"
#include "player_manager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include <DxLib.h>
#include <stdio.h>
#include "map_manager.h"
#include "npc_manager.h"
#include "enemy_manager.h"
#include "ui_manager.h"
#include "se_manager.h"

CPlayerControl::CPlayerControl()
:CTask(0, eUDP_Player, eDWP_Player)
, m_gear(0)
, m_BodyPos(START_POSX,0.0f,START_POSZ)
, m_ShadowPos(START_POSX + PLAYER_SHADOW_WIDTH_POS, 0.0f, START_POSZ + PLAYER_SHADOW_HEIGHT_POS)
, m_attack_time(0)
, m_jumping(false)
, m_jumppower(0)
, m_purge(FALSE)
, m_upper_animcounter(0)
, m_lower_animcounter(0)
, m_upper_playerstate(Stand)
, m_lower_playerstate(Stand)
, m_live(true)
{
	for (int i = 0; i < 3; i++){
		m_Equipment[i].m_img = 0;
		m_Equipment[i].m_name = NONE;
		m_Equipment[i].m_type = (ItemType)0;
		m_Equipment[i].m_useful = 0;
	}
	m_buff.m_speedup = 0;
	m_buff.m_score_ratio = 0;
	LoadDivGraph("media\\img\\player\\top.png", 16, 4, 4, 167, 190, m_heroUpperimg[P_NORMAL], TRUE);
	LoadDivGraph("media\\img\\player\\coat_knife_top.png", 18, 4, 5, 167, 190, m_heroUpperimg[P_KNIFE], TRUE);
	LoadDivGraph("media\\img\\player\\coat_handgun.png", 13, 4, 4, 167, 190, m_heroUpperimg[P_PISTOL], TRUE);
	LoadDivGraph("media\\img\\player\\coat_shotgun.png", 15, 4, 4, 167, 190, m_heroUpperimg[P_SHOTTOGAN], TRUE);
	LoadDivGraph("media\\img\\player\\coat_ak.png", 12, 4, 3, 167, 190, m_heroUpperimg[P_RIFLE], TRUE);
	LoadDivGraph("media\\img\\player\\run.png", 13, 4, 4, 167, 190, m_heroUpperimg[P_PURGE], TRUE);
	LoadDivGraph("media\\img\\player\\purge.png", 7, 4, 2, 167, 190, m_heroUpperimg[P_PURGE_ACTIVE], TRUE);
	LoadDivGraph("media\\img\\player\\under.png", ANIM_COUNT, 4, 4, 167, 190, m_heroLowerimg);
	m_shadowimg = LoadGraph("media\\img\\Pshadow.png", TRUE);
	//CPlayerManagerにCPlayerControlのアドレスを渡すための関数
	CPlayerManager::GetInstance()->Init(this);
}

CPlayerControl::~CPlayerControl(){
}

void CPlayerControl::Update(){
	CNpc *_npc = CNpcManager::GetInstance()->GetNpcAdress();
	bool _goal = CMapManager::GetInstance()->GetMapAdress()->getGoalFlag();
	if (!_goal){
		//ショップを開いてる間は移動不可
		if (!_npc->getShopFlag()){
			m_upper_animcounter++;
			m_upper_animcounter %= MAXINT;
			m_upper_ac = m_upper_animcounter / ANIM_RATE;
			m_lower_animcounter++;
			m_lower_animcounter %= MAXINT;
			m_lower_ac = m_lower_animcounter / ANIM_RATE;

			int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
			float hx = m_BodyPos.getX();
			float hy = m_BodyPos.getY();
			float hz = m_BodyPos.getZ();

			if (!m_gear){
				m_lower_playerstate = Stand;
				if (m_upper_playerstate == Move)
					m_upper_playerstate = Stand;
			}
			else{
				if (!m_jumping && m_upper_playerstate != Attack){
					m_lower_playerstate = Move;
					m_upper_playerstate = Move;
				}
			}

			if (m_playerstate == P_PURGE_ACTIVE){
				m_jumppower += GRAVITY / 2 + GRAVITY / 3 + GRAVITY / 12;
				if (m_upper_ac == 14){
					m_playerstate = P_PURGE;
					m_upper_playerstate = Move;
					m_upper_ac = 0;
					m_upper_animcounter = 0;
				}
			}

			if (m_jumping){
				m_jumppower -= GRAVITY;
				hy -= (m_jumppower * FRAMETIME);
				if (m_playerstate != P_PURGE_ACTIVE){
					m_upper_playerstate = Jump;
					m_lower_playerstate = Jump;
				}
			}

			

			//移動
			float mv = (P_SPEED + m_buff.m_speedup) * FRAMETIME;		//270pixel/s + buff
			if (key & PAD_INPUT_LEFT){
				hx -= mv;
				m_gear = (m_BodyPos.getX() / (ONE_GEAR_SPACE)) + m_purge;
				if (m_upper_playerstate != Jump && m_lower_playerstate != Jump
					&& m_upper_playerstate != Attack && m_lower_playerstate != Attack){
					m_upper_playerstate = Move;
					m_lower_playerstate = Move;
				}
			}
			else if (key & PAD_INPUT_RIGHT){
				hx += mv;
				m_gear = (m_BodyPos.getX() / (ONE_GEAR_SPACE)) + m_purge;
				if (m_upper_playerstate != Jump && m_lower_playerstate != Jump
					&& m_upper_playerstate != Attack && m_lower_playerstate != Attack){
					m_upper_playerstate = Move;
					m_lower_playerstate = Move;
				}
			}
			if (key & PAD_INPUT_UP){
				hz -= mv;
				if (m_upper_playerstate != Jump && m_lower_playerstate != Jump
					&& m_upper_playerstate != Attack && m_lower_playerstate != Attack){
					m_upper_playerstate = Move;
					m_lower_playerstate = Move;
				}
			}
			else if (key & PAD_INPUT_DOWN){
				hz += mv;
				if (m_upper_playerstate != Jump && m_lower_playerstate != Jump
					&& m_upper_playerstate != Attack && m_lower_playerstate != Attack){
					m_upper_playerstate = Move;
					m_lower_playerstate = Move;
				}
			}

			if ((int)m_gear == 8){
			m_gear = m_gear + m_BodyPos.getX() / (ONE_GEAR_SPACE) / 3;
			}
			if ((int)m_gear == 0){
				m_gear = 0.0f + m_purge;
			}


			//移動範囲外だと座標の移動を無効化
			if (hx < MOVEING_RANGE_LEFT)hx = m_BodyPos.getX();
			if (hx > MOVEING_RANGE_RIGHT) hx = m_BodyPos.getX();
			if (hz + PLAYER_LOWER_SIZE + PLAYER_SHADOW_HEIGHT_POS > MOVEING_RANGE_DOWN) hz = m_BodyPos.getZ();
			if (hz + PLAYER_LOWER_SIZE + PLAYER_SHADOW_HEIGHT_POS < MOVEING_RANGE_UP)hz = m_BodyPos.getZ();

			//ジャンプ関連
			if (!m_jumping){
				if (key & PAD_INPUT_1 && hy == 0){
					PlaySoundMem(CSeManager::GetInstance()->getsnd(JUMP_SE), DX_PLAYTYPE_BACK);
					m_jumping = true;
					m_jumppower = JUMP_POWER;
					m_upper_ac = 0;
					m_upper_animcounter = 0;
				}
			}
			else {
				if (hy > 0){
					m_jumppower = 0;
					m_jumping = false;
					hy = 0;
					if (m_gear == 0)		//後々モーションが増えると追加
						m_upper_playerstate = Stand;
					else
						m_upper_playerstate = Move;
				}
			}

			//パージ
			if (key & PAD_INPUT_5 && key & PAD_INPUT_6){
				//if (m_Equipment[WEAPON].m_name != NONE && m_Equipment[ARMOR].m_name != NONE &&m_Equipment[ITEM].m_name != NONE){
					//アニメーション
					PlaySoundMem(CSeManager::GetInstance()->getsnd(PURGE_SE), DX_PLAYTYPE_BACK);
					m_playerstate = P_PURGE_ACTIVE;
					m_upper_playerstate = Move;
					m_purge = TRUE;
					m_upper_ac = 0;
					m_upper_animcounter = 0;
					m_jumping = true;
					m_jumppower = 300;
					
					//装備を外す
					for (int i = WEAPON; i != EQUIPMENT_COUNT; i++){
						//スコア加算
						CUiManager::GetInstance()->GetPlayerAdress()->scoreFluctuation(CItemManager::GetInstance()->get_itemprice(m_Equipment[i].m_name));
						m_Equipment[i].m_img = 0;
						m_Equipment[i].m_name = NONE;
						m_Equipment[i].m_type = (ItemType)0;
						m_Equipment[i].m_useful = 0;
					}

					//画面に映っている敵を倒す
					float _t_move = CMapManager::GetInstance()->GetMapAdress()->getTotalmovement();
					auto _enemy_list = CEnemyManager::getInstance()->getEnemyList();
					for (auto it = _enemy_list.begin(); it != _enemy_list.end(); it++){
						if ((*it)->GetPos().getX() < 1279.9f){
							(*it)->SetLive(false);
						}
					//}
				}
			}

			//攻撃
			if (m_Equipment[WEAPON].m_name != NONE){
				if (m_upper_playerstate != Jump){
					switch (m_Equipment[WEAPON].m_name){
					case KNIFE:
						m_attack_time++;
						m_Equipment[WEAPON].m_useful--;
						if (IsXKeyTrigger(key) && m_attack_time > m_Equipment[WEAPON].m_attack_rate){
							m_Equipment[WEAPON].m_useful = 5;					//攻撃ON
							m_attack_time = 0;
							PlaySoundMem(CSeManager::GetInstance()->getsnd(KNIFE_SE), DX_PLAYTYPE_BACK);
							if (m_upper_playerstate != Attack){
								m_upper_playerstate = Attack;
								m_upper_animcounter = 0;
								m_upper_ac = 0;
							}
						}
						break;
					case PISTOL:
						if (IsXKeyTrigger(key)){
							if (m_Equipment[WEAPON].m_useful > 0){
								CVector3D _pos = m_BodyPos + CVector3D(127.0f, 0.0f, 45.0f);
								CVector3D _vec(36.0f, 0.0f, 0.0f);
								CBulletManager::GetInstance()->Create(&_pos, &_vec, 1200.0f, PLAYER);
								m_Equipment[WEAPON].m_useful--;
								PlaySoundMem(CSeManager::GetInstance()->getsnd(SHOT_SE), DX_PLAYTYPE_BACK);
								if (m_upper_playerstate != Attack){
									m_upper_playerstate = Attack;
									m_upper_animcounter = 0;
									m_upper_ac = 0;
								}

							}
							CPlayerManager::GetInstance()->setNoDamageMovement(0);
						}
						break;
					case SHOTTOGAN:
						m_attack_time++;
						if (IsXKeyTrigger(key)){

							if (m_attack_time > m_Equipment[WEAPON].m_attack_rate){
								CVector3D _pos = m_BodyPos + CVector3D(117.0f, 0.0f, 50.0f);
								CVector3D _vec(0.0f, 0.0f, 0.0f);
								for (int i = -3; i < 3; i++){
									_vec = CVector3D(cos(i * 10 * PI / 180.0) * 36, 0.0f, sin(i * 10 * PI / 180.0) * 15);
									CBulletManager::GetInstance()->Create(&_pos, &_vec, 300.0f, PLAYER);
								}
								if (m_upper_playerstate != Attack){
									m_upper_playerstate = Attack;
									m_upper_animcounter = 0;
									m_upper_ac = 0;
								}
								PlaySoundMem(CSeManager::GetInstance()->getsnd(SHOT2_SE), DX_PLAYTYPE_BACK);
								m_attack_time = 0;
								m_Equipment[WEAPON].m_useful--;
							}
							CPlayerManager::GetInstance()->setNoDamageMovement(0);
						}
						break;
					case RIFLE:
						m_attack_time++;
						if (key & PAD_INPUT_2){
							if (m_Equipment[WEAPON].m_useful > 0){

								if (m_attack_time > m_Equipment[WEAPON].m_attack_rate){
									CVector3D _pos = m_BodyPos + CVector3D(127.0f, 0.0f, 55.0f);
									CVector3D _vec(36.0f, 0.0f, 0.0f);
									CBulletManager::GetInstance()->Create(&_pos, &_vec, 1200.0f, PLAYER);
									if (m_upper_playerstate != Attack){
										m_upper_playerstate = Attack;
										m_upper_animcounter = 0;
										m_upper_ac = 0;
									}
									PlaySoundMem(CSeManager::GetInstance()->getsnd(SHOT_SE), DX_PLAYTYPE_BACK);
									m_Equipment[WEAPON].m_useful--;
									m_attack_time = 0;
								}
							}
							CPlayerManager::GetInstance()->setNoDamageMovement(0);
						}
						break;
					default:
						break;
					}
				}
			}
			//攻撃のリセット
			if (m_upper_playerstate == Attack){
				switch (m_Equipment[WEAPON].m_name){
				case KNIFE:
					if (m_upper_ac > 5){
						m_upper_ac = 0;
						m_upper_animcounter = 0;
						if (!m_gear){
							m_lower_playerstate = Stand;
							m_upper_playerstate = Stand;
						}
						else{
							m_lower_playerstate = Move;
							m_upper_playerstate = Move;
						}
					}
					break;
				case PISTOL:
					if (m_upper_ac > 3){
						if (m_Equipment[WEAPON].m_useful <= 0){
							m_Equipment[WEAPON].m_name = NONE;
							m_Equipment[WEAPON].m_img = 0;
							m_playerstate = P_NORMAL;
						}
						m_upper_ac = 0;
						m_upper_animcounter = 0;
						if (!m_gear){
							m_lower_playerstate = Stand;
							m_upper_playerstate = Stand;
						}
						else{
							m_lower_playerstate = Move;
							m_upper_playerstate = Move;
						}

					}
					break;
				case SHOTTOGAN:
					if (m_upper_ac > 3){
						if (m_Equipment[WEAPON].m_useful <= 0){
							m_Equipment[WEAPON].m_name = NONE;
							m_Equipment[WEAPON].m_img = 0;
							m_playerstate = P_NORMAL;
						}
						m_upper_ac = 0;
						m_upper_animcounter = 0;
						if (m_gear == 0){
							m_lower_playerstate = Stand;
							m_upper_playerstate = Stand;
						}
						else{
							m_lower_playerstate = Move;
							m_upper_playerstate = Move;
						}
					}
					break;
				case RIFLE:
					if (m_upper_ac > 1){
						if (m_Equipment[WEAPON].m_useful <= 0){
							m_Equipment[WEAPON].m_name = NONE;
							m_Equipment[WEAPON].m_img = 0;
							m_playerstate = P_NORMAL;
						}
						m_upper_ac = 0;
						m_upper_animcounter = 0;
						if (!m_gear){
							m_lower_playerstate = Stand;
							m_upper_playerstate = Stand;
						}
						else{
							m_lower_playerstate = Move;
							m_upper_playerstate = Move;
						}
					}
					break;
				default:
					break;
				}
			}

			//アイテム使用　attack_ratio = 使った時間
			if (IsHitKeyTrigger(key, PAD_INPUT_C)){
				//アイテムの種類を判別
				switch (m_Equipment[ITEM].m_name){
				case SCOREBOOST:
					m_buff.m_score_ratio = SCORE_BUFF;
					m_Equipment[ITEM].m_img = 0;
					m_buff.m_score_ratio_time = GetNowCount();
					m_Equipment[ITEM].m_name = NONE;
					m_buff.m_score_ratio_delay = m_Equipment[ITEM].m_useful;
					break;
				case SPEEDUP:
					m_buff.m_speedup = SPEED_BUFF;
					m_Equipment[ITEM].m_img = 0;
					m_Equipment[ITEM].m_attack_rate = GetNowCount();
					m_Equipment[ITEM].m_name = NONE;
					m_buff.m_sppedup_time = GetNowCount();
					m_buff.m_speedup_delay = m_Equipment[ITEM].m_useful;
					break;
				default:
					break;
				}
			}
			//バフの効果時間を管理
			if (GetNowCount() - m_buff.m_score_ratio_time > m_buff.m_score_ratio_delay){
				m_buff.m_score_ratio = 0;
			}
			if (GetNowCount() - m_buff.m_sppedup_time > m_buff.m_speedup_delay){
				m_buff.m_speedup = 0;
			}

			//無敵時間関係
			if (m_InvincibleFlag == TRUE){		//無敵時間
				m_duration += FRAMETIME;
				damageFlash(m_duration);
				if ((int)m_duration >= 2){
					m_duration = 0;
					m_InvincibleFlag = FALSE;
				}
			}

			//影と体の場所を更新
			m_BodyPos = CVector3D(hx, hy, hz);
			m_ShadowPos = CVector3D(hx + PLAYER_SHADOW_WIDTH_POS, 0, hz + PLAYER_SHADOW_HEIGHT_POS);
		}
	}
	else{
		//ゴールしたら走り抜ける
		float mv = (P_SPEED + m_buff.m_speedup) * FRAMETIME;		//270pixel/s + buff
		float hx = m_BodyPos.getX();
		m_upper_animcounter++;
		m_upper_animcounter %= MAXINT;
		m_upper_ac = m_upper_animcounter / ANIM_RATE;
		m_lower_animcounter++;
		m_lower_animcounter %= MAXINT;
		m_lower_ac = m_lower_animcounter / ANIM_RATE;
		m_upper_playerstate = Move;
		m_lower_playerstate = Move;

		m_BodyPos.setX(hx + mv);
		m_ShadowPos.setX(hx + PLAYER_SHADOW_WIDTH_POS + mv);
	}

}

//ダメージ時の点滅
void CPlayerControl::damageFlash(float time){
	float i = (time / FRAMETIME);
	m_flashImgTime = i / 7;
	m_flashImgTime = (int)m_flashImgTime % 2;
	if (time >= 1.5){		//無敵時間
		i = 0;
		m_flashImgTime = 0;
	}
}

void CPlayerControl::Draw(){
	if (m_flashImgTime == 0){
		//見た目の関係で影、下半身、上半身の順番で描画
		DrawGraph((int)m_ShadowPos.getX(), (int)m_ShadowPos.getY() + m_ShadowPos.getZ(), m_shadowimg, TRUE);
		//主人公の状態によって描画の変化
		if (m_purge == FALSE){
			switch (m_lower_playerstate){
			case Stand:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroLowerimg[m_lower_playerstate], TRUE);
				break;
			case Move:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroLowerimg[m_lower_playerstate + (m_lower_ac % 8)], TRUE);
				break;
			case Jump:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroLowerimg[m_lower_playerstate + (m_lower_ac % 5)], TRUE);
				break;
			}
		}
		//全てのモーションの画像を一つの一次元配列に入れられるなら変更のしようがある
		switch (m_playerstate){
		case P_NORMAL:
			switch (m_upper_playerstate){
			case Stand:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][m_upper_playerstate], TRUE);
				break;
			case Move:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][m_upper_playerstate + (m_upper_ac % 8)], TRUE);
				break;
			case Jump:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][m_upper_playerstate + (m_upper_ac % 5)], TRUE);
				break;
			default:
				break;
			}
			break;
		case P_KNIFE:
			switch (m_upper_playerstate){
			case Stand:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][17], TRUE);
				break;
			case Move:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][(m_upper_ac % 8)], TRUE);
				break;
			case Jump:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][8 + (m_upper_ac % 5)], TRUE);
				break;
			case Attack:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][13 + (m_upper_ac % 4)], TRUE);
				break;
			default:
				break;
			}
			break;
		case P_PISTOL:
			switch (m_upper_playerstate){
			case Stand:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][12], TRUE);
				break;
			case Move:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][(m_upper_ac % 4)], TRUE);
				break;
			case Jump:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][4 + (m_upper_ac % 5)], TRUE);
				break;
			case Attack:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][9 + (m_upper_ac % 3)], TRUE);
				break;
			default:
				break;
			}
			break;
		case P_SHOTTOGAN:
			switch (m_upper_playerstate){
			case Stand:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][14], TRUE);
				break;
			case Move:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][(m_upper_ac % 4)], TRUE);
				break;
			case Jump:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][4 + (m_upper_ac % 5)], TRUE);
				break;
			case Attack:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][9 + (m_upper_ac % 4)], TRUE);
				break;
			default:
				break;
			}
			break;
		case P_RIFLE:
			switch (m_upper_playerstate){
			case Stand:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][11], TRUE);
				break;
			case Move:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][(m_upper_ac % 4)], TRUE);
				break;
			case Jump:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][4 + (m_upper_ac % 5)], TRUE);
				break;
			case Attack:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][9 + (m_upper_ac % 2)], TRUE);
				break;
			default:
				break;
			}
			break;
		case P_PURGE:
			switch (m_upper_playerstate){
			case Stand:
			case Move:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][(m_upper_ac % 8)], TRUE);
				break;
			case Jump:
				DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][m_upper_playerstate + (m_upper_ac % 5)], TRUE);
				break;
			default:
				break;
			}
			break;
		case P_PURGE_ACTIVE:
			DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_playerstate][m_upper_ac / 2], TRUE);
			break;
		default:
			break;
		}
	}
}

float CPlayerControl::getMoveAmount(){
	//仮：移動量 = (ギア*基本速度-装備重量)*バフ効果
	return (m_gear * BASE_SCR_SPEED * 1.5f) * FRAMETIME;
}

void CPlayerControl::setEquipment(CItemData* item){
	if (m_purge == FALSE){
		PlaySoundMem(CSeManager::GetInstance()->getsnd(GET_SE), DX_PLAYTYPE_BACK);
		m_Equipment[item->m_type].m_img = item->m_img;
		m_Equipment[item->m_type].m_name = item->m_name;
		m_Equipment[item->m_type].m_type = item->m_type;
		m_Equipment[item->m_type].m_useful = item->m_useful;
		m_Equipment[item->m_type].m_attack_rate = item->m_attack_rate;
		if (item->m_type == WEAPON){
			m_attack_time = 100;
			m_playerstate = (PState)(item->m_name + 1);
		}
	}

}