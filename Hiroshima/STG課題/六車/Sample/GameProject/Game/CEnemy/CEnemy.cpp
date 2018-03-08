#include "CEnemy.h"

CEnemy::CEnemy():CTask(0,eUDP_Enemy,eDWP_Enemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
	m_img.SetRect(0, 64, 64, 128);
	m_img.SetSize(64, 64);
	m_pos = CVector2D(100,0);
}

CEnemy::~CEnemy()
{
	new CEnemy();
}

void CEnemy::Update() {

	m_pos.y += 5;
	
	if (m_pos.y > 800) {
		SetKill();
	}
}
