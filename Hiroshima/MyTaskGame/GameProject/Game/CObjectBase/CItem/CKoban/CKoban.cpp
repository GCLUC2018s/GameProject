#include "CKoban.h"
#define KOBAN_HOSEI 183

CKoban::CKoban(CVector3D * pos) :CItemBase(pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("UI"));
	m_img.SetRect(0, 320, 32, 352);
	m_img.SetSize(32, 32);
	m_rect = CRect(0,0, 32, 32);
	m_rect_F = m_rect;
}

CKoban::~CKoban(){

}

void CKoban::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Player&& m_get == false) {
		SOUND("SE_COIN")->Play(false);
		Action(t);
		m_time = 0;
		m_get = true;
	}
}

void CKoban::Draw()
{
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(-12 + m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + KOBAN_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	//Utility::DrawQuad(CVector2D(-12 + m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + ITEM_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	//Utility::DrawQuad(CVector2D(-12 + m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + ITEM_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}

void CKoban::Action(CObjectBase * a){
	m_score ++;
}
