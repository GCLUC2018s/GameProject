#include "CItemBox.h"
/*

����ҁ@�͖�

*/

CItemBox::CItemBox(CVector3D *pos) :CObjectBase(eID_Gimmick, eU_Gimmick, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("ItemBox"));
	m_img.SetSize(512, 512);
	m_pos3D = *pos;
	m_rect = CRect(124, 182, 392, 414);
	m_rect_F = m_rect;
}

CItemBox::~CItemBox() {
}

void CItemBox::Update() {
	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
	CheckOverlap();
}

void CItemBox::Draw() {
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 550 + m_pos3D.y + m_pos3D.z - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}