#include "CFire.h"
/*

»ìÒ@‰Í–ì

*/

CFire::CFire(CObjectBase *ob){
	OB = dynamic_cast<CObjectBase*>(ob);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Fire"));
	m_img.SetSize(204, 245);
	m_img.SetCenter(204 / 2, 245);
	m_pos3D = OB->GetPos();
	m_pos3D.x = (OB->GetRect().m_right + OB->GetRect().m_left);
	m_pos3D.y = OB->GetRect().m_bottom;
	m_rect = CRect(40, 32, 150, 0);
	m_rect_F = m_rect;
	m_color.w = 1.5;
	m_img.ChangeAnimation(0);
}

CFire::~CFire(){
}

void CFire::Update(){
	m_pos3D = OB->GetPos();
	m_color.w -= 0.1;
	if (m_color.w <= 0) {
		SetKill();
	}
	m_img.UpdateAnimation();
	CheckOverlap();
}
