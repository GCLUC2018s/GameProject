#include "gamescore_screen.h"

//�R���X�g���N�^
CGameScoreScreen::CGameScoreScreen()
{
	m_state = GAMESCORE_SCREEN;
}

//�f�X�g���N�^
CGameScoreScreen::~CGameScoreScreen(){}

void CGameScoreScreen::Dest(){
	StopSoundMem(m_GoverSound);
}

//���[�h
void CGameScoreScreen::Load(){
	m_BGclearImage = LoadGraph("media\\img\\GAMECLEAR2.png");
	m_GoverSound = LoadSoundMem("media\\mp3\\gameover\\sousou3.mp3");
}

//������
void CGameScoreScreen::Init(){
	m_lasttime = GetNowCount() & INT_MAX;
	PlaySoundMem(m_GoverSound, DX_PLAYTYPE_BACK);
}

//���s����
void CGameScoreScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > BADGAMECLEAR_TIME){
		m_state = TITLE_SCREEN;
		StopSoundMem(m_GoverSound);
	}
	//if (CheckHitKey(KEY_INPUT_X) == 1){
		//m_state = GAME_SCREEN;
		//StopSoundMem(m_GoverSound);
	//}
}

//�`��
void CGameScoreScreen::Draw()
{
	ClearDrawScreen();
	DrawGraph(0, 0, m_BGclearImage, TRUE);
}


//���ɃX�e�[�W
SCREEN CGameScoreScreen::GetNextScreen()
{
	return (m_state);
}