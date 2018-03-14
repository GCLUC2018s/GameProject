#include "CEnemy2.h"


/*

êªçÏé“Å@ê¬ñÿ

*/
//íÒìî
CEnemy2::CEnemy2(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy2"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_pos3D = *pos;
	m_hp = CHOCHIN_HP;
	m_at = CHOCHIN_AT;
	m_rect = CRect(0, 0, ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_rect_F = CRect(0, 0, ENEMY_SIZ_X, ENEMY_SIZ_Y*1.5);
}

CEnemy2::~CEnemy2() {
}

void CEnemy2::Update() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > GROUND_WIDTH - ENEMY_SIZ_X) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = CHOCHIN_SPEED;
	}
	else {
		m_vec3D.x = -CHOCHIN_SPEED;
	}

	//è„â∫ïÇóV
	m_a += CHOCHIN_FLOAT;
	m_vec3D.y = sin(m_a) * 2;


	m_img.ChangeAnimation(eAnimIdol);
	m_img.UpdateAnimation();
}