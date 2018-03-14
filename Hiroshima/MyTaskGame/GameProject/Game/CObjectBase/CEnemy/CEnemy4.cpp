#include "CEnemy4.h"
/*

製作者　青木

*/

//かまいたち
CEnemy4::CEnemy4(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy4"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_pos3D = *pos;
	m_hp = KAMAITACHI_HP;
	m_at = KAMAITACHI_AT;
	m_rect = CRect(0, 0, ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_rect_F = CRect(0, 0, ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_state = eIdol;
	m_cnt = 0;
	m_move_cnt = 0;
	m_stop = false;
	m_damage = false;
	m_end_flag = false;
}

CEnemy4::~CEnemy4() {
}

void CEnemy4::Update() {

	switch (m_state)
	{
		//待機
	case eIdol:
		Neutral();
		break;
		//移動
	case eMove:	
		Move();
		break;
		//攻撃
	case eAttack:
		Attack();
		break;
	case eKnockBack:
		KnockBack();
		break;
	case eFall:
		Fall();
		break;
	}

	//此処で待機時間を調整可能
	if (m_cnt > KAMAITACHI_MOVE_TIME) {
		m_state = eMove;
		m_cnt = 0;
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

void CEnemy4::Neutral() {
	//上下浮遊
	m_vec3D.x = 0;
	m_stop = false;
	m_pos3D += m_vec3D;
	m_a += KAMAITACHI_FLOAT;
	m_vec3D.y = sin(m_a) * 5;
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

	//一定の場所まで来たら反転
	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > SCREEN_WIDTH - ENEMY_SIZ_X) {
		m_flipH = false;
	}
	//向いている方向に進む
	if (m_flipH) {
		m_vec3D.x = KAMAITACHI_SPEED;
	}
	else {
		m_vec3D.x = -KAMAITACHI_SPEED;
	}


	if (!m_stop) {
		m_pos3D += m_vec3D;
		m_move_cnt++;
	}
	else {
		m_state = eAttack;
	}

	if (m_move_cnt > KAMAITACHI_STOP_TIME) {
		m_stop = true;
		m_move_cnt = 0;
	}
	m_img.ChangeAnimation(eAnimKamaMove);
}

void CEnemy4::KnockBack() {
	m_img.ChangeAnimation(eAnimKamaKnockBack);
	Damage();
	m_move_cnt = 0;
	if (m_img.GetIndex() == 1) {
		m_state = eIdol;
	}
}

void CEnemy4::Fall() {
	m_img.ChangeAnimation(eAnimKamaFall);
	m_img.SetColor(m_color.r, m_color.g, m_color.b, m_color.a);
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

void CEnemy4::Damage() {
	m_vec3D.y = 0;
	m_pos3D += m_vec3D;
	if (m_damage) {
		m_hp--;
		m_damage = false;
		if (m_flipH) {
			m_vec3D.x = -KAMAITACHI_KNOCKBACK_SPEED;
		}
		else {
			m_vec3D.x = KAMAITACHI_KNOCKBACK_SPEED;
		}
	}
	
}