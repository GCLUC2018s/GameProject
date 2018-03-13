#include "CPlayer.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

/*

制作者　六車　

編集　　河野

*/

CPlayer::CPlayer() :CObjectBase(0, eU_Chara, eD_Chara) {
	m_vec3D = CVector3D(0, 0, 0);
	m_pos3D = CVector3D(0, 0, 0);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_img.SetSize(256, 256);
	m_img.SetFlipH(m_flipH);
	m_punch1 = false;
	m_punch2 = false;
	m_jump = false;
	m_anim = 0;
	m_state = eNutral;
	m_cnt = 0;
}

CPlayer::~CPlayer() {
	NEW_SCENE(eTitle)
}

void CPlayer::Update() {

	m_pos3D += m_vec3D;

	if (m_pos3D.z > 0) {
		m_pos3D.z = 0;
	}
	if (m_pos3D.z < -430) {
		m_pos3D.z = -430;
	}
	if (m_pos3D.x < 0) {
		m_pos3D.x = 0;
	}

	m_move_length = false;
	m_move_side = false;
	m_squat = false;

	switch (m_state) {
	case eNutral:
		Nutral();
		break;
	case eAttack:
		Attack();
		break;
	}

	//減速(左右)
	if (!m_move_side) {
		if (!m_jump) {
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 1.0f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 1.0f);
		}else {
			//ジャンプ中の減速
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 0.1f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 0.1f);
		}
		m_cnt = 0;
	}
	//停止(上下)
	if (!m_move_length && !m_jump) {
		m_vec3D.y = 0;
		m_vec3D.z = 0;
	}
	
	//アニメーション
	m_img.ChangeAnimation(m_anim);
	if (m_anim == 4 && m_img.GetIndex() == 3) {
		if (m_punch2) {
			m_anim = 5;
			SOUND("SE_PUNCH_KARA")->Play();
		}else {
			m_state = eNutral;
		}
	}
	if (m_anim == 5 && m_img.GetIndex() == 2) {
		m_state = eNutral;
	}


	if (m_squat&&m_img.GetIndex() == 1) {
	}else if(m_jump && m_img.GetIndex() == 0){
		if (m_vec3D.y > 0) {
			m_img.UpdateAnimation();
		}
	}else if (m_jump && m_img.GetIndex() == 1) {
	}else {
		m_img.UpdateAnimation();

	}
	if (m_pos3D.x > SCREEN_WIDTH / 2 && m_pos3D.x < 4000 - SCREEN_WIDTH / 2) {
		m_scroll.x = m_pos3D.x - SCREEN_WIDTH / 2;
	}
	if (450 + m_pos3D.y + m_pos3D.z / 2 < 120 && 450 + m_pos3D.y + m_pos3D.z / 2 > -100) {
		m_scroll.y = 450 + m_pos3D.y + m_pos3D.z / 2 - 120;
	}
}

void CPlayer::Nutral() {

	m_punch1 = false;
	m_punch2 = false;
	if (!m_jump) {
		m_anim = 0;
	}

	//しゃがみ
	if (HOLD_X && !m_jump) {
		m_squat = true;
		m_anim = 3;
	}
	//移動
	if (!m_squat) {
		if (!m_jump && HOLD_UP) {
			m_vec3D.z = -10;
			m_variation += (640 - (m_pos3D.x + m_variation - m_scroll.x)) / 500;
			m_move_length = true;
			m_anim = 1;
			m_cnt++;
		}
		if (!m_jump && HOLD_DOWN) {
			m_vec3D.z = 10;
			m_variation += ((m_pos3D.x + m_variation - m_scroll.x) - 640) / 500;
			m_move_length = true;
			m_anim = 1;
			m_cnt++;
		}
		if (HOLD_RIGHT) {
			//加速
			m_vec3D.x = Price_Up(m_vec3D.x, 10, 1.0f);
			m_move_side = true;
			m_flipH = false;
			m_anim = 1;
			m_cnt++;
		}
		if (HOLD_LEFT) {
			//加速
			m_vec3D.x = Price_Down(m_vec3D.x, -10, 1.0f);
			m_move_side = true;
			m_flipH = true;
			m_anim = 1;
			m_cnt++;
		}
	}
	//ジャンプ
	if (PUSH_Z && !m_jump && !m_squat) {
		m_vec3D.z = 0;
		m_jump = true;
		m_anim = 2;
		m_vec3D.y = -32;
	}
	if (m_jump) {
		//重力
		m_anim = 2;
		m_vec3D.y += 1.2;
		//元の位置に戻ったら
		if (m_pos3D.y > 0) {
			m_vec3D.y = 10;
			//微調整
			m_pos3D.y = 0;
			m_jump = false;
		}
	}
	//足音
	if (m_cnt % 30 == 0 && m_cnt) {
		m_dash = Utility::Rand(0, 2);
		switch (m_dash) {
		case 0:
			SOUND("SE_DASH1")->Play(true);
			break;
		case 1:
			SOUND("SE_DASH2")->Play(true);
			break;
		case 2:
			SOUND("SE_DASH3")->Play(true);
			break;
		}
	}

	if (!m_jump && PUSH_R) {
		SOUND("SE_PUNCH_KARA")->Play();
		m_punch1 = true;
		m_anim = 4;
		m_pos3D.x++;
		m_state = eAttack;
	}
}

void CPlayer::Attack(){
	//キック
	if (PUSH_R) {
		m_punch2 = true;
		m_punch1 = false;
		m_pos3D.x++;
	}
	if (PUSH_ENTER) {
		SetKill();
	}
}

void CPlayer::Draw(){
	m_img.SetFlipH(!m_flipH);
	m_img.SetPos(m_pos3D.x + m_variation - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
}

