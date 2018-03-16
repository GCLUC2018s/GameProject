#include "CItemBox.h"
/*

êªçÏé“Å@âÕñÏ

*/

CItemBox::CItemBox(CVector3D *pos, int state) :CObjectBase(eID_Gimmick, eU_Gimmick, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("ItemBox"));
	m_img.SetSize(256, 256);
	m_pos3D = *pos;
	m_rect = CRect(60, 90 + 48, 200, 200 + 48);
	m_rect_F = m_rect;
	m_state = state;
	m_break = false;
	m_cnt = 0;
}

CItemBox::~CItemBox() {
}

void CItemBox::Update() {
	m_img.SetColor(m_color.r, m_color.g, m_color.b, m_color.a);

	if (!m_break && PUSH_E) {
		m_break = true;
	}
	if (m_cnt > 60) {
		m_color.a = Price_Down(m_color.a, 0, 0.05f);
	}
	if (m_color.a == 0)
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

void CItemBox::Draw() {
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 502 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}
