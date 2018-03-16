#include "CEnemyBase.h"

CEnemyBase::CEnemyBase() :CObjectBase(eID_Enemy, eU_Enemy, eD_Object) {
	
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
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}

void CEnemyBase::Hit(CTask * t)
{
	////PL‚ª•Ô‚Á‚Ä‚­‚é
	//CObjectBase* pl = dynamic_cast<CObjectBase*>(t);

}
