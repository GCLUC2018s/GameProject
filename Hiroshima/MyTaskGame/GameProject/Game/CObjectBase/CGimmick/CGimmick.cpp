#include "CGimmick.h"
/*

êªçÏé“Å@âÕñÏ

*/

CGimmick::CGimmick(CVector3D *pos) :CObjectBase(eID_Gimmick, eU_Gimmick, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Fire"));
	m_img.SetSize(100, 200);
	m_pos3D = *pos;
	m_rect = CRect(15, 70, 80, 270);
	m_rect_F = m_rect;
}

CGimmick::~CGimmick(){
}

void CGimmick::Update(){
	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
	CheckOverlap();
}

void CGimmick::Draw(){
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 550 + m_pos3D.y + m_pos3D.z - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}
