#include "CManhole.h"

//�T�C�Y�ݒ�Ə������R���X�g���N�^
//Init()�Ɠ����Ӗ�
C_Manhole::C_Manhole()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object)
, m_UorD_rand(rand() % 3)
{
	//�V�[�h�ŗ�����������
	srand((unsigned)time(NULL));
	//x,y�̏����ʒu�����߂�
	m_Position.x+=DISPLAY_RIGHT;
	if (m_UorD_rand==0){
		m_Position.y+=Ypos_SetPos_Center;
	}
	else if (m_UorD_rand == 1){
		m_Position.y+=Ypos_SetPos_Up;
	}
	else if (m_UorD_rand == 2){
		m_Position.y+=Ypos_SetPos_Down;
	}
}

//�X�V����
void C_Manhole::Update(){
}

//�`�揈��
void C_Manhole::Draw(){
	//Texture�ݒ�
	//CTexture�N���X���C���X�^���X��
	CTexture mTexturet;
	//Texture���[�h
	mTexturet.Load("manhole.tga");
	//���W������
	mTexturet.DrawImage(-64, 64, -64, 64, 0, 128, 128, 0);
}