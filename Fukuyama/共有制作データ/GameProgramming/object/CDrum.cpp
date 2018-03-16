#include "CDrum.h"
//�e�N�X�`���N���X���C���X�^���X��
CTexture mTexture;
//�A�j���[�V�����J�E���g
int m_DrumAnimationCount = 60;
//�R���X�g���N�^�ŏ�����
C_Drum::C_Drum()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object, DISPLAY_LEFT, 0, 0)
, m_DrumPos_Random(rand() % 3)
{
	//�V�[�h�ŗ�����������
	srand((unsigned)time(NULL));
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
	Scroll(&m_Position, m_Scroll);
	m_Position.x += 2;
	m_DrumAnimationCount--;
	if (m_DrumAnimationCount >= 48){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 128, 128, 0);
	}
	else if (m_DrumAnimationCount <= 48 && m_DrumAnimationCount >= 36){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 512, 640, 128, 0);
	}
	else if (m_DrumAnimationCount <= 36 && m_DrumAnimationCount >= 24){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 384, 512, 128, 0);
	}
	else if (m_DrumAnimationCount <= 24 && m_DrumAnimationCount >= 12){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 256, 384, 128, 0);
	}
	else if (m_DrumAnimationCount <= 12 && m_DrumAnimationCount >= 0){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 128, 256, 128, 0);
	}
	else{
		m_DrumAnimationCount = 60;
	}
}

//�`�揈��
void C_Drum::Draw(){
	m_image.SetVertex(-64, 64, -64, 64);
	Rect(&m_image, &m_Position);
}

