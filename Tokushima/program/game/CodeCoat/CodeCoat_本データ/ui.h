#ifndef UI_H
#define UI_H

#include "Task\CTask.h"
#include "myLib.h"

const float SCORE_INIT_X = 0;				//�X�R�AX
const float SCORE_INIT_Y = 650;				//�X�R�AY
const float SCOREGAGE_INIT_X = 0;			//�X�R�A�Q�[�WX
const float SCOREGAGE_INIT_Y = 600;			//�X�R�A�Q�[�WY
const float SCORENUM_INIT_X = 380;			//�X�R�A�i���o�[X
const float SCORENUM_INIT_Y = 650;			//�X�R�A�i���o�[Y
const float MAP_INIT_X = 810;				//�~�j�}�b�vX
const float MAP_INIT_Y = 620;				//�~�j�}�b�vY
const float MAP_P_INIT_X = 812;				//�~�j�}�b�v�̃v���C���[X
const float MAP_P_INIT_Y = 665;				//�~�j�}�b�v�̃v���C���[Y
const float SCORE_INIT_MAG_X = 0;			//�X�R�A�{����X
const float SCORE_INIT_MAG_Y = 575;			//�X�R�A�{����Y
const float ITEM_INIT_X = 540;				//�A�C�e����X
const float ITEM_INIT_Y = 670;				//�A�C�e����Y
const float ITEM_SPACE_X = 100;				//�A�C�e����X

const float P_CENTER_X = 83;				//�v���C���[�̐^�񒆂̍��WX
const float ITEM_FRAME_X = 490;				//�A�C�e���̃t���[��X
const float ITEM_FRAME_Y = 620;				//�A�C�e���̃t���[��Y
const float ITEM_IMGSIZE_X = 100;			//�A�C�e���̉摜�T�C�Y
const float SCORE_MAGNIFICATION_X = 57;		//�X�R�A�{����X���W
const float SCORE_MAGNIFICATION_Y = 15;		//�X�R�A�{����Y���W
const float TIMER_BORDER_X = 150.0f;		//���؂ꂽ�ꍇ�̐������Ԃ�X���W
const float TIMER_OVER_X = 100.0f;			//�������Ԃ����؂��X�̌��E�l
const float TIMER_SKIP_X = 170.0f;			//�R�������΂����Ƃ���X���W
const int TIMER_SPACE = 35;					//�^�C�}�[�̕�����
const int TIMER_COLON_CONT_X = 40;			//�^�C�}�[�̃R������X���W

class Ui :public CTask{
private:
	int m_timer_img[12];		//�������Ԃ̉摜
	int m_scorenum_img[12];		//�X�R�A�̐����摜
	int m_item_img[4];			//�A�C�e���̉摜
	int m_score_img;			//�u�X�R�A�v�̉摜
	int m_scoregage_img[2];		//�X�R�A�Q�[�W�̉摜
	int m_map_img;				//�~�j�}�b�v�̉摜
	int m_scorearrow_img;		//�X�R�A�Q�[�W�̖��̉摜
	int m_item_bg_img;			//�A�C�e���̃o�b�N�O���E���h�摜
	CVector3D m_timer_pos;		//�������Ԃ̍��W
	CVector3D m_arrow_pos;		//�X�R�A�{���̖��̍��W	�X�R�A�{���ł��g�p
	CVector3D m_maparrow_pos;	//�~�j�}�b�v�̎��@�̍��W
	int m_totalscore;				//�X�R�A��
	float m_timelimit;				//�^�C�����~�b�g
	float m_score_magnification;	//�X�R�A�{��
public:
	Ui();
	Ui(CVector3D p_pos);
	~Ui();
	void Update();
	void Draw();
	void scoreMagnification(CVector3D *pos);	//
	void scoreAddition(int points);		//
};

#endif UI_H