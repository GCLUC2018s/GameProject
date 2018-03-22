#include "ui.h"
#include "player_manager.h"
#include "map_manager.h"
#include "enemy_manager.h"
#include "npc_manager.h"
#include "ui_manager.h"

Ui::Ui() :
m_timer_pos(0, 0, 0),
m_arrow_pos(0,0,0),
m_maparrow_pos(0,0,0),
m_totalscore(0),
m_timelimit(0),
m_score_magnification(0)
{
}

Ui::Ui(CVector3D p_pos) :CTask(0,eUDP_Ui,eDWP_Ui),
m_score_img(LoadGraph("media\\img\\score2.png" ,TRUE)),
m_map_img(LoadGraph("media\\img\\map.png", TRUE)),
m_scorearrow_img(LoadGraph("media\\img\\power-arrow1.png", TRUE)),
m_combotxt_img(LoadGraph("media\\img\\combo.png",TRUE)),
m_timer_pos(p_pos),
m_arrow_pos(p_pos),
m_maparrow_pos(MAP_P_INIT_X,MAP_P_INIT_Y,0),
m_totalscore(0),
m_timelimit(99.9f),
m_score_magnification(1),
m_comb_flag(false),
m_c_angle(COMB_MOVE_X),
m_past_comb(0),
m_ndm_magnification(0)
{
	LoadDivGraph("media\\img\\time-number.png",12,6,2,70,70,m_timer_img);
	LoadDivGraph("media\\img\\score_number2.png",12,10,2,40,40,m_scorenum_img);
	LoadDivGraph("media\\img\\item-frame.png", 4, 2, 2, 100, 100, m_item_img);
	m_scoregage_img[0] = LoadGraph("media\\img\\power-gage0.png");
	m_scoregage_img[1] = LoadGraph("media\\img\\power-gage1.png");
	m_totalrun_txt_img[0] = LoadGraph("media\\img\\bonus.png");
	m_totalrun_txt_img[1] = LoadGraph("media\\img\\fold.png");
	CUiManager::GetInstance()->Init(this);
}

Ui::~Ui()
{
}

void Ui::Update(){
	CNpc *_npc = CNpcManager::GetInstance()->GetNpcAdress();
	if (!_npc->getShopFlag()){
		const float offset = 50;
		CVector3D p_pos = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos();
		float _totalmove = CMapManager::GetInstance()->GetMapAdress()->getTotalmovement();
		float _move = 0;
		//�e��		�ǉ�
		for (int i = 0; i < 2; i++){
			m_ammo[i] = CPlayerManager::GetInstance()->GetPlayerAdress()->getEquipment(i)->m_useful;
			if (CPlayerManager::GetInstance()->GetPlayerAdress()->getEquipment(i)->m_name == 0)
				m_ammo[i] = 0;
		}

		//�^�C�}�[���v���C���[�ɒǏ]�����鏈��
		if (p_pos.getX() < 100){	//�^�C�}�[�����؂��Ȃ�
			m_timer_pos = CVector3D(TIMER_BORDER_X, p_pos.getY(), p_pos.getZ());
		}
		else{
			m_timer_pos = CVector3D(p_pos.getX() + offset, p_pos.getY(), p_pos.getZ());
		}

		m_timelimit -= 0.0166666f;

		//�J�E���g�_�E������
		if (m_timelimit < 0){	//0�ȉ��Ȃ�
			m_timelimit = 0;
		}

		//�����v���C���[�ɒǏ]�����鏈��
		m_arrow_pos = CVector3D(p_pos.getX() + P_CENTER_X, SCORE_INIT_MAG_Y, 0);

		//�X�R�A�{���̏���
		scoreMagnification(&p_pos);

		//�~�j�}�b�v�̑��s�����̏���
		_move = _totalmove / MAP_DISTANCE;			//�ύX
		if (_move < 405)
			m_maparrow_pos = CVector3D(_move + MAP_P_INIT_X, MAP_P_INIT_Y, 0);

		scoreAddition();
	}
}

