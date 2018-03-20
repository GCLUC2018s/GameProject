#include "CPanchEF.h"
#include "../CPlayer/CPlayer.h"

#define PANCH_CENTER_X 64
#define PANCH_CENTER_Y 24

CPanchEF::CPanchEF(bool frip, CPlayer *pl, int anim_num)
{
	PL = dynamic_cast<CPlayer*>(pl);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Effect_panch"));
	m_img.SetSize(256, 256);
	m_img.SetCenter(PANCH_CENTER_X, PANCH_CENTER_Y);
	if (frip) {
		if (anim_num == eAnimEffectAttack3)
			m_rect = CRect(-127 + PANCH_CENTER_X * 2, 0, -157 + PANCH_CENTER_X * 2, 150);
		else
			m_rect = CRect(-127 + PANCH_CENTER_X * 2, 0, -170 + PANCH_CENTER_X * 2, 150);
	}
	else {
		if (anim_num == eAnimEffectAttack3)
			m_rect = CRect(127, 0, 157, 150);
		else
			m_rect = CRect(127, 0, 170, 150);
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

