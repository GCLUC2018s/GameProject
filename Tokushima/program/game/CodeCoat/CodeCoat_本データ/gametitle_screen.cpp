#include "gametitle_screen.h"
int stagenum;
//�R���X�g���N�^
CTitleScreen::CTitleScreen():
m_titlename_pos(TITLE_INIT_TEXT_X,TITLE_TEXT_Y,0),
m_title_akey_pos(TITLE_INIT_TEXT_X, TITLE_AKEY_Y, 0),
m_count(0),
m_drawtime(0)
{
	m_state = TITLE_SCREEN;
	m_titleName_img = LoadGraph("media\\img\\title_02.png");
	m_titleBg_f_img = LoadGraph("media\\img\\bg_front.png");
	m_titleBg_b_img = LoadGraph("media\\img\\bg_back.png");
	m_titlePushA_img = LoadGraph("media\\img\\press_A_key1.png");
}

//�f�X�g���N�^
CTitleScreen::~CTitleScreen() {}

void CTitleScreen::Dest(){}

//���s����
void CTitleScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_A) == 1) m_state = GAME_SCREEN;
	
	//�^�C�g�����ړ�
	if (m_titlename_pos.getX() > TITLE_TEXT_X){
		m_titlename_pos += CVector3D(-TITLE_M_TEXT_X,0,0);
	}

	//�uA�{�^���������v�ړ�
	if (m_title_akey_pos.getX() > TITLE_AKEY_X){
		m_title_akey_pos += CVector3D(-TITLE_M_AKEY_X,0,0);
	}
	else{
		m_count++;
		m_drawtime = m_count / 45 % 2;
	}
}

//�`��
void CTitleScreen::Draw()
{
	ClearDrawScreen();
	DrawGraph(0, -TITLE_BG_B_Y, m_titleBg_b_img, TRUE);
	DrawGraph(0, -TITLE_BG_F_Y, m_titleBg_f_img, TRUE);
	DrawGraph(m_titlename_pos.getX(), m_titlename_pos.getY(), m_titleName_img, TRUE);
	if (m_drawtime == 0){
		DrawGraph(m_title_akey_pos.getX(), m_title_akey_pos.getY(), m_titlePushA_img, TRUE);
	}
	DrawString(10, 100, "TITLE Screen Hit A key to Next Screen", GetColor
		(255, 255, 255));
}

//���̃X�e�[�W��
SCREEN CTitleScreen::GetNextScreen()
{
	return (m_state);
}