#include "CCleave.h"


CCleave::CCleave(CVector2D pos) {
	m_effect_type = eBress;
	m_pos2D = pos;
	m_pos3D.x = pos.x;
	m_pos3D.y = pos.y;
	m_color.w = 2.0f;
	m_rect = CRect(-640, 120, -320, 960);
}

void CCleave::Update() {
}

void CCleave::Draw() {
	m_img.SetPos(m_pos2D.x, m_pos2D.y - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7/*+ m_variation*/ - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
}