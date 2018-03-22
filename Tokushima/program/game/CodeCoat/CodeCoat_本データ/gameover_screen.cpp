#include "gameover_screen.h"
#include "se_manager.h"

//コンストラクタ
CGameOverScreen::CGameOverScreen()
{
	m_state = GAMEOVER_SCREEN;
	//初期化
	m_lasttime = GetNowCount() & INT_MAX;
	//ロード
	m_gover_bg_img = LoadGraph("media\\img\\bg_black.png");
	m_gover_light_img = LoadGraph("media\\img\\light.png");
	m_gover_txt_img = LoadGraph("media\\img\\gm_over_02.png");
	PlaySoundMem(CSeManager::GetInstance()->getsnd(OVER_SE), DX_PLAYTYPE_BACK);
}

//デストラクタ
CGameOverScreen::~CGameOverScreen(){}

void CGameOverScreen::Dest(){
	//StopSoundMem(m_GoverSound);
}


//実行処理
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

//描画
void CGameOverScreen::Draw()
{
	ClearDrawScreen();
	DrawGraph(0, 0, m_gover_bg_img, TRUE);
	DrawGraph(0, 0, m_gover_light_img, TRUE);
	DrawGraph(285, 305, m_gover_txt_img, TRUE);
}


//次にステージ
SCREEN CGameOverScreen::GetNextScreen()
{
	return (m_state);
}