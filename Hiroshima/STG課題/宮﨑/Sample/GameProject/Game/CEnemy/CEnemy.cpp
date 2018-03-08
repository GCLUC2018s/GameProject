#include "CEnemy.h"

CEnemy::CEnemy() : CTask(eID_Enemy, eUDP_Enemy, eDWP_Enemy)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("TIP"));
	m_img.SetRect(0, 64, 64, 128);
	m_img.SetSize(64, 64);
	m_pos = CVector2D(SCREEN_WIDTH / 2, -200);
	m_vec = CVector2D(3, 3);
	m_rect = CRect(0, 0, 64, 64);
}

CEnemy::~CEnemy()
{
	new CEnemy();
}

void CEnemy::Update()
{
	m_pos.y += m_vec.y;
	if (m_pos.y + m_rect.m_top > SCREEN_HEIGHT) {
		SetKill();
	}
}
