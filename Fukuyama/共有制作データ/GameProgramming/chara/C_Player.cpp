#include "C_Player.h"
<<<<<<< HEAD

void C_Player::Update(){

=======
#include <stdio.h>

#define PLAYER_SCROLL ((100-SCROLL_PERCENTAGE)/100)*1200    //�v���C���[�ƃX�N���[����_�̋���
#define PLAYER_START_BOTTOM -135               //�v���C���[�̏����ʒu�i���j���㉺�ʒu�����͉��̂ݕύX���Ă��������B
#define PLAYER_START_TOP (PLAYER_START_BOTTOM+135)          //�v���C���[�̏����ʒu�i��j
#define PLAYER_START_RIGHT (-PLAYER_SCROLL)          //�v���C���[�̏����ʒu�i�E�j
#define PLAYER_START_LEFT (PLAYER_START_RIGHT-90)       //�v���C���[�̏����ʒu�i���j

void C_Player::Init(){
	//�A�j���[�V�����J�E���^�̏�����
	m_Anime = 0;
	m_Anime_s = 0;
	//�v���C���[�̃T�C�Y
	SetVertex(PLAYER_START_LEFT, PLAYER_START_RIGHT, PLAYER_START_BOTTOM, PLAYER_START_TOP);
}


void C_Player::Update(){

	//�A�j���[�V�����J�E���^�������ҋ@
	if (!(CKey::Once(VK_RIGHT) || CKey::Once(VK_LEFT)
		|| CKey::Once(VK_UP) || CKey::Once(VK_DOWN))){
		if (m_Anime != 0)m_Anime = 0;
		if (m_Anime_s != 0)m_Anime_s = 0;
	}

	//�A�j���[�V�����J�E���^��1�b����
	if (m_Anime_Taiki < 60)++m_Anime_Taiki;
	//�A�j���[�V�����J�E���^�����Z�b�g���A�o�ߎ���(�b)��ǉ�����
	else if (m_Anime_Taiki == 60){
		m_Anime_Taiki = 0;
		++m_Anime_Taiki_s;
	}

>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
	//�E�ړ�
	if (CKey::Push(VK_RIGHT)){
		m_Turn = E_RIGHT;
		m_Right += PLAYER_LR_SPEED;
		m_Left += PLAYER_LR_SPEED;
	}
	//���ړ�
<<<<<<< HEAD
	if (CKey::Push(VK_LEFT)&&m_Left>=(-W_H)/2){
=======
	else if (CKey::Push(VK_LEFT)){
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
		m_Turn = E_LEFT;
		m_Right -= PLAYER_LR_SPEED;
		m_Left -= PLAYER_LR_SPEED;
	}
	//��ړ�
	else if (CKey::Push(VK_UP) && (m_Bottom >= DISPLAY_BOTTOM&&m_Bottom <= DISPLAY_TOP - 390)){
		m_Bottom += PLAYER_UD_SPEED;
		m_Top += PLAYER_UD_SPEED;
	}
	//���ړ�
	else if (CKey::Push(VK_DOWN) && (m_Bottom >= DISPLAY_BOTTOM&&m_Bottom <= DISPLAY_TOP - 390)){
		m_Bottom -= PLAYER_UD_SPEED;
		m_Top -= PLAYER_UD_SPEED;
	}

<<<<<<< HEAD
		C_Scroll::Scroll(this);              //�X�N���[������
=======
	C_Rectangle::Scroll(m_Left, m_Right);              //�X�N���[������
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
}


//�v���C���[�̕`��
void C_Player::Draw(){
<<<<<<< HEAD

	//�A�j���[�V�����J�E���^��1�b����
	if (m_Anime_Taiki < 60)
		++m_Anime_Taiki;

	//�A�j���[�V�����J�E���^�����Z�b�g���A�o�ߎ���(�b)��ǉ�����
	else if (m_Anime_Taiki == 60){
		m_Anime_Taiki = 0;
		++m_Anime_Taiki_s;
	}

	i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 140, 5);
=======
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
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