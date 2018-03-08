#include "CPlayer.h"
#include "../Global.h"

CPlayer::CPlayer()
{
	m_pos = CVector2D(500, 500);
	m_vec = CVector2D(5, 5);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
}

void CPlayer:: Update(){
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
}

void CPlayer::Draw() {
	m_img.SetRect(0, 0, 64, 64);
	m_img.SetSize(64, 64);
	m_img.SetPos(m_pos);
	m_img.Draw();
}