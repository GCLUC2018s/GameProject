#include "CEnemy1.h"

/*

êªçÏé“Å@ê¬ñÿ

*/
//ÇæÇÈÇ‹
CEnemy1::CEnemy1(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_img.SetRect(0, 0, 512, 512);
	m_pos3D = *pos;
	m_hp = DARUMA_HP;
	m_at = DARUMA_AT;

}

CEnemy1::~CEnemy1() {
}

void CEnemy1::Update() {

	m_pos3D += m_vec3D;
	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > GROUND_WIDTH - ENEMY_SIZ_X) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = DARUMA_SPEED;
	}
	else {
		m_vec3D.x = -DARUMA_SPEED;
	}


	m_img.ChangeAnimation(eAnimIdol);
	m_img.UpdateAnimation();
}