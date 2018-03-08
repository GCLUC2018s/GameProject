#include "CPlayer.h"
#include "../CBullet/CBullet.h"
#include "../GameProject/Task/CTaskManager.h"

CPlayer::CPlayer() : CTask(eID_Player, eUDP_Player, eDWP_Player)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("TIP"));
	m_img.SetCenter(32, 32);
	m_img.SetRect(0, 0, 64, 64);
	m_img.SetSize(64, 64);
	m_pos = CVector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 200);
	m_vec = CVector2D(5, 5);
	m_rect = CRect(-32, -32, 32, 32);
}

void CPlayer::Update()
{
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
		new CBullet(m_pos);
	}
}
