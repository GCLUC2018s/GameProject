#include "CObjectBase.h"

CVector2D CObjectBase::m_scroll(0, 0);

CObjectBase::CObjectBase(int id, int updatePrio, int drawPrio) :
	CTask(id, updatePrio, drawPrio) {
	m_pos3D = CVector3D(0, 0, 0);
	m_vec3D = CVector3D(0, 0, 0);
	m_flipH = false;
	m_color = 0;
	m_type = 0;
	m_move = false;
}
void CObjectBase::Draw()
{
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_scroll.x, m_pos3D.y - m_scroll.y);
	m_img.Draw();
}
