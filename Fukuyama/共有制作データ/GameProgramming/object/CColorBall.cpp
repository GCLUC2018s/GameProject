#include "CColorBall.h"

void C_ColorBall::Init(){

	if (C_Player::m_Playerpoint->m_Throw==E_THROW){
		m_State = E_NAGE;
		//�v���C���[�̃X�e�[�^�X�𓊂��Ă��Ȃ��ɕύX���܂�
		C_Player::m_Playerpoint->m_Throw = E_NTHROW;
	}
	if(C_Player::m_Playerpoint->m_Set==E_SET){
		m_State=E_OKI;
		//�v���C���[�̃X�e�[�^�X��ݒu���Ă��Ȃ��ɕύX���܂�
		C_Player::m_Playerpoint->m_Set = E_NSET;
	}

	//�J���[�{�[���̉e�̏����ʒu�̉��s�𒲐����܂�
	i_Throwpos = C_Player::m_Playerpoint->m_Position;
	//�J���[�{�[���̉e�ƃ{�[���𓯊�
	m_Position = i_Throwpos;
	ShadowPos = i_Throwpos;

	//�������J���[�{�[���̏ꍇ
	if (m_State == E_NAGE){
		//�J���[�{�[���̏����ʒu�̒���
		//�E����
		if (C_Player::m_Playerpoint->m_Turn == E_RIGHT){
			m_Position.x += 40;
			m_Position.z += 80;
			ShadowPos.x = m_Position.x;
			//�J���[�{�[���̏���
			m_Speed = C_Vector3(500, 4, 0);
		}
		//������
		else if (C_Player::m_Playerpoint->m_Turn == E_LEFT){
			m_Position.x -= 40;
			m_Position.z += 80;
			ShadowPos.x = m_Position.x;
			//�J���[�{�[���̏���
			m_Speed = C_Vector3(-500, 4, 0);
		}
	}
	//�{�[���̐ݒu
	else if (m_State == E_OKI){
		//�E����
		if (C_Player::m_Playerpoint->m_Turn == E_RIGHT){
			m_Position.x += 10;
			ShadowPos.x = m_Position.x;
		}
		//������
		else if (C_Player::m_Playerpoint->m_Turn == E_LEFT){
			m_Position.x -= 10;
			ShadowPos.x = m_Position.x;
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

	//�e�̈ʒu���J���[�{�[���Ɠ������܂�
	ShadowPos.x = m_Position.x;

	Rect(&m_image, &m_Position);             //�摜�̈ʒu��m_Position�Ɠ������܂�
	Scroll(&m_Position, m_Scroll);           //�J���[�{�[���̃X�N���[�����������܂�
	Rect(&i_Shadow, &ShadowPos);             //�e�̈ʒu��ShadowPos�Ɠ������܂�
	Scroll(&ShadowPos, m_Scroll);           //�e�̃X�N���[�����������܂�

	if(m_Position.x <= -(W_H / 2)){
		SetKill();
	}
}

void C_ColorBall::Draw(){

	//�e�̕`��
	i_Chara_Motion_2.DrawImage(i_Shadow.m_Left, i_Shadow.m_Right, i_Shadow.m_Bottom - 3, i_Shadow.m_Top - 3, 630, 720, 275, 140);

	//�J���[�{�[���̕`��
	i_ColorBall.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 128, 128, 0);

}