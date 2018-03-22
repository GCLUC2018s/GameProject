#include "CBeam.h"


CBeam::CBeam(CVector2D pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Effect_beam"));
	m_pos2D = pos;
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
}