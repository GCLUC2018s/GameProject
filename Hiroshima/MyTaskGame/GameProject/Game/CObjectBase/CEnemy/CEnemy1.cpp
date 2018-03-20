#include "CEnemy1.h"

/*

製作者　青木

*/
//だるま
CEnemy1::CEnemy1(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_img.SetRect(0, 0, 512, 512);
	m_pos3D = *pos;
	m_hp = DARUMA_HP;
	m_at = DARUMA_AT;
	m_rect = CRect(64, 135, 166, 237);
	m_rect_F = m_rect;

}

void CEnemy1::Update() {
	switch (m_state)
	{
		//待機
	case eIdol:
		Nutral();
		break;
		//移動
	case eMove:
		Move();
		break;
		//攻撃
	case eAttack:
		Attack();
		break;
		//のけぞり
	case eKnockBack:
		KnockBack();
		break;
		//倒されたとき
	case eFall:
		Fall();
		break;
	}

	m_img.UpdateAnimation();
	CheckOverlap();
	m_rect_F.m_bottom = m_rect.m_bottom - m_pos3D.y;

	if (m_pos3D.y < 0) {
		m_vec3D.y += 1.0f;
	}else if(m_pos3D.y == 0){
	}else if (m_pos3D.y > 0) {
		if (abs(m_vec3D.y) > 2.0f)
			m_vec3D.y *= -0.8f;
		else
			m_vec3D.y = 0;
		m_pos3D.y = 0;
	}
}


void CEnemy1::Nutral() {

}
void CEnemy1::Move() {
	m_pos3D += m_vec3D;
	if (m_pos3D.x - m_scroll.x < 0 || m_pos3D.x - m_scroll.x > SCREEN_WIDTH - ENEMY_SIZ_X) {
		m_flipH = !m_flipH;
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
	m_img.ChangeAnimation(eAnimEnemyAttack);
	if (m_img.GetIndex() == 2) {
		m_state = eMove;
	}
}

void CEnemy1::KnockBack() {
	m_img.ChangeAnimation(eAnimEnemyKnockBack);
	Damage();
	if (m_img.GetIndex() == 1) {
		m_state = eMove;
	}
}
