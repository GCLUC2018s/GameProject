#include "CDrum.h"

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
}

//�X�V����
void C_Drum::Update(){

}

//�`�揈��
void C_Drum::Draw(){

}

