
#include "CEnemy4.h"
/*

製作者　青木

*/
//かまいたち
CEnemy4::CEnemy4(CVector3D *pos) :CObjectBase(0, eU_Chara, eD_Chara) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy4"));
	m_img.SetSize(213, 256);
	m_pos3D = *pos;
	m_hp = KAMAITACHI_HP;
	m_at = KAMAITACHI_AT;
	m_state = eIdol;
	m_cnt = 0;
	m_move_cnt = 0;
	m_stop = false;
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
	}

	//此処で待機時間を調整可能
	if (m_cnt > 130) {
		m_state = eMove;
		m_cnt = 0;
	}

	m_img.UpdateAnimation();
}

void CEnemy4::Neutral() {
	//上下浮遊
	m_vec3D.x = 0;
	m_stop = false;
	m_pos3D += m_vec3D;
	m_a += 0.1f;
	m_vec3D.y = sin(m_a) * 5;
	m_cnt++;
	m_img.ChangeAnimation(0);
}

void CEnemy4::Attack() {
	m_img.ChangeAnimation(2);
	if (m_img.GetIndex() == 2) {
		m_state = eIdol;
	}
}

void CEnemy4::Move() {
	m_vec3D.y = 0;

	if (m_pos3D.x < 0) {
		m_flipH = true;
	}

	if (m_pos3D.x > 4000 - 213) {
		m_flipH = false;
	}

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
		//m_state = eIdol;
	}

	if (m_move_cnt > 20) {
		m_stop = true;
		m_move_cnt = 0;
	}
	m_img.ChangeAnimation(1);
}