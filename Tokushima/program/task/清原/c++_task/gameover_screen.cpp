
//ヘッダーファイル
#include "gameover_screen.h"

//コンストラクタ
CGameOverScreen::CGameOverScreen()
{
	m_state = GAMEOVER_SCREEN;
}

//デストラクタ
CGameOverScreen::~CGameOverScreen(){}

//ロード
void CGameOverScreen::Load(){}

//リリース
void CGameOverScreen::Release(){}

//初期化
void CGameOverScreen::Init(){}

//実行処理
void CGameOverScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_C) == 1) m_state = TITLE_SCREEN;
}

//描画
void CGameOverScreen::Draw()
{
	ClearDrawScreen();
	DrawString(10, 100, "SELECT Screen Hit C key to Title Screen", GetColor
		(255, 255, 255));
}

//次のステージへ
SCREEN CGameOverScreen::GetNextScreen()
{
	return( m_state );
}