void Ui::Draw(){
	int offset1 = 0;	//�^�C�}�[�Ŏg�p
	int offset2 = 1;	//�X�R�A�{���Ŏg�p
	int offset3 = 0;	//���s�{���Ŏg�p	�ǉ�
	int offset4 = 0;	//�ǉ�

	char buf[100];
	float num;
	//�^�C�}�[�̕`��@�����_���ʂ܂�
	//�`��ɂ������āu10.00�v�̂悤�Ȑ����̏ꍇ�A�����_������̂�
	//�P�Q�R�S�T
	//����������
	//�P�O�D�O�O�ƂȂ�
	//num�̐��l��5�ƂȂ�
	//�����Ȃ��3�͐��l�ł͂Ȃ��̂ŏ��O���鏈�����s��

	num = sprintf_s(buf, 100, "%0.2f", m_timelimit);
	for (int i = 0; i < num; i++){

		//10�b�ȉ��̏ꍇ�A��������̂�offset�Ń}�C�i�X������
		if (num == 4.0 && i == 0){

			//10�b�ȉ��̕\�L�A�Ⴆ�΁u09.00�b�v�̏ꍇ�A�ŏ��́u0�v��
			//�\�L����Ȃ��̂ł����ŕ`�悳����

			DrawGraph(m_timer_pos.getX() + (-TIMER_BORDER_X + i * TIMER_SPACE),
				m_timer_pos.getY() + m_timer_pos.getZ() - 60, m_timer_img[0/* - '&'*/], TRUE);
			offset1 = 1;
		}

		//��񌅂̕`��
		if (i > 2 - offset1){
			DrawGraph(m_timer_pos.getX() + (-TIMER_SKIP_X + (i + offset1) * TIMER_SPACE),
				m_timer_pos.getY() + m_timer_pos.getZ() - 60, m_timer_img[(buf[i] - '0')], TRUE);
		}
		//�����_�̕`��
		else if (i == 2 - offset1){
			DrawGraph(m_timer_pos.getX() + (-TIMER_SKIP_X + (i + offset1) * 40),
				m_timer_pos.getY() + m_timer_pos.getZ() - 60, m_timer_img[10], TRUE);
		}
		//���񌅂̕`��
		else{
			DrawGraph(m_timer_pos.getX() + (-TIMER_BORDER_X + (i + offset1) * TIMER_SPACE),
				m_timer_pos.getY() + m_timer_pos.getZ() - 60, m_timer_img[(buf[i] - '0')], TRUE);
		}
	}

	//�X�R�A�����̕`��
	DrawGraph(SCORE_INIT_X, SCORE_INIT_Y, m_score_img, TRUE);
	
	//�X�R�A�̕`��
	num = sprintf_s(buf, 100, "%d", m_totalscore);
	for (int i = 0; i < num; i++){
		DrawGraph(SCORENUM_INIT_X + i * 25,
			SCORENUM_INIT_Y, m_scorenum_img[(buf[i] - '0')], TRUE);		//'0'
	}

	//�A�C�e���̕`��
	for (int i = 0; i < 3; i++){
		DrawGraph(ITEM_FRAME_X + ITEM_IMGSIZE_X*i, ITEM_FRAME_Y, m_item_img[i], TRUE);
	}

	//�}�b�v�̕`��
	DrawGraph(MAP_INIT_X, MAP_INIT_Y, m_map_img, TRUE);
	
	//�}�b�v�̎��@�̕`��
	DrawGraph(m_maparrow_pos.getX(),m_maparrow_pos.getY(),m_scorearrow_img,TRUE);

	//�X�R�A�{���̃��[�^�[�̕`��
	DrawRectGraph(SCOREGAGE_INIT_X, SCOREGAGE_INIT_Y, 0, 0
		,1280, 20, m_scoregage_img[1], TRUE, FALSE);

	//�X�R�A�{���̖��̕`��
	DrawGraph(m_arrow_pos.getX(), m_arrow_pos.getY(), m_scorearrow_img, TRUE);
	
	//�X�R�A�{���̕\�L�̕`��@�����_���ʂ܂�
	num = sprintf_s(buf, 100, "%0.1f", m_score_magnification);
	for (int i = 0; i < num; i++){
		//�~��`��
		if (i == 0){
			DrawGraph(m_arrow_pos.getX() + 30,
				m_arrow_pos.getY() - 10, m_scorenum_img[10], TRUE);
		}
		//�����_�̕`��
		if (i == 1){
			DrawGraph(m_arrow_pos.getX() + SCORE_MAGNIFICATION_X + (i * 32),
				m_arrow_pos.getY() + 3 - SCORE_MAGNIFICATION_Y, m_scorenum_img[11], TRUE);
		}
		//�����̕`��
		else
		{
		DrawGraph(m_arrow_pos.getX() + SCORE_MAGNIFICATION_X+(i * 20),
			m_arrow_pos.getY()-SCORE_MAGNIFICATION_Y, m_scorenum_img[(buf[i] - '0')], TRUE);		//'0'
		}
	}
	
	//�A�C�e��UI�̕`��	30�x�p�x�����Ă܂�
	for (int i = 0; i < 3; i++){
		CItemData* itemdata = CPlayerManager::GetInstance()->GetPlayerAdress()->getEquipment(i);
		if (itemdata->m_img != 0){
			DrawRotaGraph(ITEM_INIT_X + i*ITEM_SPACE_X, ITEM_INIT_Y, 0.5, 3.141592/180*-30, itemdata->m_img, TRUE, FALSE);
		}
	}

	//�e��⑕���̎g�p��		�ǉ�
	for (int j = 0; j < 2; j++){
		num = sprintf_s(buf, 100, "%d", m_ammo[j]);
		for (int i = 0; i < num; i++){
			DrawRotaGraph(((ITEM_FRAME_X + 70 + (j * 100))) + i * 17,
				ITEM_FRAME_Y + 80, 0.7, 0, m_scorenum_img[(buf[i] - '0')], TRUE, FALSE);		//'0'
		}
	}

	//�R���{��		�ǉ�
	if (m_comb_flag == true){
		float temp = 0;
		//�ړ���
		if (m_c_angle < 90){
			m_c_angle++;
		}
		temp = sin(m_c_angle * PI/180);
	//�R���{�̕����`��	�ǉ�
		DrawRotaGraph(COMB_X * temp, COMB_Y - 20, 0.5, 0,
			 m_combotxt_img, TRUE, FALSE);
		//�R���{���`��
		num = sprintf_s(buf, 100, "%d", CEnemyManager::getInstance()->GetComb());
		for (int i = 0; i < num; i++){
			DrawGraph((COMB_X * temp) + i * 25,
				COMB_Y, m_scorenum_img[(buf[i] - '0')], TRUE);		//'0'
		}
	}

	//���s�����̔{�������`��
	if (CPlayerManager::GetInstance()->getNoDamageMovement()>2500){
		float temp = 0;
		if (m_c_angle < 90){
			m_c_angle++;
		}
		temp = sin(m_c_angle * PI / 180);
		for (int i = 0; i < 2; i++){
			DrawRotaGraph(COMB_X * temp, BONUS_Y - 20 + (35 * i), 0.4, 0,
				m_totalrun_txt_img[i], TRUE, FALSE);
		}
		//���s�����̔{���`��
		num = sprintf_s(buf, 100, "%0.1f", m_ndm_magnification);
		for (int i = 0; i < num; i++){
			if (i == 0){
				DrawGraph((BONUS_X * temp) + 30,
					COMB_Y, m_scorenum_img[10], TRUE);
			}
			if (i - offset3 == 1){
				DrawGraph((BONUS_X * temp) + (SCORE_MAGNIFICATION_X - offset4) + (i * 32),
					COMB_Y, m_scorenum_img[11], TRUE);		//.
			}
			else{
				DrawGraph((BONUS_X * temp) + SCORE_MAGNIFICATION_X + (i * 20),
					COMB_Y, m_scorenum_img[(buf[i] - '0')], TRUE);
			}
		}
	}
}

