#include "player.h"
#include "player_manager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include <DxLib.h>
#include <stdio.h>
#include "map_manager.h"

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
{
	for (int i = 0; i < 3; i++){
		m_Equipment[i].m_img = 0;
		m_Equipment[i].m_name = (ItemName)0;
		m_Equipment[i].m_type = (ItemType)0;
		m_Equipment[i].m_useful = 0;
	}
	LoadDivGraph("media\\img\\top.png", ANIM_COUNT, 4, 4, 167, 190, m_heroUpperimg);
	LoadDivGraph("media\\img\\under.png", ANIM_COUNT, 4, 4, 167, 190, m_heroLowerimg);
	m_shadowimg = LoadGraph("media\\img\\Pshadow.png", TRUE);
	//CPlayerManager��CPlayerControl�̃A�h���X��n�����߂̊֐�
	CPlayerManager::GetInstance()->Init(this);
}

CPlayerControl::~CPlayerControl(){
}

void CPlayerControl::Update(/*CMapControl *Map,CItemControl *Item*/){
	m_upper_animcounter++;
	m_upper_animcounter %= MAXINT;
	m_upper_ac = m_upper_animcounter / ANIM_RATE;
	m_lower_animcounter++;
	m_lower_animcounter %= MAXINT;
	m_lower_ac = m_lower_animcounter / ANIM_RATE;
	
	//if (Map->getGoalFlag() != true){
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	float hx = m_BodyPos.getX();
	float hy = m_BodyPos.getY();
	float hz = m_BodyPos.getZ();

	if (!m_gear){
		m_lower_playerstate = Stand;
		if (m_upper_playerstate == Move)
			m_upper_playerstate = Stand;

	}
	if (m_jumping){
		m_jumppower -= GRAVITY;
		hy -= (m_jumppower * FRAMETIME);
	}

	float mv = P_SPEED * FRAMETIME;		//270pixel/s
	if (key & PAD_INPUT_LEFT){
		hx -= mv;
		m_gear = (m_BodyPos.getX() / (ONE_GEAR_SPACE));
		if (m_upper_playerstate != Jump && m_lower_playerstate != Jump){
			m_upper_playerstate = Move;
			m_lower_playerstate = Move;
		}
	}
	else if (key & PAD_INPUT_RIGHT){
		hx += mv;
		m_gear = (m_BodyPos.getX() / (ONE_GEAR_SPACE));
		if (m_upper_playerstate != Jump && m_lower_playerstate != Jump){
			m_upper_playerstate = Move;
			m_lower_playerstate = Move;
		}
	}
	if (key & PAD_INPUT_UP){
		hz -= mv;
		if (m_upper_playerstate != Jump && m_lower_playerstate != Jump){
			m_upper_playerstate = Move;
			m_lower_playerstate = Move;
		}
	}
	else if (key & PAD_INPUT_DOWN){
		hz += mv;
		if (m_upper_playerstate != Jump && m_lower_playerstate != Jump){
			m_upper_playerstate = Move;
			m_lower_playerstate = Move;
		}
	}

	if ((int)m_gear == 5){
		m_gear = m_gear + m_BodyPos.getX() / (ONE_GEAR_SPACE) / 3;
	}
	if ((int)m_gear == 0){
		m_gear = 0.0f;
	}


	//�ړ��͈͊O���ƍ��W�̈ړ��𖳌���
	if (hx < MOVEING_RANGE_LEFT)hx = m_BodyPos.getX();
	if (hx > MOVEING_RANGE_RIGHT) hx = m_BodyPos.getX();
	if (hz + PLAYER_LOWER_SIZE + PLAYER_SHADOW_HEIGHT_POS > MOVEING_RANGE_DOWN) hz = m_BodyPos.getZ();
	if (hz + PLAYER_LOWER_SIZE + PLAYER_SHADOW_HEIGHT_POS < MOVEING_RANGE_UP)hz = m_BodyPos.getZ();

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

		//�U��
	if (m_Equipment[WEAPON].m_name != NONE){
		switch (m_Equipment[WEAPON].m_name){
		case KNIFE:
			m_attack_time++;
			m_Equipment[WEAPON].m_useful--;
			if (IsXKeyTrigger(key) && m_attack_time > m_Equipment[WEAPON].m_attack_rate){
				m_Equipment[WEAPON].m_useful = 5;					//�U��ON
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

		//�e�Ƒ̂̏ꏊ���X�V
		m_BodyPos = CVector3D(hx,hy,hz);
		m_ShadowPos = CVector3D(hx + PLAYER_SHADOW_WIDTH_POS, 0,hz + PLAYER_SHADOW_HEIGHT_POS);


	//}
	//else{
		//goalpos��0�ɂȂ�܂łɒ�ʒu�ɂ��Ă���
		//goalpos��0�ɂȂ�ƃA�j���[�V�����J�n�@animconter�œ������Ǘ�����
		//��l�����ԂƏd�Ȃ�Ǝp�������A�N���A
		//��������key�ɓ���̏�����͂��A����������
	//}


}

void CPlayerControl::Draw(){
	//�����ڂ̊֌W�ŉe�A�����g�A�㔼�g�̏��Ԃŕ`��
	DrawGraph((int)m_ShadowPos.getX(), (int)m_ShadowPos.getY() + m_ShadowPos.getZ(), m_shadowimg, TRUE);
	//��l���̏�Ԃɂ���ĕ`��̕ω�
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

	switch (m_upper_playerstate){
	case Stand:
		DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_upper_playerstate], TRUE);
		break;
	case Move:
		DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_upper_playerstate + (m_upper_ac % 8)], TRUE);
		break;
	case Jump:
		DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() + m_BodyPos.getZ(), m_heroUpperimg[m_upper_playerstate + (m_upper_ac % 5)], TRUE);
		break;
	}
}

float CPlayerControl::getMoveAmount(){
	//���F�ړ��� = (�M�A*��{���x-�����d��)*�o�t����
	return (m_gear * BASE_SCR_SPEED * 1.5f) * FRAMETIME;
}

void CPlayerControl::setEquipment(CItemData* item){
	m_Equipment[item->m_type].m_img = item->m_img;
	m_Equipment[item->m_type].m_name = item->m_name;
	m_Equipment[item->m_type].m_type = item->m_type;
	m_Equipment[item->m_type].m_useful = item->m_useful;
	m_Equipment[item->m_type].m_attack_rate = item->m_attack_rate;
}