
#include "CEnemy4.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//Ç©Ç‹Ç¢ÇΩÇø
CEnemy4::CEnemy4(CVector3D *pos) :CObjectBase(0, eUDP_Enemy, eDWP_Enemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy4"));
	m_img.SetSize(213, 256);
	m_pos3D = *pos;
	m_hp = KAMAITACHI_HP;
	m_at = KAMAITACHI_AT;

}

CEnemy4::~CEnemy4() {
}

void CEnemy4::Update() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > 1280 - 213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = KAMAITACHI_SPEED;
	}
	else {
		m_vec3D.x = -KAMAITACHI_SPEED;
	}


	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}