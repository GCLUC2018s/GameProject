
#include "CBoss.h"
#include "../CBB/CBB.h"
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
	m_headpos3D = m_headoldpos3D = *headpos;
	m_armpos3D = m_armoldpos3D = *armpos;
	m_arm2pos3D = m_arm2oldpos3D = *arm2pos;
	m_tailpos3D = m_tailoldpos3D = *tailpos;
	m_hp = BOSS_HP;
	m_at = BOSS_AT;
	m_test = 0;
	m_motiontest = 0;
	m_rect = CRect  (0, 0, 0, 0);
	m_headrect = CRect(-200, -150, BOSS_SIZ_X - 350, BOSS_SIZ_Y - 350);
	m_armrect = CRect(-150, -100, BOSS_SIZ_X - 400, BOSS_SIZ_Y - 450);
	m_arm2rect = CRect(-150, -100, BOSS_SIZ_X - 400, BOSS_SIZ_Y - 400);
	m_tailrect = CRect(-100, -150, BOSS_SIZ_X - 420, BOSS_SIZ_Y - 470);
	m_rect_F = CRect(0, 0, 0, 0);
//	m_flipH = false;
	m_parts_head = eHead;
	m_parts_arm = eArm;
	m_parts_arm2 = eArm2;
	m_parts_tail = eTail;
	m_state = eIdol;
	m_rect_F = m_armrect;
}

CBoss::~CBoss() {
}

void CBoss::Update() {
	
	
	//if(m_state!=eTailAttack)
	//m_test++;
	//if (m_test >= 50) {
	//	m_flipH = true;
	//}else if(m_test < 50){
	//	m_flipH = false;
	//}
	//if (m_test == 50) {
	//	m_tailpos3D.x += 113;
	//}
	//if (m_test == 100) {
	//	m_tailpos3D.x -= 113;
	//}	
	//if (m_test == 100) {
	//	m_test = 0;
	//}

	if(m_state!=eFall)
	m_motiontest++;

	if (m_motiontest == 60 * 10) {
		m_state = eJump;
		AttackPattern();
	}

	if (m_motiontest == 60 * 25) {
		m_state = eJump;
		AttackPattern();
	}
	if (m_motiontest == 60 * 40) {
		m_state = eJump;
		AttackPattern();
	}

	if (m_motiontest == 60 * 55) {
		m_state = eJump;
		AttackPattern();
		m_motiontest = 0;
	}

	


	m_headpos3D += m_headvec3D;
	m_armpos3D += m_armvec3D;
	m_arm2pos3D += m_arm2vec3D;
	m_tailpos3D += m_tailvec3D;

	Head();
	Arm();
	Arm2();
	Tail();


	//if (PUSH_ENTER) {
	//	//m_state = eDown;
	//	m_state = eJump;
	//}
	
	
//m_img.ChangeAnimation(6);
//m_head.ChangeAnimation(7);


	m_head.UpdateAnimation();
	m_arm.UpdateAnimation();
	m_arm.UpdateAnimation();
	m_tail.UpdateAnimation();


	BossCheckOverlap();
	m_rect_F.m_bottom = BOSS_SIZ_Y - m_tailpos3D.y;
}

