#include "gametitle_screen.h"
int stagenum;
//コンストラクタ
CTitleScreen::CTitleScreen()
{
	m_state = TITLE_SCREEN;
}

//デストラクタ
CTitleScreen::~CTitleScreen() {}

void CTitleScreen::Dest(){}
//ロード
void CTitleScreen::Load() {
	
}

//初期化
void CTitleScreen::Init(){
	
}

//実行処理
void CTitleScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_A) == 1) m_state = GAME_SCREEN;
}

//描画
void CTitleScreen::Draw()
{
	ClearDrawScreen();
	DrawString(10, 100, "TITLE Screen Hit A key to Next Screen", GetColor
		(255, 255, 255));
}

//次のステージへ
SCREEN CTitleScreen::GetNextScreen()
{
	return (m_state);
}