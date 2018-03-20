#include "CPanchEF.h"
#include "../CPlayer/CPlayer.h"

#define PANCH_CENTER_X 64
#define PANCH_CENTER_Y 24

CPanchEF::CPanchEF(bool frip, CPlayer *pl, int anim_num) : CObjectBase(eID_Effect, eU_Effect, eD_Effect)
{
	PL = dynamic_cast<CPlayer*>(pl);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Effect_panch"));
	m_img.SetSize(256, 256);
	m_img.SetCenter(PANCH_CENTER_X, PANCH_CENTER_Y);
	if (frip) {
		if (anim_num == eAnimEffectAttack3)
			m_rect = CRect(-127 + PANCH_CENTER_X * 2, 0, -157 + PANCH_CENTER_X * 2, 215);
		else
			m_rect = CRect(-127 + PANCH_CENTER_X * 2, 0, -170 + PANCH_CENTER_X * 2, 215);
	}
	else {
		if (anim_num == eAnimEffectAttack3)
			m_rect = CRect(127, 0, 157, 215);
		else
			m_rect = CRect(127, 0, 170, 215);
	}
	m_color.w = 1.5;
	m_pos3D = PL->GetPos();
	m_flipH = frip;
	m_img.ChangeAnimation(anim_num);
	CheckOverlap();
}

void CPanchEF::Update()
{
	m_pos3D = PL->GetPos();
	m_color.w -= 0.1;
	if (m_color.w <= 0) {
		SetKill();
	}
	m_img.UpdateAnimation();
	CheckOverlap();
}

void CPanchEF::Draw()
{
	m_img.SetFlipH(!m_flipH);
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
}
