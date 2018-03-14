#include "C_Player.h"

void C_Player::Update(){

	//�E�ړ�
	if (CKey::Push(VK_RIGHT)){
		m_Turn = E_RIGHT;
		m_Scroll += PLAYER_LR_SPEED;
		m_Position.x += PLAYER_LR_SPEED;
	}
	//���ړ�
	if (CKey::Push(VK_LEFT) && m_Position.x >= (-W_H) / 2){
		m_Turn = E_LEFT;
		m_Scroll -= PLAYER_LR_SPEED;
		m_Position.x -= PLAYER_LR_SPEED;
	}
	//��ړ�
	if (CKey::Push(VK_UP) && m_Position.z <= DISPLAY_TOP - 390){
		m_Position.z += PLAYER_UD_SPEED;
	}
	//���ړ�
	if (CKey::Push(VK_DOWN) && m_Position.z >= DISPLAY_BOTTOM){
		m_Position.z -= PLAYER_UD_SPEED;
	}
	m_Scroll = m_Position.x + SCROLL_POINT;
	C_Object::Rect(&m_image,&m_Position);
	C_Object::Scroll(&m_Position,m_Scroll);
}

void C_Test::Update(){
	C_Object::Rect(&m_image, &m_Position);
	C_Object::Scroll(&m_Position,m_Scroll);
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

	i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
	//�ҋ@���[�V�����̕`��
	if (m_Anime_Taiki >= 0 && m_Anime_Taiki <= 60){
		if (m_Turn == E_RIGHT)
			i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
		if (m_Turn == E_LEFT)
			i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
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

void C_Test::Draw(){
	glBegin(GL_TRIANGLES);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Left, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Top);
	glEnd();
}