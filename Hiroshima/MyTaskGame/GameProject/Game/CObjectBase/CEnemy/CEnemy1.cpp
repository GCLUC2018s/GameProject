
#include "CEnemy1.h"
/*

����ҁ@��

*/
CEnemy1::CEnemy1(CVector3D *pos){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
	m_img.SetSize(213, 256);
	m_pos3D = *pos;

}

CEnemy1::~CEnemy1() {
}

void CEnemy1::Update() {

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