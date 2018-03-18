#include "CColorBall.h"


void C_ColorBall::Init(){
	if (C_Player::m_Playerpoint->m_Anime_Throw <= THROW_ANIME + 1){
		m_Anime_Throw = E_THROW;
	}
	else{
		m_Anime_Throw = E_NTHROW;
	}
	//�J���[�{�[���̉e�̏����ʒu�̉��s�𒲐����܂�
	i_Throwpos = C_Player::m_Playerpoint->m_Position;
	//�J���[�{�[���̉e�ƃ{�[���𓯊�
	m_Position = i_Throwpos;

	//�������J���[�{�[���̏ꍇ
	if (m_State == E_NAGE){
		//�J���[�{�[���̏����ʒu�̒���
		//�E����
		if (C_Player::m_Playerpoint->m_Turn == E_RIGHT){
			m_Position.x += 40;
			m_Position.z += 80;
			//�J���[�{�[���̏���
			m_Speed = C_Vector3(500, 4, 0);
		}
		//������
		else if (C_Player::m_Playerpoint->m_Turn == E_LEFT){
			m_Position.x -= 40;
			m_Position.z += 80;
			//�J���[�{�[���̏���
			m_Speed = C_Vector3(-500, 4, 0);
		}
	}
	else{
		//�J���[�{�[���̏����ʒu�̒���
		//�E����
		if (C_Player::m_Playerpoint->m_Turn == E_RIGHT){
			m_Position.x += 35;
		}
		//������
		else if (C_Player::m_Playerpoint->m_Turn == E_LEFT){
			m_Position.x -= 35;
		}
	}

}

void C_ColorBall::Update()
{
	//Init��1�x�����Ăт܂��i�R���X�g���N�^�ł�m_Playerpoint���G���[�ɂȂ邽��Init�ŏ������܂��j
	if (init == false){
		Init();
		init = true;
	}

	//�������J���[�{�[���̏ꍇ
	if (m_State == E_NAGE){
		//�d�͉����x�𑬓x�֔��f
		m_Speed.x += m_Gravity.x*m_Deltatime;
		m_Speed.y += m_Gravity.y*m_Deltatime;
		m_Speed.z += m_Gravity.z*m_Deltatime;

		//���x�����ƂɃ|�W�V�������X�V
		m_Position.x += m_Speed.x*m_Deltatime;
		m_Position.y += m_Speed.y*m_Deltatime;
		m_Position.z += m_Speed.z*m_Deltatime;

		m_Position.z += m_Speed.y;

		//�J���[�{�[�����n�ʂɗ�����Ə����܂�
		if (m_Position.z <= i_Throwpos.z){
			SetKill();
		}
	}

	Rect(&m_image, &m_Position);             //�摜�̈ʒu��m_Position�Ɠ������܂�
	Scroll(&m_Position, m_Scroll);           //�X�N���[�����������܂�
}

void C_ColorBall::Draw(){

	//�J���[�{�[���̕`��
	i_ColorBall.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);

}