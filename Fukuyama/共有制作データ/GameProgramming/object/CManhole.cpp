#include "CManhole.h"
#include "../CCollider.h"

//Texture�ݒ�
//CTexture�N���X���C���X�^���X��
CTexture mTexturem;

int C_Manhole::main(){
	//�V�[�h�ŗ�����������
	srand((unsigned)time(NULL));
	return NULL;
}
//�T�C�Y�ݒ�Ə������R���X�g���N�^
//Init()�Ɠ����Ӗ�
C_Manhole::C_Manhole()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object, DISPLAY_RIGHT, 0, 0)
, m_UorD_rand(rand() % 3)
{
	//0�̏ꍇ�A�^�񒆂ɔz�u
	if (m_UorD_rand == 0){
		m_Position.z += Zpos_SetPos_Center;
	}
	//1�̏ꍇ�A��ɔz�u
	else if (m_UorD_rand == 1){
		m_Position.z += Zpos_SetPos_Up;
	}
	//2�̏ꍇ�A���ɔz�u
	else if (m_UorD_rand == 2){
		m_Position.z += Zpos_SetPos_Down;
	}
	m_image.SetVertex(-64, 64, -64, 64);
	//Texture���[�h
	mTexturem.Load("object/manhole.tga");
}

//�X�V����
void C_Manhole::Update(){
	//�X�N���[������
	Scroll(&m_Position, m_Scroll);
	//�E�ӂ���ʍ��[�����������Ȃ����ꍇ
	if (m_Position.x<DISPLAY_LEFT){
		//�폜���āA�V�����ǉ�
		SetKill();
		new C_Manhole();
	}
	if (CKey::Push('A')){
		m_Position.x -= TestSpeed;
	}
	//�`��
	Rect(&m_image, &m_Position);
	printf("%f\n", m_image.m_Top);
}

//�`�揈��
void C_Manhole::Draw(){
	//���W������
	mTexturem.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 128, 128, 0);
}
