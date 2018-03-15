
#include "CEnemy3.h"
/*

����ҁ@��

*/
//�΂̋�
CEnemy3::CEnemy3(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy3"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_pos3D = *pos;
	m_hp = HI_HP;
	m_at = HI_AT;
	m_rect = CRect(150, 150, 350, 350);
	m_rect_F = CRect(0, 0, ENEMY_SIZ_X, ENEMY_SIZ_Y);

	m_damage = false;
	m_end_flag = false;
	m_state = eMove;


}

CEnemy3::~CEnemy3() {
}

void CEnemy3::Update() {

	switch (m_state)
	{
		//�ҋ@
	case eIdol:
		Nutral();
		break;
		//�ړ�
	case eMove:
		Move();
		break;
		//�U��
	case eAttack:
		Attack();
		break;
		//�̂�����
	case eKnockBack:
		KnockBack();
		break;
		//�|���ꂽ�Ƃ�
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

void CEnemy3::Nutral() {

}

void CEnemy3::Move() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > GROUND_WIDTH - ENEMY_SIZ_X) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_vec3D.x = HI_SPEED;
	}
	else {
		m_vec3D.x = -HI_SPEED;
	}

	//�㉺���V
	m_a += HI_FLOAT;
	m_vec3D.y = sin(m_a) * 5;


	m_img.ChangeAnimation(eAnimEnemyMove);

}

void CEnemy3::Attack() {

}

void CEnemy3::KnockBack() {
	m_img.ChangeAnimation(eAnimEnemyKnockBack);
	Damage();
	if (m_img.GetIndex() == 1) {
		m_state = eMove;
	}
}

void CEnemy3::Fall() {
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

void CEnemy3::Damage() {
	m_vec3D.y = 0;
	m_pos3D += m_vec3D;
	if (m_damage) {
		m_hp--;
		m_damage = false;
		if (m_flipH) {
			m_vec3D.x = -HI_KNOCKBACK_SPEED;
		}
		else {
			m_vec3D.x = HI_KNOCKBACK_SPEED;
		}
	}
}