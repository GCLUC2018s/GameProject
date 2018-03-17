#include "CCollider.h"

bool C_BoxCollider::CCollisionX(C_Rectangle *mp_R1, const C_Rectangle &i_R2){
	mp_R1->m_Adjust = 0.0f;
	//mp_R1��i_R2���ǂ�������݂���ꍇ
	if (mp_R1->m_Enabled&&i_R2.m_Enabled){
		if (mp_R1->m_Left >= i_R2.m_Right ||
			mp_R1->m_Right <= i_R2.m_Left ||
			mp_R1->m_Bottom >= i_R2.m_Top ||
			mp_R1->m_Top <= i_R2.m_Bottom){
			return false;
		}
		//mp_R1���Ai_R2�E����̏ꍇ
		//������
		if (mp_R1->m_Left >= i_R2.m_Left){
			mp_R1->m_Adjust = i_R2.m_Right - mp_R1->m_Left;
			return true;
		}
		//mp_R1�E�Ai_R2������̏ꍇ
		//�E����
		if (mp_R1->m_Right <= i_R2.m_Right){
			mp_R1->m_Adjust = i_R2.m_Left - mp_R1->m_Right;
			return true;
		}
	}
	return false;
}

bool C_BoxCollider::CCollisionY(C_Rectangle *mp_R1, const C_Rectangle &i_R2){
	mp_R1->m_Adjust = 0.0f;
	//mp_R1��i_R2���ǂ�������݂���ꍇ
	if (mp_R1->m_Enabled&&i_R2.m_Enabled){
		if (mp_R1->m_Left >= i_R2.m_Right ||
			mp_R1->m_Right <= i_R2.m_Left ||
			mp_R1->m_Bottom >= i_R2.m_Top ||
			mp_R1->m_Top <= i_R2.m_Bottom){
			return false;
		}
		//mp_R1���Ai_R2�㔻��
		//�㔻��
		if (mp_R1->m_Bottom >= i_R2.m_Bottom){
			mp_R1->m_Adjust = i_R2.m_Top - mp_R1->m_Bottom;
			return true;
		}
		//mp_R1��Ai_R2������
		//������
		if (mp_R1->m_Top <= i_R2.m_Top){
			mp_R1->m_Adjust = i_R2.m_Bottom - mp_R1->m_Top;
			return true;
		}
	}
	return false;
}