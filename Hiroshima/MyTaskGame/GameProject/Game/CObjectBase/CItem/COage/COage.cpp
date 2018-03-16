#include "COage.h"

COage::COage(CVector3D * pos) :CObjectBase(0, eU_Item, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Oage"));
	m_img.SetRect(0, 256, 64, 320);
	m_img.SetSize(64, 64);
	m_rect = CRect(0, 0, 64, 64);
	m_pos3D = *pos;

}

COage::~COage() {

}

void COage::Update() {

}

void COage::Draw(){

	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetFlipH(m_flipH);

	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));

}

void COage::Hit(CTask * t)
{
}
