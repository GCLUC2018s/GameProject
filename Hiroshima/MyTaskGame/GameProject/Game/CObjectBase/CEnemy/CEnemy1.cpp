
#include "CEnemy1.h"
/*

製作者　青木

*/
//だるま
CEnemy1::CEnemy1(CVector3D *pos) :CObjectBase(0, eUDP_Enemy, eDWP_Enemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
	m_img.SetSize(213, 256);
	m_img.SetRect(0, 0, 512, 512);
	m_pos3D = *pos;

}

CEnemy1::~CEnemy1() {
}

void CEnemy1::Update() {

	m_pos3D += m_vec3D;
	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > 1280 - 213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = 3;
	}
	else {
		m_vec3D.x = -3;
	}


	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}