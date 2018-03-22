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
	m_rect = CRect(77, 68, 170, 161);
	m_rect_F = CRect(77, 68, 170, ENEMY_SIZ_Y);
	//âeê›íË
	m_img_shadow = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Shadow"));
	m_img_shadow.SetSize(93, 24);
	m_img_shadow.SetCenter(-77, 24 / 2);

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
	//if (m_pos3D.y < 0) {
	//	m_vec3D.y += 1.0f;
	//}
	//else if (m_pos3D.y == 0) {
	//}
	//else if (m_pos3D.y > 0) {
	//	if (abs(m_vec3D.y) > 2.0f)
	//		m_vec3D.y *= -0.8f;
	//	else
	//		m_vec3D.y = 0;
	//	m_pos3D.y = 0;
	//}
	//è„â∫ïÇóV
	m_a += CHOCHIN_FLOAT;
	m_vec3D.y = sin(m_a) * 2;

	m_img.UpdateAnimation();
	CheckOverlap();
	m_rect_F.m_bottom = ENEMY_SIZ_Y - m_pos3D.y;

}


void CEnemy2::Nutral() {

}

void CEnemy2::Move() {
	CTask *p = CTaskManager::GetInstance()->GetTask(eID_Player);
	CObjectBase *PL = dynamic_cast<CObjectBase*>(p);
	m_cnt++;
	if (m_pos3D.x - m_scroll.x >= 50 && m_pos3D.x - m_scroll.x <= SCREEN_WIDTH - 50 - ENEMY_SIZ_X)
	m_pos3D += m_vec3D;
	//àÍíËÇÃèÍèäÇ‹Ç≈óàÇΩÇÁîΩì]
	if (m_pos3D.x - m_scroll.x < 50) {
		m_pos3D.x = m_scroll.x + 50;
		m_flipH = false;
	}
	if (m_pos3D.x - m_scroll.x > SCREEN_WIDTH - 50 - ENEMY_SIZ_X) {
		m_pos3D.x = m_scroll.x + SCREEN_WIDTH - 50 - ENEMY_SIZ_X;
		m_flipH = true;
	}
	m_pleneVec = PL->GetPos() - m_pos3D;
	if (m_cnt == 1) {
		if (m_pleneVec.Length() >= 512) {
			if (TWO_RANDOM) {
				if (m_pos3D.x < SCREEN_WIDTH - ENEMY_SIZ_X + m_scroll.x)
				m_vec3D.x = 2;
			}else {
				if (0 + m_scroll.x < m_pos3D.x)
				m_vec3D.x = -2;
			}
		}else if (100 <= m_pleneVec.Length())
			m_vec3D.x = m_pleneVec.GetNormalize().x * CHOCHIN_SPEED;
		else {
			m_vec3D.x = -m_pleneVec.GetNormalize().x * CHOCHIN_SPEED;
		}
		if (m_vec3D.x < 0)
			m_flipH = false;
		else
			m_flipH = true;
	}
	else if (60 <= m_cnt && m_cnt < 150) {
		m_vec3D = CVector3D(0, 0, 0);
	}
	else if (m_cnt == 150) {
		if (256 >= m_pleneVec.Length())
			m_state = eAttack;
		m_cnt = 0;
	}
	//è„â∫ïÇóV
	m_a += CHOCHIN_FLOAT;
	m_vec3D.y = sin(m_a) * 2;


	m_img.ChangeAnimation(eAnimEnemyMove);
}

void CEnemy2::Attack() {
	m_img.ChangeAnimation(eAnimEnemyAttack);
	if (m_img.GetIndex() == 2) {
		m_state = eMove;
	}
}

void CEnemy2::KnockBack() {
	m_img.ChangeAnimation(eAnimEnemyKnockBack);
	Damage();
	if (m_img.GetIndex() == 1) {
		m_state = eMove;
	}
}
