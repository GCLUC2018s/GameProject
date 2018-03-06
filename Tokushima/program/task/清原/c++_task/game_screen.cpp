
//ヘッダーファイル
#include "game_screen.h"

//コンストラクタ
CGameScreen::CGameScreen()
{
	m_state = GAME_SCREEN;
}

//デストラクタ
CGameScreen::~CGameScreen(){}

//ロード
void CGameScreen::Load(){
	//map.loadMap();
	//map.loadItem();
}

//リリース
void CGameScreen::Release(){}

//初期化
void CGameScreen::Init(){}

//実行処理
void CGameScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_E) == 1) m_state = GAMEOVER_SCREEN;
	if (CheckHitKey(KEY_INPUT_F) == 1) m_state = GAMECLEAR_SCREEN;
}

//描画
void CGameScreen::Draw()
{
	ClearDrawScreen();
	//map.drawMap();
	DrawString(10, 100, "Game Screen Hit E key to Gameover Screen\n F key to Gameclear Screen", GetColor
		(255, 255, 255));
}

//次のステージへ
SCREEN CGameScreen::GetNextScreen()
{
	return(m_state);
}