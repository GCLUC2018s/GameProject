#include "C_Spray.h"


void C_Spray::Init(){

	//�J���[�{�[���̉e�̏����ʒu�̉��s�𒲐����܂�
	i_ShadowPos = C_Player::m_Playerpoint->m_Position;
	//�J���[�{�[���̉e�ƃ{�[���𓯊�
	m_Position = i_ShadowPos;

	//�J���[�{�[���̏����ʒu�̒���
	//�E����
	if (C_Player::m_Playerpoint->m_Turn == E_RIGHT){
		m_Position.x += 40;
		m_Position.z += 70;
	}
	//������
	else if (C_Player::m_Playerpoint->m_Turn == E_LEFT){
		m_Position.x -= 40;
		m_Position.z += 70;
	}
}

void C_Spray::Update(){

	//Init��1�x�����Ăт܂��i�R���X�g���N�^�ł�m_Playerpoint���G���[�ɂȂ邽��Init�ŏ������܂��j
	if (init == false){
		Init();
		init = true;
	}


}

void C_Spray::Draw(){

	//�A���t�@�u�����h��L���ɂ���
	glEnable(GL_BLEND);
	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_TRIANGLES);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Left, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Top);
	glEnd();

	//�A���t�@�u�����h�𖳌�
	glDisable(GL_BLEND);
	//�e�N�X�`���𖳌�
	glDisable(GL_TEXTURE_2D);

}