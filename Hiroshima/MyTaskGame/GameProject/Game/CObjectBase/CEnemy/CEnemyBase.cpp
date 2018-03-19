#include "CEnemyBase.h"
#include "../GameProject/Source/Itemsource.h"

int CEnemyBase::m_enemy_cnt = 0;

CEnemyBase::CEnemyBase() :CObjectBase(eID_Enemy, eU_Enemy, eD_Object) {
	
}

CEnemyBase::~CEnemyBase()
{
	new CKoban(&(  CVector3D(m_pos3D.x + 20, m_pos3D.y, m_pos3D.z)));
	new CKoban(&(  CVector3D(m_pos3D.x - 20, m_pos3D.y, m_pos3D.z)));
	new CKoban(&(  CVector3D(m_pos3D.x + 10, m_pos3D.y, m_pos3D.z)));
	new CKoban(&(  CVector3D(m_pos3D.x - 10, m_pos3D.y, m_pos3D.z)));
	new CKoban(&(  CVector3D(m_pos3D.x + 30, m_pos3D.y, m_pos3D.z)));
	new COage(&(   CVector3D(m_pos3D.x - 30, m_pos3D.y, m_pos3D.z)));
	new CSake(&(   CVector3D(m_pos3D.x + 40, m_pos3D.y, m_pos3D.z)));
	new CKakera(&( CVector3D(m_pos3D.x + 40, m_pos3D.y, m_pos3D.z)));

	m_enemy_cnt--;
}

void CEnemyBase::DropItem() {

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
	m_img.ChangeAnimation(eAnimEnemyFall);
	DropItem();
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
void CEnemyBase::Damage() {
	m_vec3D.y = 0;
	m_pos3D += m_vec3D;
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
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}

void CEnemyBase::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Player) {
		if (t->GetState() == eAttack && m_state != eKnockBack) {
			if (m_hp >= 0) {
				m_damage = true;
				m_state = eKnockBack;
			}
			else {
				m_state = eFall;
			}
		}
		 /*if(t->GetState() != eAttack && m_state != eAttack){
			m_state = eAttack;
		}*/
	}
}
