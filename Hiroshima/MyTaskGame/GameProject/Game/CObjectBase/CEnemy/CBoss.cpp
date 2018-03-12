
#include "CBoss.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
CBoss::CBoss(CVector3D *pos) :CObjectBase(0, eUDP_Enemy, eDWP_Enemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Boss"));
	m_img.SetSize(213, 256);
	m_pos3D = *pos;

}

CBoss::~CBoss() {
}

void CBoss::Update() {

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > 1280 - 213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_pos3D.x += 5;
	}
	else {
		m_pos3D.x -= 5;
	}


	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}