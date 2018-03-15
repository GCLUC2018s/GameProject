#include "CManhole.h"

//�T�C�Y�ݒ�Ə������R���X�g���N�^
//Init()�Ɠ����Ӗ�
C_Manhole::C_Manhole()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object, DISPLAY_RIGHT, 0, 0)
, m_UorD_rand(rand() % 3)
{
	//�V�[�h�ŗ�����������
	srand((unsigned)time(NULL));
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
}

//�X�V����
void C_Manhole::Update(){
	Scroll(&m_Position, m_Scroll);
	//�E�ӂ���ʍ��[�����������Ȃ����ꍇ
	if (m_image.m_Right<DISPLAY_LEFT){
		//�폜���āA�V�����ǉ�
		SetKill();
		new C_Manhole();
	}
	//�E�ӂ���ʍ��[�����傫���ꍇ
	else{
		//�X�N���[������
		
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
	//Texture�ݒ�
	//CTexture�N���X���C���X�^���X��
	CTexture mTexture;
	//Texture���[�h
	mTexture.Load("object/manhole.tga");
	//���W������
	mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 128, 128, 0);
	m_image.SetVertex(-64, 64, -64, 64);
}