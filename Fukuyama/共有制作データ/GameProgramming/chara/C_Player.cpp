#include "C_Player.h"
#include <stdio.h>

void C_Player::Init(){
	m_Enabled = true;
	//�A�j���[�V�����J�E���^�̏�����
	m_Anime = 0;
	m_Anime_s = 0;
	//�v���C���[�̃T�C�Y
	SetVertex(0,90 ,0 ,135 );
	//�L�����N�^�[�A�j���[�V�����摜�̓ǂݍ���
	i_Chara_Motion_1.Load("image/chara/chara_motion_1.tga");
	i_Chara_Motion_2.Load("image/chara/chara_motion_2_16bit.tga");
	printf("%f\n%f\n%f\n%f\n", m_Left, m_Right, m_Bottom, m_Top);
	m_Turn = E_RIGHT;
}


void C_Player::Update(){

	//�A�j���[�V�����J�E���^��1�b����
	if (m_Anime_Taiki < 60)++m_Anime_Taiki;
	//�A�j���[�V�����J�E���^�����Z�b�g���A�o�ߎ���(�b)��ǉ�����
	else if (m_Anime_Taiki == 60){
		m_Anime_Taiki = 0;
		++m_Anime_Taiki_s;
	}

	//�E�ړ�
	if (CKey::Push(VK_RIGHT)){
		m_Turn = E_RIGHT;
		m_Right += PLAYER_LR_SPEED;
		m_Left += PLAYER_LR_SPEED;
	}
	//���ړ�
	if (CKey::Push(VK_LEFT)){
		m_Turn = E_LEFT;
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

	C_Scroll::Scroll(m_Left, m_Right);              //�X�N���[������
}


//�v���C���[�̕`��
void C_Player::Draw(){
	C_Rectangle::Render();
	i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 140, 5);
	//�ҋ@���[�V�����̕`��
	if (!(CKey::Push(VK_RIGHT)
		|| CKey::Push(VK_LEFT)
		|| CKey::Push(VK_UP)
		|| CKey::Push(VK_DOWN))){
		if (m_Anime_Taiki >= 0){
			if (m_Turn == E_RIGHT)
				i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 135, 0);
			if (m_Turn == E_LEFT)
				i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 90, 0, 135, 0);
		}
		//1�b�ŃA�j���[�V�����J�E���^�����Z�b�g���܂�
		else if (m_Anime_Taiki_s == 1){
			m_Anime_Taiki = 0;
			m_Anime_Taiki_s = 0;
		}
	}
	//�ړ����[�V�����̕`��
	else{
		//�A�j���[�V�����J�E���^��1�b����
		if (m_Anime < 60)++m_Anime;
		//�A�j���[�V�����J�E���^�����Z�b�g���A�o�ߎ���(�b)��ǉ�����
		else if (m_Anime == 60){
			m_Anime = 0;
			++m_Anime_s;
		}
	}
}