#include "CPlayer.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

/*

����ҁ@�Z�ԁ@

�ҏW�@�@�͖�

*/

CPlayer::CPlayer() :CObjectBase(0, eU_Chara, eD_Chara) {
	m_vec3D = CVector3D(0, 0, 0);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_img.SetSize(256, 256);
	m_img.SetFlipH(m_flipH);
	m_punch1 = false;
	m_punch2 = false;
	m_jump = false;
}

CPlayer::~CPlayer() {
	NEW_SCENE(eTitle)
}

void CPlayer::Update() {
	m_move_length = false;
	m_move_side = false;
	m_squat = false;
	if (!m_punch1 && !m_punch2 && !m_jump) {
		m_anim = 0;
	}

	m_pos3D += m_vec3D;

	if (HOLD_X && !m_jump) {
		m_squat = true;
		m_anim = 3;
	}

	//�L�b�N
	if (m_punch1 && PUSH_R) {
		m_punch2 = true;
		m_punch1 = false;
		m_pos3D.x++;
	}

	if (!m_squat && !m_jump && !m_punch1 && !m_punch2) {
		//�ړ�
		if (HOLD_UP) {
			m_vec3D.z = -10;
			m_pos3D.x += (640 - m_pos3D.x) / 500;
			m_move_length = true;
			m_anim = 1;
		}
		if (HOLD_DOWN) {
			m_vec3D.z = 10;
			m_pos3D.x -= (640 - m_pos3D.x) / 500;
			m_move_length = true;
			m_anim = 1;
		}
		if (HOLD_RIGHT) {
			//����
			m_vec3D.x = Price_Up(m_vec3D.x, 10, 1.0f);
			m_move_side = true;
			m_flipH = false;
			m_anim = 1;
		}
		if (HOLD_LEFT) {
			//����
			m_vec3D.x = Price_Down(m_vec3D.x, -10, 1.0f);
			m_move_side = true;
			m_flipH = true;
			m_anim = 1;
		}
		//�p���`
		if (!m_punch2 && PUSH_R) {
			SOUND("SE_PUNCH_KARA")->Play();
			m_punch1 = true;
			m_anim = 4;
			m_pos3D.x++;
		}

	}
	//�W�����v
	if (PUSH_Z && !m_jump && !m_squat) {
		//�W�����v����O��y���W���擾
		m_y = m_pos3D.y;
		m_jump = true;
		m_anim = 2;
		m_vec3D.y = -32;
	}
	if (m_jump) {
		//�d��
		m_vec3D.y += 1.2;
		//���̈ʒu�ɖ߂�����
		if (m_pos3D.y > m_y) {
			m_vec3D.y = 10;
			//������
			m_pos3D.y = m_y;
			m_jump = false;
		}
	}

	//����(���E)
	if (!m_move_side) {
		if (!m_jump) {
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 1.0f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 1.0f);
		}
		else {
			//�W�����v���̌���
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 0.1f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 0.1f);
		}
	}
	//��~(�㉺)
	if (!m_move_length && !m_jump) {
		m_vec3D.y = 0;
		m_vec3D.z = 0;
	}
	
	//�A�j���[�V����
	m_img.ChangeAnimation(m_anim);
	if (m_anim == 4 && m_img.GetIndex() == 3) {
		if (m_punch2) {
			m_anim = 5;
			SOUND("SE_PUNCH_KARA")->Play();
		}else {
			m_punch1 = false;
		}
	}
	if (m_anim == 5 && m_img.GetIndex() == 2) {
		m_punch2 = false;
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
	if (PUSH_ENTER) {
		SetKill();
	}
}

void CPlayer::Draw(){
	m_img.SetFlipH(!m_flipH);
	m_img.SetPos(m_pos3D.x - m_scroll.x, m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	
}
