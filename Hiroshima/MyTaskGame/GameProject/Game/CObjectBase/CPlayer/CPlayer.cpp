#include "CPlayer.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

/*

����ҁ@�Z�ԁ@

�ҏW�@�@�͖�

*/

CPlayer::CPlayer() :CObjectBase(eID_Player, eU_Player, eD_Chara) {
	m_vec3D = CVector3D(0, 0, 0);
	m_pos3D = CVector3D(0, 0, 0);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_img.SetSize(256, 256);
	m_img.SetFlipH(m_flipH);
	m_rect = CRect(129, 58, 353, 489);
	m_punch1 = false;
	m_punch2 = false;
	m_kick = false;
	m_jump = false;
	m_hp = 10;
	m_anim = eAnimIdol;
	m_state = eNutral;
	m_cnt = 0;
	m_die = false;
	damage_vec = CVector2D(5, -10);
	m_img.ChangeAnimation(m_anim);
	m_img.UpdateAnimation();
}

CPlayer::~CPlayer() {
	NEW_SCENE(eTitle)
}

void CPlayer::Update() {
	//�ړ�����
	m_pos3D += m_vec3D;

	//���̕����ړ�
	if (m_pos3D.z > 0) {
		m_pos3D.z = 0;
	}
	if (m_pos3D.z < -430) {
		m_pos3D.z = -430;
	}
	if (m_pos3D.x < 0) {
		m_pos3D.x = 0;
	}

	//�ړ��n�̕ϐ�������
	m_move_length = false;
	m_move_side = false;
	m_squat = false;

	//��������
	switch (m_state) {
	case eNutral:
		Nutral();
		break;
	case eAttack:
		Attack();
		break;
	case eDamage:
		Damage();
		break;
	case eFall:
		Fall();
		break;
	}

	//���E�ړ��I����̌�������
	if (!m_move_side && !m_die) {
		if (!m_jump) {
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 1.0f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 1.0f);
		}else {
			//�W�����v���̌�������
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 0.1f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 0.1f);
		}
	}
	//�㉺�ړ��I����̒�~����
	if (!m_move_length && !m_jump && !m_die) {
		m_vec3D.y = 0;
		m_vec3D.z = 0;
	}

	if (m_hp == 0 && !m_die) {
		m_state = eFall;
		m_die = 1 ;
		m_cnt = 0;
	}
	
	//�A�j���[�V����
	m_img.ChangeAnimation(m_anim);
	//�p���`������
	if (m_anim == eAnimPunch && m_img.GetIndex() == 4) {
		if (m_punch2) {
			//�p���`���Ă���
			m_img.UpdateAnimation();
			m_punch1 = false;
			SOUND("SE_PUNCH_KARA")->Play();
		}else {
			//���ĂȂ�
			m_state = eNutral;
		}
	}
	//�L�b�N����
	if (m_anim == eAnimPunch && m_img.GetIndex() == 7) {
		if (m_kick) {
			//�p���`���Ă���
			m_anim = eAnimKick;
			m_punch2 = false;
			SOUND("SE_PUNCH_KARA")->Play();
		}
		else {
			//���ĂȂ�
			m_state = eNutral;
		}
	}
	if (m_anim == eAnimKick && m_img.GetIndex() == 3) {
		m_state = eNutral;
	}

	if (m_anim == eAnimBill && m_img.GetIndex() == 2) {
		m_state = eNutral;
	}

	if (m_squat&&m_img.GetIndex() == 1) {
	}//��������W�����v���[�V����
	else if(m_jump && m_img.GetIndex() == 0){
		if (m_vec3D.y > -10) {
			m_img.UpdateAnimation();
		}
	}else if (m_jump && m_img.GetIndex() == 1) {
		if (m_vec3D.y > 0) {
			m_img.UpdateAnimation();
		}
	}else if (m_jump && m_img.GetIndex() == 2) {
	//��������_���[�W���[�V����
	}else if(m_anim == eAnimFall && m_img.GetIndex() == 3) {
		m_die = 0;
	}else if (m_anim == eAnimFall && m_img.GetIndex() == 1) {
		if(m_die >= 2)
			m_img.UpdateAnimation();
	}else {
		m_img.UpdateAnimation();

	}
	if (m_pos3D.x > SCREEN_WIDTH / 2 && m_pos3D.x - SCREEN_WIDTH / 2) {
		m_scroll.x = m_pos3D.x - SCREEN_WIDTH / 2;
	}
	if (450 + m_pos3D.y + m_pos3D.z / 2 < 80 && 450 + m_pos3D.y + m_pos3D.z / 2 > -100) {
		m_scroll.y = 450 + m_pos3D.y + m_pos3D.z / 2 - 80;
		if (m_pos3D.y == 715 + 512) {
			m_scroll.y = SCREEN_HEIGHT;
		}
	}
	CheckOverlap();
}

