#include "CCollider.h"

bool C_BoxCollider::CCollisionX(C_Rectangle *mp_R1, const C_Rectangle &i_R2){
	mp_R1->m_Adjust = 0.0f;
	//mp_R1とi_R2がどちらも存在する場合
	if (mp_R1->m_Enabled&&i_R2.m_Enabled){
		if (mp_R1->m_Left >= i_R2.m_Right ||
			mp_R1->m_Right <= i_R2.m_Left ||
			mp_R1->m_Bottom >= i_R2.m_Top ||
			mp_R1->m_Top <= i_R2.m_Bottom){
			return false;
		}
		//mp_R1左、i_R2右判定の場合
		//左判定
		if (mp_R1->m_Left >= i_R2.m_Left){
			mp_R1->m_Adjust = i_R2.m_Right - mp_R1->m_Left;
			return true;
		}
		//mp_R1右、i_R2左判定の場合
		//右判定
		if (mp_R1->m_Right <= i_R2.m_Right){
			mp_R1->m_Adjust = i_R2.m_Left - mp_R1->m_Right;
			return true;
		}
	}
	return false;
}

bool C_BoxCollider::CCollisionY(C_Rectangle *mp_R1, const C_Rectangle &i_R2){
	mp_R1->m_Adjust = 0.0f;
	//mp_R1とi_R2がどちらも存在する場合
	if (mp_R1->m_Enabled&&i_R2.m_Enabled){
		if (mp_R1->m_Left >= i_R2.m_Right ||
			mp_R1->m_Right <= i_R2.m_Left ||
			mp_R1->m_Bottom >= i_R2.m_Top ||
			mp_R1->m_Top <= i_R2.m_Bottom){
			return false;
		}
		//mp_R1下、i_R2上判定
		//上判定
		if (mp_R1->m_Bottom >= i_R2.m_Bottom){
			mp_R1->m_Adjust = i_R2.m_Top - mp_R1->m_Bottom;
			return true;
		}
		//mp_R1上、i_R2下判定
		//下判定
		if (mp_R1->m_Top <= i_R2.m_Top){
			mp_R1->m_Adjust = i_R2.m_Bottom - mp_R1->m_Top;
			return true;
		}
	}
	return false;
}