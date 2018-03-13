
#include "CEnemy2.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//íÒìî
CEnemy2::CEnemy2(CVector3D *pos) :CObjectBase(0, eUDP_Enemy, eDWP_Enemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy2"));
	m_img.SetSize(213, 256);
	m_pos3D = *pos;
	m_hp = CHOCHIN_HP;
	m_at = CHOCHIN_AT;

}

CEnemy2::~CEnemy2() {
}

void CEnemy2::Update() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > 4000 - 213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = CHOCHIN_SPEED;
	}
	else {
		m_vec3D.x = -CHOCHIN_SPEED;
	}

	//è„â∫ïÇóV
	m_a += 0.3f;
	m_vec3D.y = sin(m_a) * 2;


	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}