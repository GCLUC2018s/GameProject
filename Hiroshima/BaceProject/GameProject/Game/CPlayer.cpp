#include "CPlayer.h"
#include "CBullet.h"
#include "CMap.h"
#include "../Global.h"
#include "CEffect.h"
#include "CClear.h"

CPlayer::CPlayer() : CBase(eTagUI) {
	m_img = CAnimImage(g_image[eImagePlayer], playerAnimData, 56, 56);
}
CPlayer::~CPlayer() {

}
void CPlayer::Draw() {
	m_img.SetPos(0, 0);
	m_img.SetRect(0, 0, 56, 56);
	m_img.SetSize(56, 56);
	m_img.Draw();
}
void CPlayer::Update() {
	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}
/*
CPlayer::CPlayer() : CBase(eTagPlayer) {
	m_img = CAnimImage(g_image[eImagePlayer], playerAnimData, 256, 256);
	m_pos = CVector2D(0, 504);
	m_img.SetRect(0, 0, 256, 256);
	m_img.SetSize(256, 256);
	m_rect = CRect(80, 90, 160, 230);
	m_body = MASK_PLAYER;
	m_ground = false;
	m_state = eNutral;
}
void CPlayer::Update() {
	m_old_pos = m_pos;
	switch (m_state) 
	{
	case eNutral:
		Nutral();
		break;
	case eAttack:
		Attack();
		break;
	}
	if (m_vec.y > GRAVITY) {
		m_ground = false;
		m_img.ChangeAnimation(3);
	}

	m_pos.y += m_vec.y;
	m_vec.y += GRAVITY;
	
	m_img.UpdateAnimation();

	int x, y;
	if (WallCheck(&x) != 0) {
		m_pos.x = x;
	}
	if (FloorCheck(&y) != 0) {
		m_pos.y = y;
		m_vec.y = 0;
		m_ground = true;
		m_jump_cnt = 0;
	}

	//スクロール
	m_scroll.x = m_pos.x - 500;
	if (m_scroll.x < 0)m_scroll.x = 0;
	if (m_scroll.x > MAP_WIDTH * MAP_TIP_SIZE - SCREEN_WIDTH)
		m_scroll.x = MAP_WIDTH * MAP_TIP_SIZE - SCREEN_WIDTH;
}
void CPlayer::Nutral() {
	bool is_move = false;

	//弾 上
	if (CInput::GetState(0, CInput::eHold, CInput::eUp) &&
		CInput::GetState(0, CInput::ePush, CInput::eButton1)) {
		SOUND("SE_GUN")->Play();
		g_list.push_back(new CBullet(0, m_pos + CVector2D(128, 128), CVector2D(0, -8)));
		g_list.push_back(new CEffectShotHit(m_pos + CVector2D(128, 128)));
	}

	//弾 右
	else if (CInput::GetState(0, CInput::ePush, CInput::eButton1) && m_flipH == false) {
		SOUND("SE_GUN")->Play();
		g_list.push_back(new CBullet(0, m_pos + CVector2D(128, 128), CVector2D(8, 0)));
		g_list.push_back(new CEffectShotHit(m_pos + CVector2D(128, 128)));
	}
	//弾 左
	else if (CInput::GetState(0, CInput::ePush, CInput::eButton1) && m_flipH == true) {
		SOUND("SE_GUN")->Play();
		g_list.push_back(new CBullet(0, m_pos + CVector2D(128, 128), CVector2D(-8, 0)));
		g_list.push_back(new CEffectShotHit(m_pos + CVector2D(128, 128)));
	}

	//右移動
	if (CInput::GetState(0, CInput::eHold, CInput::eRight)) {
		m_pos.x += 6;
		is_move = true;
		m_flipH = false;
	}

	//左移動
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_pos.x -= 6;
		is_move = true;
		m_flipH = true;
	}

	//ジャンプ
	if (m_jump_cnt < 2 && CInput::GetState(0, CInput::ePush, CInput::eButton2)) {
		m_vec.y = -16;
		m_ground = false;
		m_jump_cnt++;
	}

	//斬撃
	if (CInput::GetState(0, CInput::ePush, CInput::eButton3)) {
		SOUND("SE_SLASH")->Play();
			m_state = eAttack;
			m_slash = false;
		}
	if (m_ground) {
		if (is_move) {
			m_img.ChangeAnimation(1);
		}
		else {
			m_img.ChangeAnimation(0);
		}
	}
	else {
		if (m_vec.y < 0) {
			m_img.ChangeAnimation(eAnimJumpUp, false);
		}
		else {
			m_img.ChangeAnimation(eAnimJumpDown, false);
		}
	}
}
void CPlayer::Attack() {
	m_img.ChangeAnimation(eAnimAttack01, false);
	if (m_slash == false) {
		if (m_img.GetIndex() == 3) {
			if (m_flipH) {
				g_list.push_back(new CEffectSlash(m_pos + CVector2D(90, 64), m_flipH));
			}
			else {
				g_list.push_back(new CEffectSlash(m_pos + CVector2D(90, 64), m_flipH));
			}
		m_slash = true;
		}
	}
	if (m_img.CheckAnimationEnd()) {
		m_state = eNutral;
	}
}
void CPlayer::HitCallback(CBase* b) {
	if (b->GetTag() == eTagBullet) {
		m_active = false;
	}else 
	if(b->GetTag() == eTagItem){
		g_game_data.score += 100;
	}
}*/