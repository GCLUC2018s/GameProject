#include "CEnemyBase.h"
#include "../GameProject/Source/Itemsource.h"
#include "../CEffectBase/CEffectBase.h"

int CEnemyBase::m_enemy_cnt = 0;

CEnemyBase::CEnemyBase() :CObjectBase(eID_Enemy, eU_Enemy, eD_Object),
m_damage(false),
m_end_flag(false)
{
	damage_vec = CVector2D(10, -10);
	m_state = eMove;

}

CEnemyBase::~CEnemyBase()
{
	m_enemy_cnt--;
}

void CEnemyBase::DropItem() {
	for (int i = Utility::Rand(30, 50); i > 0; i--) {
		new CKoban(&(CVector3D(m_pos3D.x + 128, m_pos3D.y, m_pos3D.z)));
	}
	for (int i = Utility::Rand(-2, 2); i > 0; i--) {
		new CKakera(&(CVector3D(m_pos3D.x + 128, m_pos3D.y, m_pos3D.z)));
	}
	for (int i = Utility::Rand(-2, 2); i > 0; i--) {
		new CSake(&(CVector3D(m_pos3D.x + 128, m_pos3D.y, m_pos3D.z)));
	}
	for (int i = Utility::Rand(-2, 2); i > 0; i--) {
		new COage(&(CVector3D(m_pos3D.x + 128, m_pos3D.y, m_pos3D.z)));
	}

}

void CEnemyBase::Nutral(const int *enemy_id) {

}
void CEnemyBase::Move(const int *enemy_id) {

}
void CEnemyBase::Attack(const int *enemy_id) {

}
void CEnemyBase::KnockBack(const int *enemy_id) {

}
void CEnemyBase::Fall() {
	m_rect = CRect(0, 0, 0, 0);
	m_pos3D += m_vec3D;
	m_img.ChangeAnimation(eAnimEnemyFall);

	//xå∏ë¨
	if (m_flipH)
		m_vec3D.x = Price_Up(m_vec3D.x, 0, 0.5f);
	else
		m_vec3D.x = Price_Down(m_vec3D.x, 0, 0.5f);

	if (!m_end_flag) {
		if (m_flipH)
			m_vec3D.x = -damage_vec.x;
		else
			m_vec3D.x = damage_vec.x;
		m_vec3D.y = damage_vec.y;
	}
	m_vec3D = Blow(m_vec3D);

	if (m_end_flag == false) {
		m_end_flag = true;
		m_color.w = 2.0;
	}
	if (m_end_flag) {
		m_color.w -= 0.02;
	}
	if (m_color.w < -1.0) {
		DropItem();
		SetKill();
	}
}
void CEnemyBase::Damage() {
//	m_pos3D += m_vec3D;
	if (m_damage) {
		m_hp--;
		m_damage = false;
		m_vec3D.x = 0;


		//if (m_flipH) {
		//	m_vec3D.x = -CHOCHIN_KNOCKBACK_SPEED;
		//}
		//else {
		//	m_vec3D.x = CHOCHIN_KNOCKBACK_SPEED;
		//}
	}

}
void CEnemyBase::Draw() {
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
//	Utility::DrawCircle(CVector2D((m_pos3D.x  - m_scroll.x) + m_rect_F.m_right / 2,  (450 + m_pos3D.z / 2 - m_scroll.y) + m_rect_F.m_bottom), ENEMY_SIZ_X / 5, CVector4D(0.5, 0, 0, 0.2));
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img_shadow.SetColor(1, 1, 1, m_color.w + (m_pos3D.y * 0.005));
	m_img_shadow.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_rect_F.m_bottom + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img_shadow.Draw();
	m_img.Draw();
//	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
//	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}

void CEnemyBase::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Effect) {
		CEffectBase *ef = dynamic_cast<CEffectBase*>(t);
		if (ef->GetHit() > 1.0f && m_state != eKnockBack) {
			if (ef->GetEFtype() == ePanch && abs(ef->GetPos().y + m_pos3D.y) < 20) {
				SOUND("SE_Panch")->Play(false);
				m_flipH = !(ef->GetFrip());
				if (m_hp >= 0) {
					m_damage = true;
					m_state = eKnockBack;
				}
				else {
					m_state = eFall;
				}
			}
			if (ef->GetEFtype() == eFire) {
				if (m_deathblow) {
					m_hp = -1;
				}
				m_flipH = !(ef->GetFrip());
				if (m_hp >= 0) {
					m_damage = true;
					m_state = eKnockBack;
				}
				else {
					m_state = eFall;
				}
			}
		}
	}
}

//êÅÇ¡îÚÇ—
CVector3D CEnemyBase::Blow(CVector3D vec) {
	m_vec3D.z = 0;
	m_vec3D.y += 1.0f;
	if (m_pos3D.y > 0) {
		m_pos3D.y = 0;
		damage_vec.y *= 0.8f;
		m_vec3D.y = damage_vec.y;
	}
	return m_vec3D;
}
