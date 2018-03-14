#include "C_Player.h"

void C_Player::Update(){

	//�E�ړ�
	if (CKey::Push(VK_RIGHT)){
		m_Turn = E_RIGHT;
		m_Scroll += PLAYER_LR_SPEED;
		m_Right += PLAYER_LR_SPEED;
		m_Left += PLAYER_LR_SPEED;
	}
	//���ړ�
	if (CKey::Push(VK_LEFT)&&m_Left>=(-W_H)/2){
		m_Turn = E_LEFT;
		m_Scroll -= PLAYER_LR_SPEED;
		m_Right -= PLAYER_LR_SPEED;
		m_Left -= PLAYER_LR_SPEED;
	}
	//��ړ�
	if (CKey::Push(VK_UP) &&m_Bottom <= DISPLAY_TOP - 390){
		m_Bottom += PLAYER_UD_SPEED;
		m_Top += PLAYER_UD_SPEED;
	}
	//���ړ�
	if (CKey::Push(VK_DOWN) && m_Bottom >= DISPLAY_BOTTOM){
		m_Bottom -= PLAYER_UD_SPEED;
		m_Top -= PLAYER_UD_SPEED;
	}

		C_Rectangle::Scroll(this);              //�X�N���[������
}


//�v���C���[�̕`��
void C_Player::Draw(){

	//�A�j���[�V�����J�E���^��1�b����
	if (m_Anime_Taiki < 60)
		++m_Anime_Taiki;

	//�A�j���[�V�����J�E���^�����Z�b�g���A�o�ߎ���(�b)��ǉ�����
	else if (m_Anime_Taiki == 60){
		m_Anime_Taiki = 0;
		++m_Anime_Taiki_s;
	}

	i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 140, 5);
	//�ҋ@���[�V�����̕`��
	if (m_Anime_Taiki >= 0 && m_Anime_Taiki <= 60){
		if (m_Turn == E_RIGHT)
			i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 140, 5);
		if (m_Turn == E_LEFT)
			i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 90, 0, 140, 5);
	}

	//�ړ����[�V�����̕`��(������)
		if (CKey::Push(VK_LEFT)||CKey::Push(VK_UP)||CKey::Push(VK_DOWN)){
			//�A�j���[�V�����J�E���^��1�b����
			if (m_Anime < 60)++m_Anime;
			//�A�j���[�V�����J�E���^�����Z�b�g���A�o�ߎ���(�b)��ǉ�����
			if (m_Anime == 60){
				m_Anime = 0;
				++m_Anime_s;
			}
			if (m_Turn == E_LEFT){
			
			}

		}
		else{
			m_Anime = 0;
			m_Anime_s = 0;
		}
}