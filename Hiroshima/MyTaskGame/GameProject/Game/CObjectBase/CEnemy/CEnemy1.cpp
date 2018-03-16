#include "CEnemy1.h"

/*

êªçÏé“Å@ê¬ñÿ

*/
//ÇæÇÈÇ‹
CEnemy1::CEnemy1(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_img.SetRect(0, 0, 512, 512);
	m_pos3D = *pos;
	m_hp = DARUMA_HP;
	m_at = DARUMA_AT;
	m_rect = CRect(64, 135, 166, 237);
	m_rect_F = m_rect;

	m_damage = false;
	m_end_flag = false;
	m_state = eMove;

}

CEnemy1::~CEnemy1() {
}

void CEnemy1::Update() {
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

	if (PUSH_R) {
		if (m_hp >= 0) {
			m_damage = true;
			m_state = eKnockBack;
		}
		else {
			m_state = eFall;
		}
	}
	
	m_img.UpdateAnimation();
	CheckOverlap();
}


void CEnemy1::Nutral() {

}
void CEnemy1::Move() {
	m_pos3D += m_vec3D;
	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > GROUND_WIDTH - ENEMY_SIZ_X) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = DARUMA_SPEED;
	}
	else {
		m_vec3D.x = -DARUMA_SPEED;
	}


	m_img.ChangeAnimation(eAnimEnemyMove);
}

void CEnemy1::Attack() {

}

void CEnemy1::KnockBack() {
	m_img.ChangeAnimation(eAnimEnemyKnockBack);
	Damage();
	if (m_img.GetIndex() == 1) {
		m_state = eMove;
	}
}

void CEnemy1::Fall(){
	m_img.ChangeAnimation(eAnimEnemyFall);
	m_img.SetColor(m_color.r, m_color.g, m_color.b, m_color.a);
	DropItem();
	if (m_end_flag == false) {
		m_end_flag = true;
		m_color.a = 2.0;
	}
	if (m_end_flag) {
		m_color.a -= 0.02;
	}
	if (m_color.a < -1.0) {
		SetKill();
	}
}

void CEnemy1::Damage(){
	m_vec3D.y = 0;
	m_pos3D += m_vec3D;
	if (m_damage) {
		m_hp--;
		m_damage = false;
		if (m_flipH) {
			m_vec3D.x = -DARUMA_KNOCKBACK_SPEED;
		}
		else {
			m_vec3D.x = DARUMA_KNOCKBACK_SPEED;
		}
	}
}