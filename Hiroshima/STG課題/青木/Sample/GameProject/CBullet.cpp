#include "CBullet.h"


CBullet::CBullet(CVector2D pos):CTask(1,1,1)
{
	m_pos = CVector2D(pos);
	m_vec = CVector2D(5, 20);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Bullet"));
}

void CBullet::Update() {
	m_pos.y -= m_vec.y;
}

void CBullet::Draw() {
	m_img.SetRect(0, 320, 32, 352);
	m_img.SetSize(64, 64);
	m_img.SetPos(m_pos);
	m_img.Draw();
}