void Ui::scoreMagnification(CVector3D *pos){	
	m_score_magnification = (pos->getX() / 320) + 1;
	if (m_score_magnification < 1){
		m_score_magnification = 1;
	}
}

void Ui::scoreAddition(){		//�ǉ�
	int _s = 0;		//�X�R�A�v�Z����
	float _comb = (float)CEnemyManager::getInstance()->GetComb();	//�R���{�{��
	float _nodamagemove = CPlayerManager::GetInstance()->getNoDamageMovement();		//���s�����ɉ������X�R�A�{��
	float _item_score = CPlayerManager::GetInstance()->GetPlayerAdress()->getBuff()->m_score_ratio;

	//�ŏ��ɃR���{������
	if (m_past_comb == 0){
		m_past_comb = _comb;
	}
	else if(m_past_comb != _comb){
		m_c_angle = COMB_MOVE_X;
		m_past_comb = _comb;
	}

	//�o������
	if (_comb < 1)
		m_comb_flag = false;
	else{
		m_comb_flag = true;
		CPlayerManager::GetInstance()->setNoDamageMovement(0);
	}

	//�{���̏����l��1.0
	//_comb = (_comb / 10) + 1;

	//�G�l�~�[��|������
	if (CEnemyManager::getInstance()->GetDel() == true){
		_s = (m_score_magnification+_comb + _item_score) * 100;		//��ʓ��̔{���{�R���{
		m_totalscore += _s;
		CEnemyManager::getInstance()->SetDel(false);

	}

	//�U��������苗���܂ő����
	if (_nodamagemove > 2500){
		m_ndm_magnification = _nodamagemove / 2500;
		if (CPlayerManager::GetInstance()->getNdmFalg() == true){
			m_totalscore += (m_score_magnification + m_ndm_magnification + _item_score) * 50;	//��ʓ��̔{���{���s�����{��
			CPlayerManager::GetInstance()->setNdmFalg(false);
		}
	}
}

void Ui::scoreFluctuation(int points){
	m_totalscore += points;
}