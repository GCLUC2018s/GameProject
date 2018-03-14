#include "CEnemy2.h"


/*

êªçÏé“Å@ê¬ñÿ

*/
//íÒìî
CEnemy2::CEnemy2(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy2"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_pos3D = *pos;
	m_hp = CHOCHIN_HP;
	m_at = CHOCHIN_AT;
	m_rect = CRect(190, 140, 400, 340);
	m_rect_F = CRect(0, 0, ENEMY_SIZ_X, ENEMY_SIZ_Y);
<<<<<<< HEAD
=======
	m_damage = false;
	m_end_flag = false;
	m_state = eMove;
>>>>>>> 7eded4456690c0b723adcb87e2aabebafd115dc8
}

CEnemy2::~CEnemy2() {
}

void CEnemy2::Update() {
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


void CEnemy2::Nutral() {

}

void CEnemy2::Move() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > GROUND_WIDTH - ENEMY_SIZ_X) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = CHOCHIN_SPEED;
	}
	else {
		m_vec3D.x = -CHOCHIN_SPEED;
	}

	//è„â∫ïÇóV
	m_a += CHOCHIN_FLOAT;
	m_vec3D.y = sin(m_a) * 2;


	m_img.ChangeAnimation(eAnimEnemyMove);
}

void CEnemy2::Attack() {

}

void CEnemy2::KnockBack() {
	m_img.ChangeAnimation(eAnimEnemyKnockBack);
	Damage();
	if (m_img.GetIndex() == 1) {
		m_state = eMove;
	}
}

void CEnemy2::Fall() {
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

void CEnemy2::Damage() {
	m_vec3D.y = 0;
	m_pos3D += m_vec3D;
	if (m_damage) {
		m_hp--;
		m_damage = false;
		if (m_flipH) {
			m_vec3D.x = -CHOCHIN_KNOCKBACK_SPEED;
		}
		else {
			m_vec3D.x = CHOCHIN_KNOCKBACK_SPEED;
		}
	}
}