
#include "CBoss.h"
/*

»ìÒ@Â–Ø

*/
CBoss::CBoss(const CVector3D *pos) :CObjectBase(0, eU_Chara, eD_Chara) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Boss"));
	m_img.SetSize(256 * 3, 256 * 3);
	m_pos3D = *pos;
	m_hp = BOSS_HP;
	m_at = BOSS_AT;
	m_test = 0;
	m_rect = CRect(0, 0, 256 * 3, 256 * 3);
	//m_rect_F = CRect(0, 0, 256 * 3, 256 * 3);
}

CBoss::~CBoss() {
}

void CBoss::Update() {
	
	switch (m_test)
	{
	case 0:
		m_img.ChangeAnimation(0);
		break;
	case 1:
		m_img.ChangeAnimation(1);
		break;
	case 2:
		m_img.ChangeAnimation(2);
		break;
	case 3:
		m_img.ChangeAnimation(3);
		break;
	case 4:
		m_img.ChangeAnimation(4);
		break;
	case 5:
		m_img.ChangeAnimation(5);
		break;
	case 6:
		m_img.ChangeAnimation(6);
		break;
	case 7:
		m_img.ChangeAnimation(7);
		break;
	}


	if (m_test > 7)
		m_test = 0;


	if(PUSH_ENTER) {
		m_test++;
	}
	m_img.UpdateAnimation();
}