#include "BossBase.h"
#include "../CEffectBase/CEffectBase.h"
#include "../CCharge.h"
#include "../CBeam.h"

CBossBase::CBossBase() :CObjectBase(eID_Boss, eU_Enemy, eD_Object) {
	m_shaking_head = 0;
	m_shaking_arm = 0;
	m_shaking_tail = 0;
	m_shaking_head = 0;
	m_headvec3D = CVector3D(0, 0, 0);
	m_down = false;
	m_downtime = 0;
	m_armtime = 0;
	m_end_flag = false;
	m_nagi = true;
	m_dame_time = 0;
}



void CBossBase::Nutral( int boss_id) {

	switch (boss_id)
	{
	case eHead:
		m_head.ChangeAnimation(eAnimBossHeadIdol);
		m_shaking_head += BOSS_FLOAT_HEAD;
		//m_headvec3D.x = -cos(m_shaking_head + Utility::DgreeToRadian(90)) * 5;
		m_headvec3D.y = -sin(m_shaking_head) * 1;
		m_down = false;
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
		m_tailvec3D.x = -cos(m_shaking_tail + Utility::DgreeToRadian(180)) * 1;
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

void CBossBase::Attack(int boss_id) {
	switch (boss_id)
	{
	case eHead:
		m_shaking_head = 0;
		m_headvec3D = CVector3D(0, 0, 0);
		m_head.ChangeAnimation(eAnimBossBless);
		BossBress();
		break;

	case eTail:
		BossTailAttack();
		break;
	case eArm:
		m_shaking_arm = 0;
		m_armvec3D = CVector3D(0, 0, 0);
		BossLaser();
		break;
	}
}

void CBossBase::Fall() {
	if (m_end_flag == false) {
		m_shaking_tail = 0;
		m_shaking_head = 0;
		m_shaking_arm = 0;
		m_armvec3D = CVector3D(-1, 1, 0);
		m_arm2vec3D = CVector3D(1, 1, 0);
		m_headvec3D = CVector3D(0, 1, 0);
		m_tailvec3D = CVector3D(0, 1, 0);
		m_end_flag = true;
		m_color.w = 2.0;
		m_head.ChangeAnimation(eAnimBossDown);
	}
	if (m_end_flag) {
		m_color.w -= 0.005;
	}
	if (m_color.w < -1.0) {
		SetKill();
	}
}

void CBossBase::Damage(int boss_id) {
	if (m_dame_time == 0) {
		m_hp--;
	}
	m_color.y = 0.5;
	m_color.z = 0.5;
	m_dame_time++;
	if (m_dame_time == 15) {
		SetNotDame();
	}
}

void CBossBase::Down(int boss_id) {

	switch (boss_id)
	{
	case eHead:
	
		m_headpos3D += m_headvec3D;

		if (m_head.GetIndex() >= 1) {
		}else {
			m_head.ChangeAnimation(eAnimBossDown);
		}

		if (!m_down) {
			if (m_headpos3D.y < BOSS_POS_DOWN_Y){
				m_headvec3D.y += BOSS_DOWN_SPEED;
			}else {
				m_headvec3D.y = 0;
				
				if (m_downtime > BOSS_DOWN_TIME) {
					m_down = true;
				}else {
					m_downtime++;
				}
			}
		
		}else {
			if (m_headpos3D.y > BOSS_POS_Y) {
				m_headvec3D.y -= BOSS_DOWN_SPEED;
			}else {
				m_headvec3D.y = 0;
			}
			m_head.ChangeAnimation(eAnimBossHeadIdol);
			if (m_headpos3D.y < BOSS_POS_Y)
				m_state = eIdol;
				m_downtime = 0;
				
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
	//Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	//Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}



void CBossBase::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Effect) {
		CEffectBase *ef = dynamic_cast<CEffectBase*>(t);
		if (ef->GetHit() > 1.0f && !m_damage && m_state == eIdol) {
			if ((ef->GetEFtype() == ePanch && abs(ef->GetPos().z - m_headpos3D.z) < 50)||
				(ef->GetEFtype() == ePanch && abs(ef->GetPos().z - m_armpos3D.z) <  50) ||
				(ef->GetEFtype() == ePanch && abs(ef->GetPos().z - m_arm2pos3D.z) < 50) ||
				(ef->GetEFtype() == ePanch && abs(ef->GetPos().z - m_tailpos3D.z) < 50)){
				SOUND("SE_Panch")->Play(false);
			//	m_flipH = !(ef->GetFrip());
				if (m_hp >= 0) {
					m_damage = true;
					m_state = eDamage;
					//m_state = eDamage;
					//m_state = eKnockBack;
				}
				else {
					//Fall();
				m_state = eFall;
				}
			}
			if (ef->GetEFtype() == eFire) {
				if (m_deathblow) {
					m_hp -= 50;
				}
				//m_flipH = !(ef->GetFrip());
				if (m_hp >= 0) {
					m_damage = true;
					m_state = eDamage;
					//m_state = eDamage;
					//m_state = eKnockBack;
				}
				else {
					//Fall();
					m_state = eFall;
				}
			}
		}
	}
}

//ブレス攻撃
void CBossBase::BossBress() {
	m_headpos3D += m_headvec3D;
	CObjectBase *PL = dynamic_cast<CObjectBase*>(CTaskManager::GetInstance()->GetTask(eID_Player));

	switch (m_head.GetIndex()) {
	case 0:
		m_headpos3D.x = SCREEN_WIDTH;
		m_playervec = PL->GetPos() - m_headpos3D + CVector3D(0, 200, 0);
		m_headvec3D.y = m_playervec.GetNormalize().y * 30;
		break;
	case 1:
		m_headpos3D.x -= 2;
		m_playervec = PL->GetPos() - m_headpos3D + CVector3D(0, 200, 0);
		m_headvec3D.y = m_playervec.GetNormalize().y * 30;
		break;
	case 2:
		new CCharge(CVector2D(m_headpos3D.x - 80, m_headpos3D.y + 330),true);
		SOUND("SE_Mahou_Kaen")->Play(false);
		break;
	case 4:
		m_headpos3D.x += 4;
		break;
	case 5:
		SetNotDame();
		m_headpos3D = m_headoldpos3D;
		m_armpos3D = m_armoldpos3D;
		m_arm2pos3D = m_arm2oldpos3D;
		m_tailpos3D = m_tailoldpos3D;
		m_headpos3D.y -= 600;
		m_armpos3D.y  -= 600;
		m_arm2pos3D.y -= 600;
		m_tailpos3D.y -= 600;
		m_headvec3D = CVector3D(0, 0, 0);
		m_armvec3D = CVector3D(0, 0, 0);
		m_arm2vec3D = CVector3D(0, 0, 0);
		m_tailvec3D = CVector3D(0, 0, 0);
		m_state = eDescent;
		break;

	}
}
//じゃんぷ
void CBossBase::BossJump() {
	//顔が上に向いて
	m_head.ChangeAnimation(eAnimBossJump);
	m_head.SetAng(90);
	m_arm2.SetFlipH(true);
	m_arm2.SetAng(-70);
	m_tail.SetAng(-70);

	//べく操作
	m_headvec3D.y = Price_Down(m_headvec3D.y, -5, 0.2);
	 m_armvec3D.y = Price_Down( m_armvec3D.y, -5, 0.2);
	m_arm2vec3D.y = Price_Down(m_arm2vec3D.y, -5, 0.2);
	m_tailvec3D.y = Price_Down(m_tailvec3D.y, -5, 0.2);

	//ポス操作
	m_headpos3D.y += m_headvec3D.y;
	m_armpos3D.y += m_armvec3D.y;
	m_arm2pos3D.y += m_arm2vec3D.y;
	m_tailpos3D.y += m_tailvec3D.y;
	if (m_head.GetIndex() == 1) {
		SetNotDame();
		m_head.SetAng(0);
		m_arm2.SetFlipH(false);
		m_arm2.SetAng(0);
		m_tail.SetAng(0);
		m_state = eLaserShower;
	}

}
//降下
void CBossBase::BossDescent() {
	//べく操作
	m_headvec3D.y = Price_Up(m_headvec3D.y, 5, 0.2);
	 m_armvec3D.y = Price_Up(m_armvec3D.y,  5, 0.2);
	m_arm2vec3D.y = Price_Up(m_arm2vec3D.y, 5, 0.2);
	m_tailvec3D.y = Price_Up(m_tailvec3D.y, 5, 0.2);

	//ポス操作
	m_headpos3D.y += m_headvec3D.y;
	m_armpos3D.y  += m_armvec3D.y;
	m_arm2pos3D.y += m_arm2vec3D.y;
	m_tailpos3D.y += m_tailvec3D.y;
	if (m_headpos3D.y > 0) {
		SetNotDame();
		m_headvec3D = CVector3D(0, 0, 0);
		m_armvec3D = CVector3D(0, 0, 0);
		m_arm2vec3D = CVector3D(0, 0, 0);
		m_tailvec3D = CVector3D(0, 0, 0);
		m_state = eIdol;
	}

}
void CBossBase::BossLaser() {
//	m_armpos3D += m_armvec3D;
	m_armtime++;

	if (m_armtime < 180) {
//		m_armvec3D.y = Price_Up(m_armvec3D.y, 5, 0.2);
		if (m_armpos3D.y < -350) {
			m_playervec = CVector3D(695, -350, 0) - m_armpos3D;
			m_armvec3D = m_playervec.GetNormalize() * 10;
		}
		else {
			m_armpos3D = CVector3D(695, -350, 0);
			m_armvec3D = CVector3D(0, 0, 0);
		}
	}
	if (m_armtime == 180) {
		new CBeam(CVector2D(640, -240));
		m_armvec3D.y = 0;
	}
	if (m_armtime >= 300) {
		//m_armpos3D.y -= 50;
			m_armvec3D.y = -70 / 10;
			m_armvec3D.x = 50 / 50;
	}
	if (m_armtime == 420) {
		m_armtime = 0;
		SetNotDame();
		m_headpos3D = m_headoldpos3D;
		m_armpos3D = m_armoldpos3D;
		m_arm2pos3D = m_arm2oldpos3D;
		m_tailpos3D = m_tailoldpos3D;
		m_headpos3D.y -= 600;
		m_armpos3D.y -= 600;
		m_arm2pos3D.y -= 600;
		m_tailpos3D.y -= 600;
		m_headvec3D = CVector3D(0, 0, 0);
		m_armvec3D = CVector3D(0, 0, 0);
		m_arm2vec3D = CVector3D(0, 0, 0);
		m_tailvec3D = CVector3D(0, 0, 0);
		m_state = eDescent;
	}
}

void CBossBase::BossTailAttack() {

	m_tail.ChangeAnimation(eAnimBossTailAttack);
	switch (m_tail.GetIndex())
	{
	case 0:
		CCharge(CVector2D(m_tailpos3D.x, m_tailpos3D.y), false);
		m_tailpos3D.x = -1000;
		m_tailpos3D.y = +200;
		m_tailvec3D = CVector3D(0, 0, 0);
		break;

	case 8:
		SetNotDame();
		m_state = eDescent;
		m_tailpos3D.x -= 30;
		m_flipH = false;
		break;

	default:
		break;
	}
	if (m_nagi) {
		m_tailvec3D.x = Price_Up(m_tailvec3D.x, 10, 0.2);
		m_tail.SetFlipH(false);
		if (m_tailpos3D.x > SCREEN_WIDTH + 10)m_nagi = false;
	}
	else {
		m_tailvec3D.x = Price_Down(m_tailvec3D.x, -10, 0.2);
		m_tail.SetFlipH(true);
	}
	m_tailpos3D += m_tailvec3D;
	m_shaking_tail = 0;

}