void CBoss::Draw() {

	m_head.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_arm.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_arm2.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_tail.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);

	m_head.SetSize(BOSS_SIZ_X, BOSS_SIZ_Y);
	m_arm.SetSize(BOSS_SIZ_X, BOSS_SIZ_Y);
	m_arm2.SetSize(BOSS_SIZ_X, BOSS_SIZ_Y);
	m_tail.SetSize(BOSS_SIZ_X, BOSS_SIZ_Y);

	m_head.SetCenter(BOSS_SIZ_X / 2, BOSS_SIZ_Y / 2);
	m_arm.SetCenter(BOSS_SIZ_X / 2, BOSS_SIZ_Y / 2);
	m_arm2.SetCenter(BOSS_SIZ_X / 2, BOSS_SIZ_Y / 2);
	m_tail.SetCenter(BOSS_SIZ_X / 2, BOSS_SIZ_Y / 2);

	m_head.SetPos(m_headpos3D.x - m_headpos3D.z / 7/*m_variation*/ - m_scroll.x, 450 + m_headpos3D.y + m_headpos3D.z / 2 - m_scroll.y);
	m_arm.SetPos(m_armpos3D.x - m_armpos3D.z / 7/*m_variation*/ - m_scroll.x, 450 + m_armpos3D.y + m_armpos3D.z / 2 - m_scroll.y);
	m_arm2.SetPos(m_arm2pos3D.x - m_arm2pos3D.z / 7/*m_variation*/ - m_scroll.x, 450 + m_arm2pos3D.y + m_arm2pos3D.z / 2 - m_scroll.y);
	m_tail.SetPos(m_tailpos3D.x - m_tailpos3D.z / 7/*m_variation*/ - m_scroll.x, 450 + m_tailpos3D.y + m_tailpos3D.z / 2 - m_scroll.y);


	//Utility::DrawQuad(CVector2D(m_headpos3D.x - m_headpos3D.z / 7 - m_scroll.x + m_headrect.m_left , 450 + m_headpos3D.y + m_headpos3D.z / 2 - m_scroll.y + m_headrect.m_top), CVector2D(m_headrect.m_right - m_headrect.m_left, m_headrect.m_bottom - m_headrect.m_top), CVector4D(1, 0, 0, 0.3));
	//Utility::DrawQuad(CVector2D(m_headpos3D.x - m_headpos3D.z / 7 - m_scroll.x + m_headrect.m_left, 450 + m_headpos3D.y + m_headpos3D.z / 2 - m_scroll.y + m_headrect.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
	//Utility::DrawQuad(CVector2D(m_headpos3D.x - m_headpos3D.z / 7 - m_scroll.x + m_headrect.m_left , 450 + m_headpos3D.y + m_headpos3D.z / 2 - m_scroll.y + m_headrect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));

	
	//Utility::DrawQuad(CVector2D(m_armpos3D.x - m_armpos3D.z / 7 - m_scroll.x + m_armrect.m_left , 450 + m_armpos3D.y + m_armpos3D.z / 2 - m_scroll.y + m_armrect.m_top), CVector2D(m_armrect.m_right - m_armrect.m_left, m_armrect.m_bottom - m_armrect.m_top), CVector4D(1, 0, 0, 0.3));
	//Utility::DrawQuad(CVector2D(m_armpos3D.x - m_armpos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_armpos3D.y + m_armpos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
	//Utility::DrawQuad(CVector2D(m_armpos3D.x - m_armpos3D.z / 7 - m_scroll.x + m_armrect.m_left , 450 + m_armpos3D.y + m_armpos3D.z / 2 - m_scroll.y + m_armrect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));

	//Utility::DrawQuad(CVector2D(m_arm2pos3D.x - m_arm2pos3D.z / 7 - m_scroll.x + m_arm2rect.m_left , 450 + m_arm2pos3D.y + m_arm2pos3D.z / 2 - m_scroll.y + m_arm2rect.m_top), CVector2D(m_arm2rect.m_right - m_arm2rect.m_left, m_arm2rect.m_bottom - m_arm2rect.m_top), CVector4D(1, 0, 0, 0.3));
	//Utility::DrawQuad(CVector2D(m_arm2pos3D.x - m_arm2pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_arm2pos3D.y + m_arm2pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
	//Utility::DrawQuad(CVector2D(m_arm2pos3D.x - m_arm2pos3D.z / 7 - m_scroll.x + m_arm2rect.m_left , 450 + m_arm2pos3D.y + m_arm2pos3D.z / 2 - m_scroll.y + m_arm2rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));


	//Utility::DrawQuad(CVector2D(m_tailpos3D.x - m_tailpos3D.z / 7 - m_scroll.x + m_tailrect.m_left, 450 + m_tailpos3D.y + m_tailpos3D.z / 2 - m_scroll.y + m_tailrect.m_top), CVector2D(m_tailrect.m_right - m_tailrect.m_left, m_tailrect.m_bottom - m_tailrect.m_top), CVector4D(1, 0, 0, 0.3));
	//Utility::DrawQuad(CVector2D(m_tailpos3D.x - m_tailpos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_tailpos3D.y + m_tailpos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
	//Utility::DrawQuad(CVector2D(m_tailpos3D.x - m_tailpos3D.z / 7 - m_scroll.x + m_tailrect.m_left, 450 + m_tailpos3D.y + m_tailpos3D.z / 2 - m_scroll.y + m_tailrect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));

	//m_tail.SetFlipH(m_flipH);

	m_tail.Draw();
	m_arm.Draw();
	m_head.Draw();
	m_arm2.Draw();


	
}


