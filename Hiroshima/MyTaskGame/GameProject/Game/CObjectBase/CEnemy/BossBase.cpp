#include "BossBase.h"

CBossBase::CBossBase() :CObjectBase(eID_Boss, eU_Enemy, eD_Object) {
	m_shaking_head = 0;
	m_shaking_arm = 0;
	m_shaking_tail = 0;
}



void CBossBase::Nutral( int boss_id) {

	switch (boss_id)
	{
	case eHead:
		m_head.ChangeAnimation(eAnimBossHeadIdol);
		m_shaking_head += BOSS_FLOAT_HEAD;
		//m_headvec3D.x = -cos(m_shaking_head + Utility::DgreeToRadian(90)) * 5;
		m_headvec3D.y = -sin(m_shaking_head) * 1;
		break;
	case eArm:
		m_arm.ChangeAnimation(eAnimBossArm2Idol);
		m_shaking_arm += BOSS_FLOAT_ARM;
		m_armvec3D.x = cos(m_shaking_arm + Utility::DgreeToRadian(180)) * 2;
		m_armvec3D.y = sin(m_shaking_arm);
		break;
	case eArm2:
		m_arm2.ChangeAnimation(eAnimBossArmIdol);
		m_shaking_arm += BOSS_FLOAT_ARM;
		m_arm2vec3D.x = -cos(m_shaking_arm + Utility::DgreeToRadian(180)) * 2;
		m_arm2vec3D.y = sin(m_shaking_arm);
		break;
	case eTail:
		m_tail.ChangeAnimation(eAnimBossTailIdol);
		m_shaking_tail += BOSS_FLOAT_TAIL;
		m_tailvec3D.x = -cos(m_shaking_tail + Utility::DgreeToRadian(180)) * 3;
		//m_tailvec3D.y = -sin(m_shaking) * 5;
		break;
	}


}
void CBossBase::Move( int boss_id) {
	switch (boss_id)
	{
	default:
		break;
	}
}
void CBossBase::Attack( int boss_id) {
	switch (boss_id)
	{
	case eHead:
		m_shaking_head = 0;
		m_headvec3D = CVector3D(0,0,0);
		m_head.ChangeAnimation(eAnimBossBless);
		if (m_head.GetIndex() == 2) {
			m_state = eIdol;
			m_headpos3D.y += 10;
		}
		break;

	case eTail:
		m_flipH = false;
		m_shaking_tail = 0;
		m_tailvec3D = CVector3D(0, 0, 0);
		m_tail.ChangeAnimation(eAnimBossTailAttack);
		if (m_tail.GetIndex() == 3) {
			m_state = eIdol;
			m_tailpos3D.x -= 30;
		}
		
		break;
	}
}

void CBossBase::Fall( int boss_id) {

}

void CBossBase::Damage( int boss_id) {

}

void CBossBase::Down(int boss_id) {

	switch (boss_id)
	{
	case eHead:
		m_headvec3D.y = 0;
		m_shaking_head = 0;
		m_headvec3D = CVector3D(0, 0, 0);
		//m_headpos3D.y = 0;
		m_head.ChangeAnimation(eAnimBossDown);
		//m_headpos3D.y += m_headvec3D.y;
		for (; m_headpos3D.y < BOSS_POS_DOWN_Y;)
		{
			m_headpos3D += m_headvec3D;
			m_headvec3D.y += BOSS_DOWN_SPEED;
			break;
		}

		if (m_headpos3D.y > 0) {
			m_headvec3D.y = 0;
			for (; m_headpos3D.y > BOSS_POS_Y;) {
				m_headpos3D += m_headvec3D;
				m_headvec3D.y -= BOSS_DOWN_SPEED;
				break;
			}
			if (m_head.GetIndex() == 2)
			m_state = eIdol;
			
		}
		
		break;
	default:
		break;
	}
	
}


void CBossBase::Draw() {
	//Utility::DrawCircle(CVector2D((m_pos3D.x  - m_scroll.x) + m_rect_F.m_right / 2,  (450 + m_pos3D.z / 2 - m_scroll.y) + m_rect_F.m_bottom), BOSS_SIZ_X / 5, CVector4D(0.5, 0, 0, 0.2));
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}

void CBossBase::BossBress()
{
}
