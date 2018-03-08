#include "CEnemy.h"

CEnemy::CEnemy()
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("TIP"));
	m_img.SetRect(0, 64, 64, 128);
	m_img.SetSize(64, 64);
	m_pos = CVector2D(SCREEN_WIDTH / 2, -200);
	m_vec = CVector2D(3, 3);
	m_rect = CRect(0, 0, 64, 64);
}

void CEnemy::Update()
{
	m_pos.y += m_vec.y;
}
