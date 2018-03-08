#include "CPlayer.h"

CPlayer::CPlayer()
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("TIP"));
	m_img.SetRect(0, 0, 64, 64);
	m_img.SetSize(64, 64);
	m_pos = CVector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 200);
	m_vec = CVector2D(5, 5);
	m_rect = CRect(0, 0, 64, 64);
}

void CPlayer::Update()
{
	m_bullet_on = false;
	if (HOLD_UP) {
		m_pos.y -= m_vec.y;
	}
	if (HOLD_DOWN) {
		m_pos.y += m_vec.y;
	}
	if (HOLD_LEFT) {
		m_pos.x -= m_vec.x;
	}
	if (HOLD_RIGHT) {
		m_pos.x += m_vec.x;
	}
	if (PUSH_C) {
		m_bullet_on = true;
	}
}
