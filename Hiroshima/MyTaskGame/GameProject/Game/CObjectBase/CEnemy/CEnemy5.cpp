
#include "CEnemy5.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//ì˜âÚ
CEnemy5::CEnemy5(CVector3D *pos) :CObjectBase(0, eU_Chara, eD_Chara) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy5"));
	m_img.SetSize(213, 256);
	m_pos3D = *pos;
	m_hp = NIKU_HP;
	m_at = NIKU_AT;

}

CEnemy5::~CEnemy5() {
}

void CEnemy5::Update() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > 4000 - 213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = NIKU_SPEED;
	}
	else {
		m_vec3D.x = -NIKU_SPEED;
	}


	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}