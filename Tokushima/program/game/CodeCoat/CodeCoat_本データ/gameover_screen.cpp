#include "gameover_screen.h"

//コンストラクタ
CGameOverScreen::CGameOverScreen()
{
	m_state = GAMEOVER_SCREEN;
	//初期化
	m_lasttime = GetNowCount() & INT_MAX;
	PlaySoundMem(m_GoverSound, DX_PLAYTYPE_BACK);
	//ロード
	m_GoverImage = LoadGraph("media\\img\\GO_02.png");
	m_GoverSound = LoadSoundMem("media\\mp3\\gameover\\sousou3.mp3");
}

//デストラクタ
CGameOverScreen::~CGameOverScreen(){}

void CGameOverScreen::Dest(){
	StopSoundMem(m_GoverSound);
}


//実行処理
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

//描画
void CGameOverScreen::Draw()
{
	ClearDrawScreen();
	DrawGraph(0, 0, m_GoverImage, TRUE);
}


//次にステージ
SCREEN CGameOverScreen::GetNextScreen()
{
	return (m_state);
}