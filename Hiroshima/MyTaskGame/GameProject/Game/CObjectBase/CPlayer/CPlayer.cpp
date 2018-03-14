#include "CPlayer.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

/*

制作者　六車　

編集　　河野

*/

CPlayer::CPlayer() :CObjectBase(eID_Player, eU_Chara, eD_Chara) {
	m_vec3D = CVector3D(0, 0, 0);
	m_pos3D = CVector3D(0, 0, 0);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_img.SetSize(256, 256);
	m_img.SetFlipH(m_flipH);
	m_rect = CRect(129, 58, 353, 489);
	m_punch1 = false;
	m_punch2 = false;
	m_jump = false;
	m_hp = 10;
	m_anim = eAnimIdol;
	m_state = eNutral;
	m_cnt = 0;
	m_die = false;
	damage_vec = CVector2D(5, -10);
}

CPlayer::~CPlayer() {
	NEW_SCENE(eTitle)
}

void CPlayer::Update() {
	//移動処理
	m_pos3D += m_vec3D;

	//道の幅分移動
	if (m_pos3D.z > 0) {
		m_pos3D.z = 0;
	}
	if (m_pos3D.z < -430) {
		m_pos3D.z = -430;
	}
	if (m_pos3D.x < 0) {
		m_pos3D.x = 0;
	}

	//移動系の変数初期化
	m_move_length = false;
	m_move_side = false;
	m_squat = false;

	//処理分岐
	switch (m_state) {
	case eNutral:
		Nutral();
		break;
	case eAttack:
		Attack();
		break;
	case eFall:
		Fall();
		break;
	}

	//左右移動終了後の減速処理
	if (!m_move_side && !m_die) {
		if (!m_jump) {
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 1.0f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 1.0f);
		}else {
			//ジャンプ中の減速処理
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 0.1f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 0.1f);
		}
	}
	//上下移動終了後の停止処理
	if (!m_move_length && !m_jump && !m_die) {
		m_vec3D.y = 0;
		m_vec3D.z = 0;
	}

	if (m_hp == 0 && !m_die) {
		m_state = eFall;
		m_vec3D.x = damage_vec.x;
		m_vec3D.y = damage_vec.y;
		m_die = true;
		m_anim = 6;
	}
	
	//アニメーション
	m_img.ChangeAnimation(m_anim);
	if (m_anim == eAnimPunch && m_img.GetIndex() == 3) {
		if (m_punch2) {
			//パンチしてたら
			m_anim = eAnimKick;
			SOUND("SE_PUNCH_KARA")->Play();
		}else {
			//してない
			m_state = eNutral;
		}
	}
	if (m_anim == eAnimKick && m_img.GetIndex() == 2) {
		m_state = eNutral;
	}


	if (m_squat&&m_img.GetIndex() == 1) {
	}//ここからジャンプモーション
	else if(m_jump && m_img.GetIndex() == 0){
		if (m_vec3D.y > -10) {
			m_img.UpdateAnimation();
		}
	}else if (m_jump && m_img.GetIndex() == 1) {
		if (m_vec3D.y > 0) {
			m_img.UpdateAnimation();
		}
	}else if (m_jump && m_img.GetIndex() == 2) {
	//ここまで
	}else {
		m_img.UpdateAnimation();

	}
	if (m_pos3D.x > SCREEN_WIDTH / 2 && m_pos3D.x < 4000 - SCREEN_WIDTH / 2) {
		m_scroll.x = m_pos3D.x - SCREEN_WIDTH / 2;
	}
	if (450 + m_pos3D.y + m_pos3D.z / 2 < 80 && 450 + m_pos3D.y + m_pos3D.z / 2 > -100) {
		m_scroll.y = 450 + m_pos3D.y + m_pos3D.z / 2 - 80;
	}
	if (m_pos3D.y == 715 + 512) {
		m_scroll.y = SCREEN_HEIGHT/2;
	}
}

void CPlayer::Nutral() {

	m_punch1 = false;
	m_punch2 = false;
	if (!m_jump) {
		m_anim = eAnimIdol;
	}

	//しゃがみ
	if (HOLD_X && !m_jump) {
		m_squat = true;
		m_anim = eAnimSquat;
	}
	//移動
	if (!m_squat) {
		if (!m_jump && HOLD_UP) {
			m_vec3D.z = -10;
			m_variation += (SCREEN_WIDTH / 2 - (m_pos3D.x + m_variation - m_scroll.x)) / 500;
			m_move_length = true;
			m_anim = eAnimDash;
			m_cnt++;
		}
		if (!m_jump && HOLD_DOWN) {
			m_vec3D.z = 10;
			m_variation += ((m_pos3D.x + m_variation - m_scroll.x) - SCREEN_WIDTH / 2) / 500;
			m_move_length = true;
			m_anim = eAnimDash;
			m_cnt++;
		}
		if (HOLD_RIGHT) {
			//加速
			m_vec3D.x = Price_Up(m_vec3D.x, 10, 1.0f);
			m_move_side = true;
			m_flipH = false;
			m_anim = eAnimDash;
			m_cnt++;
		}
		if (HOLD_LEFT) {
			//加速
			m_vec3D.x = Price_Down(m_vec3D.x, -10, 1.0f);
			m_move_side = true;
			m_flipH = true;
			m_anim = eAnimDash;
			m_cnt++;
		}
	}
	//ジャンプ
	if (PUSH_Z && !m_jump && !m_squat) {
		SOUND("SE_JUMP")->Play(false);
		m_vec3D.z = 0;
		m_jump = true;
		m_anim = eAnimJamp;
		m_vec3D.y = -35;
	}
	if (m_jump) {
		//重力
		m_anim = eAnimJamp;
		m_vec3D.y += GRAVITY;
		//元の位置に戻ったら
		if (m_pos3D.y > 0) {
			//微調整
			m_pos3D.y = 0;
			m_jump = false;
			SOUND("SE_LANDING")->Play(false);
		}
	}
	//足音-
	if (m_cnt % 15 == 0 && m_cnt && m_jump == false) {
		m_dash = Utility::Rand(0, 2);
		switch (m_dash) {
		case 0:
			SOUND("SE_DASH1")->Play(false);
			break;
		case 1:
			SOUND("SE_DASH2")->Play(false);
			break;
		case 2:
			SOUND("SE_DASH3")->Play(false);
			break;
		}
	}

	//ジャンプしてなくて、パンチしたら
	if (!m_jump && PUSH_R) {
		SOUND("SE_PUNCH_KARA")->Play();
		m_punch1 = true;
		m_anim = eAnimPunch;
		m_state = eAttack;
	}
	if (PUSH_V) {
		m_hp = 0;
	}
}

void CPlayer::Attack(){
	//キック
	if (PUSH_R) {
		m_punch2 = true;
		m_punch1 = false;
	}
	if (PUSH_ENTER) {
		SetKill();
	}
}

void CPlayer::Fall() {
	m_vec3D = Die(m_vec3D); 
	m_vec3D.x = Price_Down(m_vec3D.x, 0, 0.1f);
}

CVector3D CPlayer::Die(CVector3D vec) {
	m_vec3D.z = 0;
	m_vec3D.y += GRAVITY_DIE;
	if (m_pos3D.y > 0) {
		damage_vec.y *= REPULSION;
		m_vec3D.y = damage_vec.y;
	}
	return m_vec3D;
}

void CPlayer::Draw(){
	m_img.SetFlipH(!m_flipH);
	m_img.SetPos(m_pos3D.x + m_variation - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
}

