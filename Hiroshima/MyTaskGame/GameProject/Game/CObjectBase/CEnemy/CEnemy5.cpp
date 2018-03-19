
#include "CEnemy5.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//ì˜âÚ
CEnemy5::CEnemy5(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy5"));
	m_img.SetSize(NIKU_SIZ_X, NIKU_SIZ_Y);
	m_pos3D = *pos;
	m_hp = NIKU_HP;
	m_at = NIKU_AT;
	m_rect = CRect(80, 100, 300, 350);
	m_rect_F = m_rect;


}

void CEnemy5::Update() {
	switch (m_state)
	{
		//ë“ã@
	case eIdol:
		Nutral();
		break;
		//à⁄ìÆ
	case eMove:
		Move();
		break;
		//çUåÇ
	case eAttack:
		Attack();
		break;
		//ÇÃÇØÇºÇË
	case eKnockBack:
		KnockBack();
		break;
		//ì|Ç≥ÇÍÇΩÇ∆Ç´
	case eFall:
		Fall();
		break;
	}
	
	m_img.UpdateAnimation();
	CheckOverlap();
	m_rect_F.m_bottom = m_rect.m_bottom - m_pos3D.y;
}

void CEnemy5::Draw() {
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 - 128 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + (256 - NIKU_SIZ_Y) + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + (256 - NIKU_SIZ_Y) + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}


void CEnemy5::Nutral() {

}

void CEnemy5::Move() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x - m_scroll.x < 0 || m_pos3D.x - m_scroll.x > SCREEN_WIDTH - ENEMY_SIZ_X) {
		m_flipH = !m_flipH;
	}

	if (m_flipH) {
		m_vec3D.x = NIKU_SPEED;
	}
	else {
		m_vec3D.x = -NIKU_SPEED;
	}
	m_img.ChangeAnimation(eAnimEnemyMove);
}

void CEnemy5::Attack() {
	m_img.ChangeAnimation(eAnimEnemyAttack);
	if (m_img.GetIndex() == 2) {
		m_state = eMove;
	}
}

void CEnemy5::KnockBack() {
	m_img.ChangeAnimation(eAnimEnemyKnockBack);
	Damage();
	if (m_img.GetIndex() == 1) {
		m_state = eMove;
	}
}
