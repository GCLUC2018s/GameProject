#include "CPlayer.h"

CPlayer::CPlayer(){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_vec = CVector2D(10, 10);
	m_pos = CVector2D(SCREEN_WIDTH -300, SCREEN_HEIGHT - 100);
	m_img.SetRect(0, 0, 64, 64);
	m_img.SetSize(64, 64);
}
void CPlayer::Update(){
		if (HOLD_UP) {
			m_pos.y -= m_vec.y;
		}
		if (HOLD_DOWN) {
			m_pos.y += m_vec.y;
		}
		if (HOLD_RIGHT) {
			m_pos.x += m_vec.x;
		}
		if (HOLD_LEFT) {
			m_pos.x -= m_vec.x;
		}
}