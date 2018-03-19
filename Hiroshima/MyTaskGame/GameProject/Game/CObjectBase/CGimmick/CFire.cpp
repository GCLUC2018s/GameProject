#include "CFire.h"
/*

êªçÏé“Å@âÕñÏ

*/

CFire::CFire(CVector3D *pos) :CObjectBase(eID_Gimmick, eU_Gimmick, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Fire"));
	m_img.SetSize(204 * 0.75, 245 * 0.75);
	m_pos3D = *pos;
	m_rect = CRect(40 * 0.75, 32 * 0.75 + 60, 150 * 0.75, 234 * 0.75 + 60);
	m_rect_F = m_rect;
}

CFire::~CFire(){
}

void CFire::Update(){
	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
	CheckOverlap();
}

void CFire::Draw(){
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + 60 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
//	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
//	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}
