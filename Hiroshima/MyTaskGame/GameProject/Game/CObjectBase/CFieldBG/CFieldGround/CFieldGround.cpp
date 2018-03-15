#include "CFieldGround.h"

CFieldGround::CFieldGround(const bool flag):CObjectBase(0,eU_Map, eD_Ground){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Ground"));
	m_img.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT);
	m_rect = CRect(2032, 715, 2424, 1180);
	m_rect_tourou1 = CRect(429, 882, 562, 1138);
	m_rect_tourou2 = CRect(1492, 882, 1625, 1138);
	m_rect_tourou3 = CRect(2878, 882, 3011, 1138);
	m_rect_tourou4 = CRect(3755, 882, 3888, 1138);
	//if (flag == false)
	//	//‚P–‡–Ú
	//	m_pos3D = CVector3D(0, 0, 0);
	//else
	//	//‚Q–‡–Ú
	//	m_pos3D = CVector3D(GROUND_WIDTH, 0, 0);
}

CFieldGround::~CFieldGround() {
}

void CFieldGround::Draw()
{
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_scroll.x, m_pos3D.y - m_scroll.y);
	m_img.Draw();
//	Utility::DrawQuad(CVector2D(m_pos3D.x - m_scroll.x + m_rect.m_left, m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_scroll.x + m_rect.m_left,m_pos3D.y - m_scroll.y), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_scroll.x + m_rect_tourou1.m_left, m_pos3D.y - m_scroll.y + 200), CVector2D(m_rect_tourou1.m_right - m_rect_tourou1.m_left, m_rect_tourou1.m_bottom - m_rect_tourou1.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_scroll.x + m_rect_tourou2.m_left, m_pos3D.y - m_scroll.y + 200), CVector2D(m_rect_tourou2.m_right - m_rect_tourou2.m_left, m_rect_tourou2.m_bottom - m_rect_tourou2.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_scroll.x + m_rect_tourou3.m_left, m_pos3D.y - m_scroll.y + 200), CVector2D(m_rect_tourou3.m_right - m_rect_tourou3.m_left, m_rect_tourou3.m_bottom - m_rect_tourou3.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_scroll.x + m_rect_tourou4.m_left, m_pos3D.y - m_scroll.y + 200), CVector2D(m_rect_tourou4.m_right - m_rect_tourou4.m_left, m_rect_tourou4.m_bottom - m_rect_tourou4.m_top), CVector4D(1, 0, 0, 0.3));

}