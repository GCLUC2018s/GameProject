
#include "CEnemy5.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//ì˜âÚ
CEnemy5::CEnemy5(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy5"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_pos3D = *pos;
	m_hp = NIKU_HP;
	m_at = NIKU_AT;
	m_rect = CRect(0, 0, ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_damage = false;
	m_end_flag = false;
	m_state = eMove;

}

CEnemy5::~CEnemy5() {
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
}



void CEnemy5::Nutral() {

}

void CEnemy5::Move() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > GROUND_WIDTH - ENEMY_SIZ_X) {
		m_flipH = false;
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

}

void CEnemy5::KnockBack() {
	m_img.ChangeAnimation(eAnimEnemyKnockBack);
	Damage();
	if (m_img.GetIndex() == 1) {
		m_state = eMove;
	}
}

void CEnemy5::Fall() {
	m_img.ChangeAnimation(eAnimEnemyFall);
	m_img.SetColor(m_color.r, m_color.g, m_color.b, m_color.a);
	DropItem();
	if (m_end_flag == false) {
		m_end_flag = true;
		m_color.a = 2.0;
	}
	if (m_end_flag) {
		m_color.a -= 0.01;
	}
	if (m_color.a < -1.0) {
		SetKill();
	}
}

void CEnemy5::Damage() {
	m_vec3D.y = 0;
	m_pos3D += m_vec3D;
	if (m_damage) {
		m_hp--;
		m_damage = false;
		if (m_flipH) {
			m_vec3D.x = -NIKU_KNOCKBACK_SPEED;
		}
		else {
			m_vec3D.x = NIKU_KNOCKBACK_SPEED;
		}
	}
}