#include "CEnemyBase.h"


CEnemyBase::CEnemyBase() :CObjectBase(eID_Enemy, eU_Enemy, eD_Chara) {
	
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
void CEnemyBase::Fall(const int *enemy_id) {

}
void CEnemyBase::Damage(const int *enemy_id) {

}
void CEnemyBase::Draw() {
//	Utility::DrawCircle(CVector2D((m_pos3D.x  - m_scroll.x) + m_rect_F.m_right / 2,  (450 + m_pos3D.z / 2 - m_scroll.y) + m_rect_F.m_bottom), ENEMY_SIZ_X / 5, CVector4D(0.5, 0, 0, 0.2));
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x /*+ m_variation*/ - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
}
