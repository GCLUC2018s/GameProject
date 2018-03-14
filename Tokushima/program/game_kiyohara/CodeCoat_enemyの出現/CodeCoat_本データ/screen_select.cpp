#include "screen_select.h"

//コンストラクタ
CSelectScreen::CSelectScreen()
{
	m_state = SELECT_SCREEN;
}

//デストラクタ
CSelectScreen::~CSelectScreen(){}

//ロード
void CSelectScreen::Load(){}

//リリース
void CSelectScreen::Release(){}

//初期化
void CSelectScreen::Init(){}

//実行処理
void CSelectScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_C) == 1) m_state = TITLE_SCREEN;
}

//描画
void CSelectScreen::Draw()
{
	ClearDrawScreen();
	DrawString(10, 100, "SELECT Screen Hit C key to Title Screen", GetColor(255, 255, 255));
}


//次にステージ
SCREEN CSelectScreen::GetNextScreen()
{
	return (m_state);
}