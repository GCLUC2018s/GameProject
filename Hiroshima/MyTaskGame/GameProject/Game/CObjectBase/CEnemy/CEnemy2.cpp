
#include "CEnemy2.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//íÒìî
CEnemy2::CEnemy2(CVector3D *pos) :CObjectBase(0, eUDP_Enemy, eDWP_Enemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy2"));
	m_img.SetSize(213, 256);
	m_pos3D = *pos;

}

CEnemy2::~CEnemy2() {
}

void CEnemy2::Update() {

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > 1280 - 213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_pos3D.x += 4;
	}
	else {
		m_pos3D.x -= 4;
	}


	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}