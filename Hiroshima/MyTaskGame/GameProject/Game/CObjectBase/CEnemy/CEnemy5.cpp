
#include "CEnemy5.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//ì˜âÚ
CEnemy5::CEnemy5(CVector3D *pos) :CObjectBase(0, eUDP_Enemy, eDWP_Enemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy5"));
	m_img.SetSize(213, 256);
	m_pos3D = *pos;

}

CEnemy5::~CEnemy5() {
}

void CEnemy5::Update() {

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > 1280 - 213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_pos3D.x += 2;
	}
	else {
		m_pos3D.x -= 2;
	}


	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}