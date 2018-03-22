
#include "CEnemy5.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
//ì˜âÚ
CEnemy5::CEnemy5(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy5"));
	m_img.SetSize(NIKU_SIZ_X, NIKU_SIZ_Y);
	m_img.SetCenter(0, 128);
	m_pos3D = *pos;
	m_pos3D.y = 0;
	m_hp = NIKU_HP;
	m_at = NIKU_AT;
	m_rect = CRect(80, -28, 300, 222);
	m_rect_F = m_rect;
	//âeê›íË
	m_img_shadow = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Shadow"));
	m_img_shadow.SetSize(220, 57);
	m_img_shadow.SetCenter(-80, 57 / 2);

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
	m_rect_F.m_bottom = 237 - m_pos3D.y;
}


void CEnemy5::Nutral() {

}

void CEnemy5::Move() {
	CTask *p = CTaskManager::GetInstance()->GetTask(eID_Player);
	CObjectBase *PL = dynamic_cast<CObjectBase*>(p);

	m_cnt++;
	if(m_pos3D.x - m_scroll.x >= 50 && m_pos3D.x - m_scroll.x <= SCREEN_WIDTH - 50 - NIKU_SIZ_X)
	m_pos3D += m_vec3D;

	//àÍíËÇÃèÍèäÇ‹Ç≈óàÇΩÇÁîΩì]
	if (m_pos3D.x - m_scroll.x < 50) {
		m_pos3D.x = m_scroll.x + 50;
		m_flipH = false;
	}
	if (m_pos3D.x - m_scroll.x > SCREEN_WIDTH - 50 - NIKU_SIZ_X) {
		m_pos3D.x = m_scroll.x + SCREEN_WIDTH - 50 - ENEMY_SIZ_X;
		m_flipH = true;
	}

	m_pleneVec = PL->GetPos() - m_pos3D;

	if (m_cnt == 1) {
		if (m_pleneVec.Length() >= 64)
			m_vec3D.x = m_pleneVec.GetNormalize().x * NIKU_SPEED;
		if (m_vec3D.x < 0)
			m_flipH = false;
		else
			m_flipH = true;
	}
	else if (60 <= m_cnt && m_cnt < 180) {
		m_vec3D = CVector3D(0, 0, 0);
	}
	else if (m_cnt == 180) {
		m_cnt = 0;
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
