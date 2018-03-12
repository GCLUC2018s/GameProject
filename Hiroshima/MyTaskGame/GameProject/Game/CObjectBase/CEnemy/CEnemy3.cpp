
#include "CEnemy3.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//âŒÇÃã 
CEnemy3::CEnemy3(CVector3D *pos) :CObjectBase(0, eUDP_Enemy, eDWP_Enemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy3"));
	m_img.SetSize(213, 256);
	m_pos3D = *pos;
	m_hp = HI_HP;
	m_at = HI_AT;

}

CEnemy3::~CEnemy3() {
}

void CEnemy3::Update() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > 1280 - 213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = HI_SPEED;
	}
	else {
		m_vec3D.x  = -HI_SPEED;
	}

	//è„â∫ïÇóV
	m_a += 0.1f;
	m_vec3D.y = sin(m_a) * 5;


	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}