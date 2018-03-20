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
	a = CVector3D(0, 0, 0);
	m_cnt = 0;
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

	m_img.UpdateAnimation();
	CheckOverlap();
	m_rect_F.m_bottom = m_rect.m_bottom - m_pos3D.y;

}


void CEnemy1::Nutral() {

}
void CEnemy1::Move() {
	CTask *p = CTaskManager::GetInstance()->GetTask(eID_Player);
	CObjectBase *PL = dynamic_cast<CObjectBase*>(p);
	m_cnt++;
	m_pos3D += m_vec3D;
	if (m_pos3D.x - m_scroll.x < 0 || m_pos3D.x - m_scroll.x > SCREEN_WIDTH - ENEMY_SIZ_X) {
		m_flipH = !m_flipH;
	}
	a = PL->GetPos() - m_pos3D;
	if (m_cnt == 1) {
		if(a.Length() >= 64)
		m_vec3D = a.GetNormalize() * DARUMA_SPEED;
	}else if (60 <= m_cnt && m_cnt < 120) {
		m_vec3D = CVector3D(0, 0, 0);
	}else if (m_cnt == 120) {
		m_cnt = 0;
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
