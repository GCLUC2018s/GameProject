#include "gameover_screen.h"

//�R���X�g���N�^
CGameOverScreen::CGameOverScreen()
{
	m_state = GAMEOVER_SCREEN;
	//������
	m_lasttime = GetNowCount() & INT_MAX;
	PlaySoundMem(m_GoverSound, DX_PLAYTYPE_BACK);
	//���[�h
	m_GoverImage = LoadGraph("media\\img\\GO_02.png");
	m_GoverSound = LoadSoundMem("media\\mp3\\gameover\\sousou3.mp3");
}

//�f�X�g���N�^
CGameOverScreen::~CGameOverScreen(){}

void CGameOverScreen::Dest(){
	StopSoundMem(m_GoverSound);
}


//���s����
void CGameOverScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMEOVER_TIME){
		m_state = TITLE_SCREEN;
		StopSoundMem(m_GoverSound);
	}
	if (CheckHitKey(KEY_INPUT_X) == 1){
		m_state = GAME_SCREEN;
		StopSoundMem(m_GoverSound);
	}
}

//�`��
void CGameOverScreen::Draw()
{
	ClearDrawScreen();
	DrawGraph(0, 0, m_GoverImage, TRUE);
}


//���ɃX�e�[�W
SCREEN CGameOverScreen::GetNextScreen()
{
	return (m_state);
}