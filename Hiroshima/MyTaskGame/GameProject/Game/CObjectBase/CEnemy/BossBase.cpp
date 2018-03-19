#include "BossBase.h"

CBossBase::CBossBase() :CObjectBase(eID_Boss, eU_Enemy, eD_Object) {

}



void CBossBase::Nutral(const int *boss_id) {

	switch (*boss_id)
	{
	case eHead:
		m_head.ChangeAnimation(0);
		m_shaking_head += BOSS_FLOAT_HEAD;
		//m_headvec3D.x = -cos(m_shaking + Utility::DgreeToRadian(90)) * 5;
		m_headvec3D.y = -sin(m_shaking_head) * 1;
		break;
	case eArm:
		m_arm.ChangeAnimation(3);
		m_shaking_arm += BOSS_FLOAT_ARM;
		m_armvec3D.x = cos(m_shaking_arm + Utility::DgreeToRadian(180)) * 2;
		m_armvec3D.y = sin(m_shaking_arm);
		break;
	case eArm2:
		m_arm2.ChangeAnimation(2);
		m_shaking_arm += BOSS_FLOAT_ARM;
		m_arm2vec3D.x = -cos(m_shaking_arm + Utility::DgreeToRadian(180)) * 2;
		m_arm2vec3D.y = sin(m_shaking_arm);
		break;
	case eTail:
		m_tail.ChangeAnimation(1);
		m_shaking_head += BOSS_FLOAT_TAIL;
		m_tailvec3D.x = -cos(m_shaking_head + Utility::DgreeToRadian(180)) * 5;
		//m_tailvec3D.y = -sin(m_shaking) * 5;
		break;
	}


}
void CBossBase::Move(const int *boss_id) {
	switch (*boss_id)
	{
	default:
		break;
	}
}
void CBossBase::Attack(const int *boss_id) {
	switch (*boss_id)
	{
	case eHead:
		break;

	case eTail:
		break;
	}
}

void CBossBase::Fall(const int *boss_id) {

}
void CBossBase::Damage(const int *boss_id) {

}

void CBossBase::Draw() {
	//	Utility::DrawCircle(CVector2D((m_pos3D.x  - m_scroll.x) + m_rect_F.m_right / 2,  (450 + m_pos3D.z / 2 - m_scroll.y) + m_rect_F.m_bottom), ENEMY_SIZ_X / 5, CVector4D(0.5, 0, 0, 0.2));
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}
