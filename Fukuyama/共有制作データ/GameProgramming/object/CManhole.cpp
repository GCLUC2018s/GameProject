#include "CManhole.h"

//�T�C�Y�ݒ�Ə������R���X�g���N�^
//Init()�Ɠ����Ӗ�
C_Manhole::C_Manhole()
:C_Rectangle(E_OBJ, eUDP_Object, eDWP_Object)
, m_UorD_rand(rand() % 2)
{
	//Texture�ݒ�
	//CTexture�N���X���C���X�^���X��
	CTexture mTexturet;
	//Texture���[�h
	mTexturet.Load("Manhole.tga");
	//���W������
	mTexturet.DrawImage(-64, 64, -64, 64, 0, 128, 128, 0);
	//�V�[�h�ŗ�����������
	srand((unsigned)time(NULL));
	//x,y�̏����ʒu�����߂�
	m_PotisionX(DISPLAY_RIGHT);
	if (m_UorD_rand==0){
		m_PotisionY(Ypos_SetPos_Up);
	}
	else if (m_UorD_rand == 1){
		m_PotisionY(Ypos_SetPos_Down);
	}
}

//�}���z�[���̊ȈՏ㉺�|�W�V�����ݒ�
float C_Manhole::m_PotisionY(float m_V){
	float mv = m_V;
	m_Top +=mv;
	m_Bottom += mv;
	return mv;
}

//�}���z�[���̊ȈՍ��E�|�W�V�����ݒ�
float C_Manhole::m_PotisionX(float m_H){
	float mh = m_H;
	m_Left +=  mh;
	m_Right +=mh;
	return mh;
}

//�X�V����
void C_Manhole::Update(){

}

//�`�揈��
void C_Manhole::Draw(){
	m_Enabled = true;
	Render();
}