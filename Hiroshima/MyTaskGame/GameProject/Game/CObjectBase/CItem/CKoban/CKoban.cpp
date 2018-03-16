#include "CKoban.h"

CKoban::CKoban(CVector3D * pos):CObjectBase(eID_Item,eU_Item, eD_Object){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Koban"));
	m_img.SetRect(0, 320, 32, 352);
	m_img.SetSize(20, 20);
	m_rect = CRect(0, 0, 20, 20);
	m_pos3D = *pos;

}

CKoban::~CKoban(){

}

void CKoban::Update(){
	m_rect_F = CRect(0, 0, 20, 20 - m_pos3D.y);
}

void CKoban::Draw() {
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetFlipH(m_flipH);

	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x,450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));

}

void CKoban::Hit(CTask * t){
	printf("1111111111111111\n");
}
