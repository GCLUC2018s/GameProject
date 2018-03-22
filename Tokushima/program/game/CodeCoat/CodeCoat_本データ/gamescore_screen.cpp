#include "gamescore_screen.h"
#include "score_manager.h"
#include "Task\CTaskManager.h"

//コンストラクタ
CGameScoreScreen::CGameScoreScreen()
{
	m_state = GAMESCORE_SCREEN;
	//初期化
	m_lasttime = GetNowCount() & INT_MAX;
	new ScoreData;
	CTaskManager::GetInstance();
}

//デストラクタ
CGameScoreScreen::~CGameScoreScreen(){
	CTaskManager::GetInstance()->KillAll();
}

void CGameScoreScreen::Dest(){
}

//実行処理
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

//描画
void CGameScoreScreen::Draw()
{
	ClearDrawScreen();
	CTaskManager::GetInstance()->DrawAll();
}


//次にステージ
SCREEN CGameScoreScreen::GetNextScreen()
{
	return (m_state);
}