void CPlayer::Nutral() {

	m_punch1 = false;
	m_punch2 = false;
	m_kick = false;
	if (!m_jump) {
		m_anim = eAnimIdol;
	}

	//���Ⴊ��
	if (HOLD_X && !m_jump) {
		m_squat = true;
		m_anim = eAnimSquat;
	}
	//�ړ�
	if (!m_squat) {
		if (!m_jump && HOLD_UP) {
			m_vec3D.z = -10; 
			if (m_pos3D.z != 0 && m_pos3D.z != -430)
			m_variation += (SCREEN_WIDTH / 2 - (m_pos3D.x + m_variation - m_scroll.x)) / 500;
			m_move_length = true;
			m_anim = eAnimDash;
			m_cnt++;
		}
		if (!m_jump && HOLD_DOWN) {
			m_vec3D.z = 10;
			if (m_pos3D.z != 0 && m_pos3D.z != -430)
			m_variation += ((m_pos3D.x + m_variation - m_scroll.x) - SCREEN_WIDTH / 2) / 500;
			m_move_length = true;
			m_anim = eAnimDash;
			m_cnt++;
		}
		if (HOLD_RIGHT) {
			//����
			m_vec3D.x = Price_Up(m_vec3D.x, 10, 1.0f);
			m_move_side = true;
			m_flipH = false;
			m_anim = eAnimDash;
			m_cnt++;
		}
		if (HOLD_LEFT) {
			//����
			m_vec3D.x = Price_Down(m_vec3D.x, -10, 1.0f);
			m_move_side = true;
			m_flipH = true;
			m_anim = eAnimDash;
			m_cnt++;
		}
	}
	//�W�����v
	if (PUSH_Z && !m_jump && !m_squat) {
		SOUND("SE_JUMP")->Play(false);
		m_vec3D.z = 0;
		m_jump = true;
		m_anim = eAnimJamp;
		m_vec3D.y = -35;
	}
	if (m_jump) {
		//�d��
		m_anim = eAnimJamp;
		m_vec3D.y += GRAVITY;
		//���̈ʒu�ɖ߂�����
		if (m_pos3D.y > 0) {
			//������
			m_pos3D.y = 0;
			m_jump = false;
			SOUND("SE_LANDING")->Play(false);
		}
	}
	//����
	if (m_cnt % 15 == 0 && !m_cnt && m_cnt && m_jump == false) {
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

	//�W�����v���ĂȂ��āA�p���`������
	if (!m_jump && PUSH_R) {
		SOUND("SE_PUNCH_KARA")->Play();
		m_punch1 = true;
		m_anim = eAnimPunch;
		m_state = eAttack;
	}
	if (PUSH_V) {
		if (m_jump) {
			m_state = eFall;
			m_die = 1;
			m_jump = false;
		}else {
			m_state = eDamage;
		}
		m_vec3D.y = 0;
		m_hp -= 2;
		m_cnt = 0;
	}
	if (!m_jump && PUSH_E) {
		m_anim = eAnimBill;
		m_state = eAttack;
	}
}

void CPlayer::Bill() {
}

void CPlayer::Attack(){
	//�L�b�N
	if (m_punch1 && PUSH_R) {
		m_punch2 = true;
	}
	if (!m_punch1 && PUSH_R) {
		m_kick = true;
	}
	if (PUSH_ENTER) {
		SetKill();
	}
}

void CPlayer::Damage() {
	m_anim = eAnimDamage;
	m_cnt++;
	if (m_cnt == 39) {
		m_anim = 0;
		m_state = eNutral;
	}
}

void CPlayer::Fall() {
	m_cnt++;
	if (m_cnt == 20) {
		if(m_flipH)
			m_vec3D.x = damage_vec.x;
		else
			m_vec3D.x = -damage_vec.x;
		m_vec3D.y = damage_vec.y;
	}
	if(m_cnt >= 20)
		if(m_die != 4)
			m_vec3D = Die(m_vec3D); 
	m_anim = eAnimFall;
	//x����
	if(m_flipH)
		m_vec3D.x = Price_Down(m_vec3D.x, 0, 0.05f);
	else
		m_vec3D.x = Price_Up(m_vec3D.x, 0, 0.05f);
	//�N���オ��
	if (!m_die) {
		//�t���O������
		m_die = 0;
		m_state = eNutral;
		//���̑����X
		damage_vec.y = -10;
		m_cnt = 0;
		m_anim = eAnimIdol;
		if(!m_hp)
		m_hp = 10;
	}
}
//�������
CVector3D CPlayer::Die(CVector3D vec) {
	m_vec3D.z = 0;
	m_vec3D.y += GRAVITY_DIE;
	if (m_pos3D.y > 0) {
		if (m_die == 3) {
			m_vec3D.y = 0;
			m_pos3D.y = 0;
		}else {
			m_pos3D.y = 0;
			damage_vec.y *= REPULSION;
			m_vec3D.y = damage_vec.y;
		}
			m_die++;
	}
	return m_vec3D;
}

void CPlayer::Draw(){
	m_img.SetFlipH(!m_flipH);
	m_img.SetPos(m_pos3D.x + m_variation - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
}

