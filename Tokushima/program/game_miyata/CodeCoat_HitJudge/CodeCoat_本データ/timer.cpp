#include "timer.h"

void CTimeData::load(){
	LoadDivGraph("media\\img\\number_2.png", 22, 5, 5, 55, 55, Tnumimg);
};

void CTimeData::init(){
	m_timer.time = 50.00;
};

void CTimeData::move(CVector3D pos){
	
	//�J�E���g�_�E��
	m_timer.time -= 0.0166666;

	//�v���C���[�����[�ɍs���ƃ^�C�}�[��������Ă��܂��̂�h�����߂̏���
	//�Ȃ��A����movepos���g���Ӗ����Ȃ��̂ŏ����Ă��悢
	if (pos.getX() < 160){
		m_timer.movepos = CVector3D(160, pos.getY(),pos.getZ());
		m_timer.pos = m_timer.movepos;
	}
	else{
		m_timer.pos = pos;
	}

	//�^�C�}�[��0�ȉ��ɂȂ��Ă��܂����ꍇ��0�ɂ���
	if (m_timer.time < 0){
		m_timer.time = 0;
	}
}

void CTimeData::draw(){
	int offset1 = 0;
	char buf[100];
	float num;

	//�`��ɂ������āu10.00�v�̂悤�Ȑ����̏ꍇ�A�����_������̂�
	//�P�Q�R�S�T
	//����������
	//�P�O�D�O�O�ƂȂ�
	//num�̐��l��5�ƂȂ�
	//�����Ȃ��3�͐��l�ł͂Ȃ��̂ŏ��O���鏈�����s��

	num = sprintf_s(buf, 100, "%0.2f", m_timer.time);
	for (int i = 0; i < num; i++){
		if (i != 2 - offset1){	//10�b�ȉ��̏ꍇ�A��������̂�offset�Ń}�C�i�X������
			if (num == 4.0 && i == 0){

				//10�b�ȉ��̕\�L�A�Ⴆ�΁u09.00�b�v�̏ꍇ�A�ŏ��́u0�v��
				//�\�L����Ȃ��̂ł����ŕ`�悳����

				DrawGraph(m_timer.pos.getX() + (-160 + i * TIMER_SPACE),
					m_timer.pos.getY() - 60, Tnumimg[('0' - '&')], TRUE);
				offset1 = 1;
			}

			//�u.�v�i�����_�j�͏��O����̂ŏ����セ�̊Ԃ��󂢂Ă��܂�
			//���̂��߉��̂悤�ɏ����_�ȉ��̐����͋l�߂�悤�ɏ����𕪂������Ă������

			if (i > 2 - offset1){
				DrawGraph(m_timer.pos.getX() + (-175 + (i + offset1) * TIMER_SPACE),
					m_timer.pos.getY() - 60, Tnumimg[(buf[i] - '&')], TRUE);
			}
			else{
				DrawGraph(m_timer.pos.getX() + (-160 + (i + offset1) * TIMER_SPACE),
					m_timer.pos.getY() - 60, Tnumimg[(buf[i] - '&')], TRUE);
			}
		}
	}
}