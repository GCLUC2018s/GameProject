#include "player.h"
#include "player_manager.h"
#include "item_manager.h"
#include "DxLib.h"
#include <stdio.h>

CPlayerControl::CPlayerControl()
:CTask(0, eUDP_Player, eDWP_Player)
, m_gear(0)
, m_BodyPos(START_POSX, START_POSY)
, m_ShadowPos(START_POSX, START_POSY + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS)
{
	m_heroUpperimg = LoadGraph("media\\img\\knife_run_top.png", TRUE);
	m_heroLowerimg = LoadGraph("media\\img\\knife_run_under.png", TRUE);
	m_shadowimg = LoadGraph("media\\img\\Pshadow.png", TRUE);
	//CPlayerManager��CPlayerControl�̃A�h���X��n�����߂̊֐�
	CPlayerManager::GetInstance()->Init(this);
}

CPlayerControl::~CPlayerControl(){
}

void CPlayerControl::Update(/*CMapControl *Map,CItemControl *Item*/){

	

	//if (Map->getGoalFlag() != true){
		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		float hx = m_BodyPos.getX();
		float hy = m_BodyPos.getY();
		float mv = P_SPEED * FRAMETIME;		//200
		if (key & PAD_INPUT_LEFT){
			hx -= mv;
			m_gear = (m_BodyPos.getX() / (ONE_GEAR_SPACE));		//����if���̍팸�̂��߂����ɓ��Ԋu��gear�̐��l���ς��悤�ɂ��Ă���A�ύX���K�v�Ȃ�b���Ă���
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
			hy -= mv;
			/*if (m_playerstate != Jump)
				m_playerstate = Move;*/
	}
		else if (key & PAD_INPUT_DOWN){
			hy += mv;
			/*if (m_playerstate != Jump)
			m_playerstate = Move;*/
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
		if (hy + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS > MOVEING_RANGE_DOWN) hy = m_BodyPos.getY();
		if (hy + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS < MOVEING_RANGE_UP)hy = m_BodyPos.getY();
		
		//-------------------------------
		//��������A�C�e���Ƃ̓����蔻��
		//-------------------------------
		float ax1 = hx + 5;
		float ay1 = hy + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS + 5;
		float ax2 = hx + PLAYER_WIDE_SIZE - 5;
		float ay2 = hy + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS + PLAYER_HEIGHT_SIZE - 5;
		float bx1, bx2, by1, by2;
		
		//�A�C�e���̃��X�g���擾����
		auto Idata = CItemManager::GetInstance()->GetItemList();
		
		for (auto it = Idata.begin(); it != Idata.end(); it++){
			//�A�C�e���̓����蔻��͈̔́A�m�F�p�ɑ傫��
			bx1 = (*it)->GetPos().getX();
			by1 = (*it)->GetPos().getY();
			bx2 = (*it)->GetPos().getX() + 200;
			by2 = (*it)->GetPos().getY() + 200;

			if ((ax1 < bx2) && (bx1 < ax2) && (ay1 < by2) && (by1 < ay2)){
				//�A�C�e���Əd�Ȃ�ƃA�C�e���͏�������
				(*it)->SetKill();
				CItemManager::GetInstance()->Remove((*it));
				/*ItemData = Item->pickupItem(it->m_pos);
				m_Equipment[ItemData.m_type].m_img = ItemData.m_img;
				m_Equipment[ItemData.m_type].m_name = ItemData.m_name;
				m_Equipment[ItemData.m_type].m_type = ItemData.m_type;
				m_Equipment[ItemData.m_type].m_useful = ItemData.m_useful;*/
			}
		}
		//���^�]
			
		/*TP++;
		TP %= 60;
		if (TP == 0){
			Item->makeItem(CVector2D(600, 250), KNIFE);
			
		}*/
		//�e�Ƒ̂̏ꏊ���X�V
		m_BodyPos = CVector2D(hx, hy);
		m_ShadowPos = CVector2D(hx, hy + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS);


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
	DrawGraph((int)m_ShadowPos.getX(), (int)m_ShadowPos.getY(), m_shadowimg, TRUE);
	DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() /*+ PLAYER_LOWER_SIZE*/, m_heroLowerimg, TRUE);
	DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY(), m_heroUpperimg, TRUE);
}

float CPlayerControl::getMoveAmount(){
	//���F�ړ��� = (�M�A*��{���x-�����d��)*�o�t����
	return (m_gear * BASE_SCR_SPEED*1.5f) * FRAMETIME;
}