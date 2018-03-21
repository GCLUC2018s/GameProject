#include "CFire.h"
/*

»ìÒ@‰Í–ì
ˆê•”•ÒW@‹{ú±

*/

CFire::CFire(CObjectBase *ob) {
	m_effect_type = eFire;
	OB = dynamic_cast<CObjectBase*>(ob);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Fire"));
	m_img.SetSize(204, 245);
	m_img.SetCenter(204 / 2, 245);
	m_pos3D = OB->GetPos();
	m_pos3D.x += (OB->GetRect().m_left + OB->GetRect().m_right) / 2;
	m_pos3D.y += OB->GetRect().m_bottom;
	m_pos3D.z++;
	m_rect = CRect(-204 / 2, -245, 204 / 2, 0);
	m_rect_F = m_rect;
	m_color.w = 1.5;
	if (m_deathblow)
		m_color.w += 10;
	m_img.ChangeAnimation(0);
	CheckOverlap();
}

CFire::~CFire(){
}

void CFire::Update(){
//	m_pos3D = OB->GetPos();
	m_color.w -= 0.1;
	if (m_color.w <= 0) {
		SetKill();
	}
	m_img.UpdateAnimation();
	CheckOverlap();
}
