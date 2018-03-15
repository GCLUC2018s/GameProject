#include "C_Object.h"

float C_Object::m_Scroll = SCROLL_POINT;

void C_Object::Rect(C_Rectangle *m_image,C_Vector3* pos){
	m_image->m_wide = (m_image->m_Right - m_image->m_Left) / 2;  //ポジションからC_Rectangleの左右までの距離
	m_image->m_high = (m_image->m_Top - m_image->m_Bottom);  //高さ
	m_image->m_Right = pos->x + m_image->m_wide;
	m_image->m_Left = pos->x - m_image->m_wide;
	m_image->m_Bottom = pos->z;
	m_image->m_Top = m_image->m_Bottom +m_image->m_high;
	return;
}

void C_Object::Scroll(C_Vector3 *m_pos,float m_Scroll){
	if (CKey::Push(VK_RIGHT) && m_Scroll >= DISPLAY_RIGHT){
		m_Position.x -= SCROLL_SPEED;
		m_Scroll -= SCROLL_SPEED;
	}
	return;
}