void CBoss::Head() {
	switch (m_state)
	{
	case eIdol:
		Nutral(m_parts_head);
		break;
	case eMove:
		break;
	case eBlessAttack:
		Attack(m_parts_head);
		break;
	case eTailAttack:
		Nutral(m_parts_head);
		break;
	case eBress:
		Attack(m_parts_head);
		break;
	case eLaserShower:
		Nutral(m_parts_head);
		break;
	case eDown:
		Down(m_parts_head);
		break;
	case eFall:
		Fall();
		break;
	case eDamage:
		Damage(m_parts_head);
		break;
	case eJump:
		BossJump();
		break;
	case eDescent:
		BossDescent();
		break;
	}
	

	//Attack(&m_parts_head);
}

void CBoss::Arm() {

	switch (m_state)
	{
	case eIdol:
		Nutral(m_parts_arm);
		break;
	case eMove:
		break;
	case eBlessAttack:
		Nutral(m_parts_arm);
		break;
	case eTailAttack:
		Nutral(m_parts_arm);
		break;
	case eBress:
		Attack(m_parts_arm);
		break;
	case eLaserShower:
		BossLaser();
		break;
	case eDown:
		Nutral(m_parts_arm);
		break;
	case eFall:
		Fall();
		break;
	case eDamage:
		Damage(m_parts_arm);
		break;
	}


	//Attack(&m_parts_head);
}

void CBoss::Arm2() {
	switch (m_state)
	{
	case eIdol:
		Nutral(m_parts_arm2);
		break;
	case eMove:
		break;
	case eBlessAttack:
		Nutral(m_parts_arm2);
		break;
	case eTailAttack:
		Nutral(m_parts_arm2);
		break;
	case eBress:
		Nutral(m_parts_arm2);
		break;
	case eLaserShower:
		Nutral(m_parts_arm2);
		break;
	case eDown:
		Nutral(m_parts_arm2);
		break;
	case eFall:
		Fall();
		break;
	case eDamage:
		Damage(m_parts_arm2);
		break;
	}


	
}

void CBoss::Tail() {
	switch (m_state)
	{
	case eIdol:
		Nutral(m_parts_tail);
		break;
	case eMove:
		break;
	case eBlessAttack:
		Nutral(m_parts_tail);
		break;
	case eTailAttack:
		Attack(m_parts_tail);
		break;
	case eBress:
		Nutral(m_parts_tail);
		break;
	case eLaserShower:
		Nutral(m_parts_tail);
		break;
	case eDown:
		Nutral(m_parts_tail);
		break;
	case eFall:
		Fall();
		break;
	case eDamage:
		Damage(m_parts_tail);
		break;
	}

	

	
}

void CBoss::AttackPattern(){
	if(TWO_RANDOM)
		m_attack_id = true;
	else
		m_attack_id = false;
}
