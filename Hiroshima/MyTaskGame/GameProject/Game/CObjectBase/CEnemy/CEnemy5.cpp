
#include "CEnemy5.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//ì˜âÚ
CEnemy5::CEnemy5(CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy5"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_pos3D = *pos;
	m_hp = NIKU_HP;
	m_at = NIKU_AT;
	m_rect = CRect(0, 0, ENEMY_SIZ_X, ENEMY_SIZ_Y);

}

CEnemy5::~CEnemy5() {
}

void CEnemy5::Update() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > GROUND_WIDTH - ENEMY_SIZ_X) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = NIKU_SPEED;
	}
	else {
		m_vec3D.x = -NIKU_SPEED;
	}


	m_img.ChangeAnimation(eAnimIdol);
	m_img.UpdateAnimation();
}