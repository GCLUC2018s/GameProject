#include "gameover_screen.h"
#include "se_manager.h"

//�R���X�g���N�^
CGameOverScreen::CGameOverScreen()
{
	m_state = GAMEOVER_SCREEN;
	//������
	m_lasttime = GetNowCount() & INT_MAX;
	//���[�h
	m_gover_bg_img = LoadGraph("media\\img\\bg_black.png");
	m_gover_light_img = LoadGraph("media\\img\\light.png");
	m_gover_txt_img = LoadGraph("media\\img\\gm_over_02.png");
	PlaySoundMem(CSeManager::GetInstance()->getsnd(OVER_SE), DX_PLAYTYPE_BACK);
}

//�f�X�g���N�^
CGameOverScreen::~CGameOverScreen(){}

void CGameOverScreen::Dest(){
	//StopSoundMem(m_GoverSound);
}


//���s����
void CGameOverScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMEOVER_TIME){
		m_state = TITLE_SCREEN;
		//StopSoundMem(m_GoverSound);
	}
	/*if (CheckHitKey(KEY_INPUT_X) == 1){
		m_state = GAME_SCREEN;
		//StopSoundMem(m_GoverSound);
	}*/
}

//�`��
void CGameOverScreen::Draw()
{
	ClearDrawScreen();
	DrawGraph(0, 0, m_gover_bg_img, TRUE);
	DrawGraph(0, 0, m_gover_light_img, TRUE);
	DrawGraph(285, 305, m_gover_txt_img, TRUE);
}


//���ɃX�e�[�W
SCREEN CGameOverScreen::GetNextScreen()
{
	return (m_state);
}