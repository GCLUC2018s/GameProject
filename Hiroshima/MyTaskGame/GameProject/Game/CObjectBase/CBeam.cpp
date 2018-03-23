#include "CBeam.h"


CBeam::CBeam(CVector2D pos) {
	m_effect_type = eBress;
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Effect_beam"));
	m_pos2D = pos;
	m_pos3D.x = pos.x;
	m_pos3D.y = pos.y;
	m_rect = CRect(-640, 0, 640, 960);
	m_img.SetCenter(640, 0);
	m_img.SetSize(1280, 960);
	CheckOverlap();
}

void CBeam::Update() {
	if (m_img.GetIndex() == 26)
		SetKill();
	m_img.ChangeAnimation(0, false);
	m_img.UpdateAnimation();
	CheckOverlap();
}

void CBeam::Draw() {
	m_img.SetPos(m_pos2D.x, m_pos2D.y - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7/*+ m_variation*/ - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
}