#include "CManhole.h"

//�T�C�Y�ݒ�Ə������R���X�g���N�^
//Init()�Ɠ����Ӗ�
C_Manhole::C_Manhole()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object, DISPLAY_RIGHT, 0, Ypos_SetPos_Center)
, m_UorD_rand(rand() % 3)
{
	//�V�[�h�ŗ�����������
	srand((unsigned)time(NULL));
	//x,y�̏����ʒu�����߂�
	//m_Position.x+=DISPLAY_RIGHT;
	//m_Position.y+=Ypos_SetPos_Center;
	// if (m_UorD_rand == 1){
	//	m_Position.y+=Ypos_SetPos_Up;
	//}
	//else if (m_UorD_rand == 2){
	//	m_Position.y+=Ypos_SetPos_Down;
	//}
}

//�X�V����
void C_Manhole::Update(){
	Rect(&m_image, &m_Position);
}

//�`�揈��
void C_Manhole::Draw(){
	//Texture�ݒ�
	//CTexture�N���X���C���X�^���X��
	CTexture mTexture;
	//Texture���[�h
	mTexture.Load("manhole.tga");
	//���W������
	mTexture.DrawImage(-64, 64, -64, 64, 0, 128, 128, 0);
}