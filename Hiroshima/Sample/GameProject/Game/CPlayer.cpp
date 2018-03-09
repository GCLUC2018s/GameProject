#include "CPlayer.h"

/*

����ҁ@�Z�ԁ@

*/


CPlayer::CPlayer():CBase(eTagPlayer){
	m_vec = CVector2D(0, 0);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_img.SetSize(256,256);
	m_img.SetFlipH(m_flipH);
	m_punch = false;
	m_jump = false;
}

CPlayer::~CPlayer(){
}

void CPlayer::Update() {
	m_move_length = false;
	m_move_side = false;
	m_squat = false;
	m_punch = false;
	m_anim = 0;

	m_pos += m_vec;

	if (HOLD_X) {
		m_squat = true;
		m_anim = 3;
	}
	if (!m_squat && !m_jump) {
		//�ړ�
		if (HOLD_UP) {
			m_vec.y = -10;
			m_move_length = true;
			m_anim = 1;
		}
		if (HOLD_DOWN) {
			m_vec.y = 10;
			m_move_length = true;
			m_anim = 1;
		}
		if (HOLD_RIGHT) {
			//����
			m_vec.x = Price_Up(m_vec.x, 10, 1.0f);
			m_move_side = true;
			m_flipH = false;
			m_anim = 1;
		}
		if (HOLD_LEFT) {
			//����
			m_vec.x = Price_Down(m_vec.x, -10, 1.0f);
			m_move_side = true;
			m_flipH = true;
			m_anim = 1;
		}
		//�p���`
		if (PUSH_C) {
			m_punch = true;
			m_anim = 4;
			m_pos.x++;

		}
	}
	//�W�����v
	if (PUSH_Z && !m_jump) {
		//�W�����v����O��y���W���擾
		y = m_pos.y;
		m_jump = true;
		m_anim = 2;
		m_vec.y = -32;
	}
	if (m_jump) {
		//�d��
		m_vec.y += 1.2;
		//���̈ʒu�ɖ߂�����
		if (m_pos.y > y) {
			m_vec.y = 10;
			//������
			m_pos.y = y;
			m_jump = false;
		}
	}

	//����(���E)
	if (!m_move_side) {
		if (!m_jump) {
			if (m_flipH)
				m_vec.x = Price_Up(m_vec.x, 0, 1.0f);
			else
				m_vec.x = Price_Down(m_vec.x, 0, 1.0f);
		}else{
			//�W�����v���̌���
			if (m_flipH)
				m_vec.x = Price_Up(m_vec.x, 0, 0.3f);
			else
				m_vec.x = Price_Down(m_vec.x, 0, 0.3f);
		}
	}
	//��~(�㉺)
	if (!m_move_length && !m_jump) {
		m_vec.y = 0;
	}
	
	//�A�j���[�V����
	m_img.ChangeAnimation(m_anim);
	if (m_anim == 4 && m_img.GetIndex() == 3) {
		m_anim = 0;
	}
	if (m_squat&&m_img.GetCount() == 1) {

	}
	else {
		m_img.UpdateAnimation();
	}
}

void CPlayer::Draw(){
	m_img.SetFlipH(!m_flipH);
	m_img.SetPos(m_pos);
	m_img.Draw();
}
