//ヘッダーファイル
#include "gameclear_screen.h"

//コンストラクタ
CGameClearScreen::CGameClearScreen()
{
	m_state = GAMECLEAR_SCREEN;
}

//デストラクタ
CGameClearScreen::~CGameClearScreen(){}

//ロード
void CGameClearScreen::Load(){}

//リリース
void CGameClearScreen::Release(){}

//初期化
void CGameClearScreen::Init(){}

//実行処理
void CGameClearScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_C) == 1) m_state = TITLE_SCREEN;
}

//描画
void CGameClearScreen::Draw()
{
	ClearDrawScreen();
	DrawString(10, 100, "SELECT Screen Hit C key to Title Screen", GetColor
		(255, 255, 255));
}

//次のステージへ
SCREEN CGameClearScreen::GetNextScreen()
{
	return(m_state);
}