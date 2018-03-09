#include "CObjectBase.h"


CObjectBase::CObjectBase() {
	m_pos = CVector2D(0, 0);
	m_vec = CVector2D(0, 0);
	m_flipH = false;
	m_active = true;
	m_color = 0;
	m_type = 0;
	m_move = false;
}
void CObjectBase::Draw()
{
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos - m_scroll);
	m_img.Draw();
}
