
#include "CEnemy3.h"
/*

製作者　青木

*/
//火の玉
CEnemy3::CEnemy3(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy3"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_pos3D = *pos;
	m_hp = HI_HP;
	m_at = HI_AT;
	m_rect = CRect(75, 80, 160, 165);
	m_rect_F = CRect(75, 80, 160, ENEMY_SIZ_Y);
	//影設定
	m_img_shadow = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Shadow"));
	m_img_shadow.SetSize(85, 22);
	m_img_shadow.SetCenter(-75, 22 / 2);

}

void CEnemy3::Update() {

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
	//上下浮遊
	m_a += HI_FLOAT;
	m_vec3D.y = sin(m_a) * 5;

	m_img.UpdateAnimation();
	CheckOverlap();
	m_rect_F.m_bottom = ENEMY_SIZ_Y - m_pos3D.y;
}

void CEnemy3::Nutral() {

}

void CEnemy3::Move() {
	CTask *p = CTaskManager::GetInstance()->GetTask(eID_Player);
	CObjectBase *PL = dynamic_cast<CObjectBase*>(p);
	m_cnt++;
	if (m_pos3D.x - m_scroll.x >= 50 && m_pos3D.x - m_scroll.x <= SCREEN_WIDTH - 50 - ENEMY_SIZ_X)
	m_pos3D += m_vec3D;
	//一定の場所まで来たら反転
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
		if (m_pleneVec.Length() >= 64)
			m_vec3D.x = m_pleneVec.GetNormalize().x * HI_SPEED;
		if (m_vec3D.x < 0)
			m_flipH = false;
		else
			m_flipH = true;
	}
	else if (60 <= m_cnt && m_cnt < 100) {
		m_vec3D = CVector3D(0, 0, 0);
	}
	else if (m_cnt == 100) {
		if (192 >= m_pleneVec.Length())
			m_state = eAttack;
		m_cnt = 0;
	}


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