#include "CDrum.h"
//�e�N�X�`���N���X���C���X�^���X��
CTexture mTexture;

int C_Drum::Dmain(){
	//�V�[�h�ŗ�����������
	srand((unsigned)time(NULL));
	return 0;
}

//�A�j���[�V�����J�E���g
int m_DrumAnimationCount = 30;
//�h�����ʂ̈ړ�����
#define Drum_Move 10
//�R���X�g���N�^�ŏ�����
C_Drum::C_Drum()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object, DISPLAY_RIGHT, 0, 0)
, m_DrumPos_Random(rand() % 3)
{
	//0�̏ꍇ�A�^�񒆂ɔz�u
	if (m_DrumPos_Random == 0){
		m_Position.z += Zpos_SetPos_Center;
	}
	//1�̏ꍇ�A��ɔz�u
	else if (m_DrumPos_Random == 1){
		m_Position.z += Zpos_SetPos_Up;
	}
	//2�̏ꍇ�A���ɔz�u
	else if (m_DrumPos_Random == 2){
		m_Position.z += Zpos_SetPos_Down;
	}
	mTexture.Load("object/Drum.tga");
}

//�X�V����
void C_Drum::Update(){
	//��ʍ��[�ɍs������
	if (m_Position.x < DISPLAY_LEFT){
		SetKill();
		new C_Drum();
	}
	m_DrumAnimationCount--;
	m_Position.x -= Drum_Move;
	//�A�j���[�V��������
	if (m_DrumAnimationCount >= 24){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 128, 128, 0);
	}
	else if (m_DrumAnimationCount <= 24 && m_DrumAnimationCount >= 18){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 128, 256, 128, 0);
	}
	else if (m_DrumAnimationCount <= 18 && m_DrumAnimationCount >= 12){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 256, 384, 128, 0);
	}
	else if (m_DrumAnimationCount <= 12 && m_DrumAnimationCount >= 6){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 384, 512, 128, 0);
	}
	else if (m_DrumAnimationCount <= 6 && m_DrumAnimationCount >= 0){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 512, 640, 128, 0);
	}
	else{
		m_DrumAnimationCount = 30;
	}
}

//�`�揈��
void C_Drum::Draw(){
	m_image.SetVertex(-64, 64, -64, 64);
	Rect(&m_image, &m_Position);
}

