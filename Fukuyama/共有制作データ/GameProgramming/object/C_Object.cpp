#include "C_Object.h"

float C_Object::m_Scroll = SCROLL_POINT;

void C_Object::Rect(C_Rectangle *image,const C_Vector3* pos){
	image->m_wide = (image->m_Right - image->m_Left) / 2;  //ポジションからC_Rectangleの左右までの距離
	image->m_high = (image->m_Top - image->m_Bottom);  //高さ
	image->m_Right = pos->x + image->m_wide;
	image->m_Left = pos->x - image->m_wide;
	image->m_Bottom = pos->z;
	image->m_Top = image->m_Bottom +image->m_high;
	return;
}

void C_Object::Scroll(C_Vector3 *m_pos,float m_Scroll){
	if (CKey::Push(VK_RIGHT) && m_Scroll >= DISPLAY_RIGHT){
		m_pos->x -= SCROLL_SPEED;
		if (m_id == E_PLAYER){
			m_Scroll -= SCROLL_SPEED;
		}
	}
	return;
}