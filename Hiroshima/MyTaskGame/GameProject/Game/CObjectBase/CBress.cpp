#include "CBress.h"


CBress::CBress(CVector2D pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Effect_bress"));
	m_pos2D = pos;
	m_img.SetCenter(960, 320);
	m_img.SetSize(960, 640);
	CheckOverlap();
}

void CBress::Update() {
	if (m_img.GetIndex() == 19)
		SetKill();
	m_img.ChangeAnimation(0, false);
	m_img.UpdateAnimation();
	CheckOverlap();
}

void CBress::Draw() {
	m_img.SetPos(m_pos2D.x, m_pos2D.y - m_scroll.y);
	m_img.Draw();
}
