#include "CDrum.h"

C_Drum::C_Drum()
:m_DrumPos_Random(rand() % 3)
, C_Rectangle(E_OBJ, eUDP_Object, eDWP_Object)
{
	//�h�����ʂ�X�|�W�V�����ݒ�
	m_PotisionX(DISPLAY_RIGHT);
	//�V�[�h�ŗ���������
	srand((unsigned)time(NULL));
	//
	switch (m_DrumPos_Random){
		//case 0�̎�
		//�h�����ʂ̈ʒu��^�񒆂�
	case 0:
		m_PotisionY(Ypos_SetPos_Center);
		break;
		//case 1�̎�
		//�h�����ʂ̈ʒu�����
	case 1:
		m_PotisionY(Ypos_SetPos_Up);
		break;
	}
}

//�X�V����
void C_Drum::Update(){

}

//�`�揈��
void C_Drum::Draw(){

}

