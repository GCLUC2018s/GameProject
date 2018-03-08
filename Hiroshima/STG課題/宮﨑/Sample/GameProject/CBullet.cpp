#include "CBullet.h"

CBullet::CBullet(CVector2D pos)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("TIP"));
	m_img.SetRect(256, 0, 272, 16);
	m_img.SetSize(16, 16);
	m_pos = CVector2D(pos.x, pos.y);
	m_vec = CVector2D(10, 10);
	m_rect = CRect(0, 0, 16, 16);
}

void CBullet::Update()
{
	m_pos.y -= m_vec.y;
}
