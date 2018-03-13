
#include "CBoss.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
CBoss::CBoss(CVector3D *pos) :CObjectBase(0, eU_Chara, eD_Chara) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Boss"));
	m_img.SetSize(213, 256);
	m_pos3D = *pos;
	m_hp = BOSS_HP;
	m_at = BOSS_AT;

}

CBoss::~CBoss() {
}

void CBoss::Update() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > 1280 - 213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = BOSS_SPEED;
	}
	else {
		m_vec3D.x = -BOSS_SPEED;
	}


	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}