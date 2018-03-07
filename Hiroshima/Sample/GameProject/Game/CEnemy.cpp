#include "CEnemy.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
CEnemy::CEnemy(CVector2D pos) :CBase(eTagEnemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
	m_img.SetSize(213, 256);
	m_pos=pos;
	
}

CEnemy::~CEnemy() {
}

void CEnemy::Update() {

	if (m_pos.x < 0) {
		m_flipH = true;
	}

	if (m_pos.x > 1280-213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_pos.x += 5;
	}
	else {
		m_pos.x -= 5;
	}
	

	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}