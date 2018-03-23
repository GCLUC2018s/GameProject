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

void CBossBase::Attack( int boss_id) {
	switch (boss_id)
	{
	case eHead:
		m_shaking_head = 0;
		m_headvec3D = CVector3D(0,0,0);
		m_head.ChangeAnimation(eAnimBossBless);
		BossBress();
		break;

	case eTail:
		m_flipH = false;
		m_shaking_tail = 0;
		m_tailvec3D = CVector3D(0, 0, 0);
		m_tail.ChangeAnimation(eAnimBossTailAttack);
		if (m_tail.GetIndex() == 3) {
			m_state = eIdol;
			m_tailpos3D.x -= 30;

	case eArm:
		m_shaking_arm = 0;
		m_armvec3D = CVector3D(0, 0, 0);
		BossLaser();
		break;
		}
		
		break;
	}
}

void CBossBase::Fall() {
	if (m_end_flag == false) {
		m_end_flag = true;
		m_color.w = 2.0;
	}
	if (m_end_flag) {
		m_color.w -= 0.02;
	}
	if (m_color.w < -1.0) {
		SetKill();
	}
}

void CBossBase::Damage( int boss_id) {
	m_hp--;
	m_damage = false;
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
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}



void CBossBase::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Effect) {
		CEffectBase *ef = dynamic_cast<CEffectBase*>(t);
		if (ef->GetHit() > 1.0f && !m_damage) {
			if ((ef->GetEFtype() == ePanch && abs(ef->GetPos().z - m_headpos3D.z) < 50)||
				(ef->GetEFtype() == ePanch && abs(ef->GetPos().z - m_armpos3D.z) <  50) ||
				(ef->GetEFtype() == ePanch && abs(ef->GetPos().z - m_arm2pos3D.z) < 50) ||
				(ef->GetEFtype() == ePanch && abs(ef->GetPos().z - m_tailpos3D.z) < 50)){
				SOUND("SE_Panch")->Play(false);
			//	m_flipH = !(ef->GetFrip());
				if (m_hp >= 0) {
					m_damage = true;
					Damage(0);
					//m_state = eKnockBack;
				}
				else {
					Fall();
				}
			}
			if (ef->GetEFtype() == eFire) {
				if (m_deathblow) {
					m_hp -= 50;
				}
				//m_flipH = !(ef->GetFrip());
				if (m_hp >= 0) {
					m_damage = true;
					Damage(0);
					//m_state = eKnockBack;
				}
				else {
					Fall();
				}
			}
		}
	}
}


void CBossBase::BossBress(){
	m_headpos3D += m_headvec3D;
	CTask *p = CTaskManager::GetInstance()->GetTask(eID_Player);
	CObjectBase *PL = dynamic_cast<CObjectBase*>(p);

	switch (m_head.GetIndex()) {
	case 0:
		m_playervec = PL->GetPos() - m_headpos3D + CVector3D(0, 200, 0);
		m_headvec3D.y = m_playervec.GetNormalize().y * 30;
		break;
	case 1:
		m_playervec = PL->GetPos() - m_headpos3D + CVector3D(0, 200, 0);
		m_headvec3D.y = m_playervec.GetNormalize().y * 30;
		break;
	case 2:
		new CCharge(CVector2D(m_headpos3D.x - 30, m_headpos3D.y + 330));
		break;
	case 3:
		break;
	case 4:
		if (abs(m_headpos3D.y) > 1.0f)
			m_headvec3D.y = -m_headpos3D.y / 30;
		else
			m_headpos3D.y = 0;
		break;
	case 5:
		m_state = eIdol;
		m_headpos3D.y += 10;
		break;
		
	}
}

void CBossBase::BossLaser(){
	m_armpos3D += m_armvec3D;
	m_armtime++;

	if (m_armtime < 180) {
		if (m_playervec.Length() >= 5.0f) {
			m_playervec = CVector3D(695, -350, 0) - m_armpos3D;
			m_armvec3D = m_playervec.GetNormalize() * 4;
		}else {
			m_armpos3D = CVector3D(695, -350, 0);
			m_armvec3D = CVector3D(0, 0, 0);
		}
	}
	if (m_armtime == 180)
		new CBeam(CVector2D(640, -240));
	if (m_armtime >= 300) {
		if (abs(m_armpos3D.y) > 1.0f) {
			m_armvec3D.y = -m_armpos3D.y / 30;
			m_armvec3D.x = 50 / 30;
		}else {
			m_armpos3D.y = 0;
			m_armpos3D.x = 750;
		}
	}
	if (m_armtime == 420) {
		m_armtime = 0;
		m_state = eIdol;
	}
}