
#include "CEnemy3.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//âŒÇÃã 
CEnemy3::CEnemy3(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy3"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_pos3D = *pos;
	m_hp = HI_HP;
	m_at = HI_AT;
	m_rect = CRect(75, 80, 160, 165);
	m_rect_F = CRect(75, 80, 160, ENEMY_SIZ_Y);

	m_damage = false;
	m_end_flag = false;
	m_state = eMove;


}

void CEnemy3::Update() {

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
	m_rect_F.m_bottom = ENEMY_SIZ_Y - m_pos3D.y;
}

void CEnemy3::Nutral() {

}

void CEnemy3::Move() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x - m_scroll.x < 0 || m_pos3D.x - m_scroll.x > SCREEN_WIDTH - ENEMY_SIZ_X) {
		m_flipH = !m_flipH;
	}
	if (m_flipH) {
		m_vec3D.x = HI_SPEED;
	}
	else {
		m_vec3D.x = -HI_SPEED;
	}

	//è„â∫ïÇóV
	m_a += HI_FLOAT;
	m_vec3D.y = sin(m_a) * 5;


	m_img.ChangeAnimation(eAnimEnemyMove);

}

void CEnemy3::Attack() {
	m_img.ChangeAnimation(eAnimEnemyAttack);
	if (m_img.GetIndex() == 2) {
		m_state = eMove;
	}
}

void CEnemy3::KnockBack() {
	m_img.ChangeAnimation(eAnimEnemyKnockBack);
	Damage();
	if (m_img.GetIndex() == 1) {
		m_state = eMove;
	}
}