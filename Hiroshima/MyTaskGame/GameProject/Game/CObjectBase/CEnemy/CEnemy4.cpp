#include "CEnemy4.h"
/*

êªçÏé“Å@ê¬ñÿ

*/

//Ç©Ç‹Ç¢ÇΩÇø
CEnemy4::CEnemy4(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy4"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_pos3D = *pos;
	m_hp = KAMAITACHI_HP;
	m_at = KAMAITACHI_AT;
	m_rect = CRect(57, 40, 201, 210);
	m_rect_F = CRect(57, 40, 201, ENEMY_SIZ_Y);
	m_state = eIdol;
	m_cnt = 0;
	m_move_cnt = 0;
	m_stop = false;
	//âeê›íË
	m_img_shadow = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Shadow"));
	m_img_shadow.SetSize(144, 37);
	m_img_shadow.SetCenter(-57, 37 / 2);
}

void CEnemy4::Update() {

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

	//çüèàÇ≈ë“ã@éûä‘Çí≤êÆâ¬î\
	if (m_cnt > KAMAITACHI_MOVE_TIME) {
		m_state = eMove;
		m_cnt = 0;
	}

	m_img.UpdateAnimation();
	CheckOverlap();
	m_rect_F.m_bottom = ENEMY_SIZ_Y - m_pos3D.y;
}

void CEnemy4::Nutral() {
	//è„â∫ïÇóV
	m_vec3D.x = 0;
	m_stop = false;
	m_a += KAMAITACHI_FLOAT;
	m_vec3D.y = sin(m_a) * 5;
	m_pos3D += m_vec3D;
	m_cnt++;
	m_img.ChangeAnimation(eAnimIdol);
}

void CEnemy4::Attack() {
	m_img.ChangeAnimation(eAnimKamaAttack);
	if (m_img.GetIndex() == 2) {
		m_state = eIdol;
	}
}

void CEnemy4::Move() {
	m_vec3D.y = 0;

	//àÍíËÇÃèÍèäÇ‹Ç≈óàÇΩÇÁîΩì]
	if (m_pos3D.x - m_scroll.x < 0) {
		m_pos3D.x = 0 - m_scroll.x;
		m_flipH = false;
	}
	if (m_pos3D.x - m_scroll.x > SCREEN_WIDTH - ENEMY_SIZ_X) {
		m_pos3D.x = SCREEN_WIDTH - ENEMY_SIZ_X - m_scroll.x;
		m_flipH = true;
	}
	//å¸Ç¢ÇƒÇ¢ÇÈï˚å¸Ç…êiÇﬁ

	if (!m_stop) {
		CTask *p = CTaskManager::GetInstance()->GetTask(eID_Player);
		CObjectBase *PL = dynamic_cast<CObjectBase*>(p);
		m_cnt++;
		m_pos3D += m_vec3D;
		if (m_pos3D.x - m_scroll.x < 0)
			m_flipH = false;
		if (m_pos3D.x - m_scroll.x > SCREEN_WIDTH - ENEMY_SIZ_X)
			m_flipH = true;
		m_pleneVec = PL->GetPos() - m_pos3D;
		if (m_cnt == 1) {
				m_vec3D.x = m_pleneVec.GetNormalize().x * KAMAITACHI_SPEED;
			if (m_vec3D.x < 0)
				m_flipH = false;
			else
				m_flipH = true;
		}
		else if (60 <= m_cnt && m_cnt < 120) {
			m_vec3D = CVector3D(0, 0, 0);
		}
		else if (m_cnt == 120) {
			m_cnt = 0;
		}
	}
	else {
		m_state = eAttack;
	}

	if (m_cnt > KAMAITACHI_STOP_TIME) {
		m_stop = true;
		m_cnt = 0;
	}
	m_img.ChangeAnimation(eAnimKamaMove);
}

void CEnemy4::KnockBack() {
	m_img.ChangeAnimation(eAnimKamaKnockBack);
	Damage();
	m_cnt = 0;
	if (m_img.GetIndex() == 1) {
		m_state = eIdol;
	}
}
