#include "CFieldGround.h"
#include "../GameProject/Game/CObjectBase/CPlayer/CPlayer.h"
#include "../GameProject/stdafx.h"

CFieldGround::CFieldGround(const bool flag):CObjectBase(eID_Ground,eU_Map, eD_Ground){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Ground"));
	m_img.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT + 450);
	m_rect =		 CRect(1869, -440, 2592, -427);
	//m_rect_tourou[4] = {
	//	(429.0f,  -250.0f, 562.0f,  -200.0f),
	//	(429.0f,  -250.0f, 562.0f,  -200.0f),
	//	(1492.0f, -250.0f, 1625.0f, -200.0f),
	//	(3755.0f, -250.0f, 3888.0f, -200.0f)
	//};
	//m_rect_tourou1 = CRect(429,  -250, 562,  -200);
	//m_rect_tourou2 = CRect(1492, -250, 1625, -200);
	//m_rect_tourou3 = CRect(2878, -250, 3011, -200);
	//m_rect_tourou4 = CRect(3755, -250, 3888, -200);
	m_flag = flag;
	if (m_flag == false)
		//‚P–‡–Ú
		m_pos3D = CVector3D(0, 0, 0);
	else
		//‚Q–‡–Ú
		m_pos3D = CVector3D(GROUND_WIDTH, 0, 0);
}

CFieldGround::~CFieldGround() {
}

void CFieldGround::Update()
{
	if (m_flag == false) {
		//‚P–‡–Ú
		if (m_pos3D.x - m_scroll.x > GROUND_WIDTH + SCREEN_WIDTH) {
			m_pos3D.x += m_scroll.x;
		}
	}
	else {
		//‚Q–‡–Ú
		if (m_pos3D.x - m_scroll.x > GROUND_WIDTH * 2 + SCREEN_WIDTH) {
			m_pos3D.x += m_scroll.x;
		}
	}
}

void CFieldGround::Draw()
{
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_scroll.x, 450 + m_pos3D.y - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	//for (int i = 0; i < 4; i++) {
	//	Utility::DrawQuad(CVector2D(m_pos3D.x - m_scroll.x + m_rect_tourou[i].m_left, 450 + m_pos3D.y - m_scroll.y + m_rect_tourou[i].m_top), CVector2D(m_rect_tourou[i].m_right - m_rect_tourou[i].m_left, m_rect_tourou[i].m_bottom - m_rect_tourou[i].m_top), CVector4D(1, 0, 0, 0.3));
	//}
}

void CFieldGround::GroundHitCheck(CPlayer * pl)
{
	//PL‚ªˆê”Ô‰œ‚Ü‚Å—ˆ‚Ä‚¢‚½‚ç
	if (pl->GetPos().z == -400) {
		//‚Ü‚¸‚ÍŽÐH‚Æ‚Ì”»’è
		{
			if (pl->GetPos().x + pl->GetRect().m_right > m_pos3D.x + m_rect.m_left &&
				pl->GetPos().x + pl->GetRect().m_left < m_pos3D.x + m_rect.m_right &&
				pl->GetPos().y + pl->GetRect().m_top < m_pos3D.y + m_rect.m_top&&
				pl->GetPos().y + pl->GetRect().m_bottom > m_pos3D.y + m_rect.m_bottom) {
				pl->SetVec(CVector3D(pl->GetVec().x, 0, -400));
			}
		}
		//
	}
}