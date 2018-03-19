#include "CItemBox.h"
#define ITEM_BOX_HOSEI 47
/*

êªçÏé“Å@âÕñÏ

*/

CItemBox::CItemBox(CVector3D *pos, int state) :CItemBase(pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("ItemBox"));
	m_img.SetSize(256, 256);
	m_pos3D = *pos;
	m_pos3D.z -= ITEM_BOX_HOSEI; //ê⁄ínì_ÇçáÇÌÇπÇÈÇΩÇﬂ
	m_rect = CRect(60, 90, 200, 200);
	m_rect_F = m_rect;
	m_state = state;
	m_break = false;
	m_cnt = 0;
}

CItemBox::~CItemBox() {
}

void CItemBox::Update() {

	if (!m_break && PUSH_E) {
		m_break = true;
	}
	if (m_cnt > 60) {
		m_color.w = Price_Down(m_color.w, 0, 0.05f);
	}
	if (m_color.w == 0)
		SetKill();

	if (m_state) {
		if (m_break) {
			m_img.ChangeAnimation(3, false);
			m_cnt++;
		}else {
			m_img.ChangeAnimation(2);
		}
	}else {
		if (m_break) {
			m_img.ChangeAnimation(1, false);
			m_cnt++;
		}
		else {
			m_img.ChangeAnimation(0);
		}
	}
		
	m_img.UpdateAnimation();
	CheckOverlap();
}
void CItemBox::Draw()
{
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + ITEM_BOX_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
//	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + ITEM_BOX_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
//	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + ITEM_BOX_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}
