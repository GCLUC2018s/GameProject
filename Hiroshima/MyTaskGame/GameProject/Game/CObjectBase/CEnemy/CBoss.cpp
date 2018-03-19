
#include "CBoss.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
CBoss::CBoss(const CVector3D *headpos, const CVector3D *armpos, const CVector3D *arm2pos, const CVector3D *tailpos) :CBossBase() {
	//m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Boss"));
	m_head = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Boss"));
	m_arm = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Boss"));
	m_arm2 = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Boss"));
	m_tail = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Boss"));
	//m_img.SetSize(BOSS_SIZ_X , BOSS_SIZ_Y );
	m_headpos3D = *headpos;
	m_armpos3D = *armpos;
	m_arm2pos3D = *arm2pos;
	m_tailpos3D = *tailpos;
	m_hp = BOSS_HP;
	m_at = BOSS_AT;
	m_test = 0;
	m_rect = CRect(0, 0, BOSS_SIZ_X, BOSS_SIZ_Y);
	//m_rect_F = CRect(0, 0, 256 * 3, 256 * 3);
	m_flipH = false;
	m_parts_head = eHead;
	m_parts_arm = eArm;
	m_parts_arm2 = eArm2;
	m_parts_tail = eTail;
}

CBoss::~CBoss() {
}

void CBoss::Update() {
	

	m_test++;

	if (m_test >= 50) {
		m_flipH = true;
	}else if(m_test < 50){
		m_flipH = false;
	}
	if (m_test == 50) {
		m_tailpos3D.x += 113;
	}
	if (m_test == 100) {
		m_tailpos3D.x -= 113;
	}
	
	
	if (m_test == 100) {
		m_test = 0;
	}



	m_headpos3D += m_headvec3D;
	m_armpos3D += m_armvec3D;
	m_arm2pos3D += m_arm2vec3D;
	m_tailpos3D += m_tailvec3D;

	Head();
	Arm();
	Arm2();
	Tail();

	//m_a += KAMAITACHI_FLOAT;
	//m_vec3D.x = -cos(m_a + Utility::DgreeToRadian(180)) * 3;	
	//m_vec3D.y = -sin(m_a) * 3;

	

//
//
//m_img.ChangeAnimation(6);
//m_head.ChangeAnimation(7);


	m_head.UpdateAnimation();
	m_arm.UpdateAnimation();
	m_arm.UpdateAnimation();
	m_tail.UpdateAnimation();
}

void CBoss::Draw() {
	m_head.SetSize(BOSS_SIZ_X, BOSS_SIZ_Y);
	m_arm.SetSize(BOSS_SIZ_X, BOSS_SIZ_Y);
	m_arm2.SetSize(BOSS_SIZ_X, BOSS_SIZ_Y);
	m_tail.SetSize(BOSS_SIZ_X, BOSS_SIZ_Y);

	m_head.SetPos(m_headpos3D.x - m_headpos3D.z / 7/*m_variation*/ - m_scroll.x, 450 + m_headpos3D.y + m_headpos3D.z / 2 - m_scroll.y);
	m_arm.SetPos(m_armpos3D.x - m_armpos3D.z / 7/*m_variation*/ - m_scroll.x, 450 + m_armpos3D.y + m_armpos3D.z / 2 - m_scroll.y);
	m_arm2.SetPos(m_arm2pos3D.x - m_arm2pos3D.z / 7/*m_variation*/ - m_scroll.x, 450 + m_arm2pos3D.y + m_arm2pos3D.z / 2 - m_scroll.y);
	m_tail.SetPos(m_tailpos3D.x - m_tailpos3D.z / 7/*m_variation*/ - m_scroll.x, 450 + m_tailpos3D.y + m_tailpos3D.z / 2 - m_scroll.y);

	
	m_tail.SetFlipH(m_flipH);

	m_tail.Draw();
	m_head.Draw();
	m_arm.Draw();
	m_arm2.Draw();
	
}


void CBoss::Head() {
	Nutral(&m_parts_head);

	Attack(&m_parts_head);
}

void CBoss::Arm() {
	Nutral(&m_parts_arm);

	//Attack(&m_parts_head);
}

void CBoss::Arm2() {
	Nutral(&m_parts_arm2);
}

void CBoss::Tail() {
	Nutral(&m_parts_tail);

	Attack(&m_parts_head);
	
}