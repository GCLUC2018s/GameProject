#include "gamescore_screen.h"
#include "score_manager.h"
#include "Task\CTaskManager.h"

//�R���X�g���N�^
CGameScoreScreen::CGameScoreScreen()
{
	m_state = GAMESCORE_SCREEN;
	//������
	m_lasttime = GetNowCount() & INT_MAX;
	new ScoreData;
}

//�f�X�g���N�^
CGameScoreScreen::~CGameScoreScreen(){
	CTaskManager::GetInstance()->KillAll();
}

void CGameScoreScreen::Dest(){
}

//���s����
void CGameScoreScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > BADGAMECLEAR_TIME){
		m_state = TITLE_SCREEN;
		//StopSoundMem(m_GoverSound);
	}
	CTaskManager::GetInstance()->UpdateAll();
	//if (CheckHitKey(KEY_INPUT_X) == 1){
		//m_state = GAME_SCREEN;
		//StopSoundMem(m_GoverSound);
	//}
}

//�`��
void CGameScoreScreen::Draw()
{
	ClearDrawScreen();
	CTaskManager::GetInstance()->DrawAll();
	DrawString(10, 100, "SCORE Screen 5Seconds to Next Screen", GetColor
		(255, 255, 255));
}


//���ɃX�e�[�W
SCREEN CGameScoreScreen::GetNextScreen()
{
	return (m_state);
}