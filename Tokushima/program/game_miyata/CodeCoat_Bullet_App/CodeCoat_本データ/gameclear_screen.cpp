#include "gameclear_screen.h"

//コンストラクタ
CGameClearScreen::CGameClearScreen()
{
	m_state = GAMECLEAR_SCREEN;
}

//デストラクタ
CGameClearScreen::~CGameClearScreen(){}

void CGameClearScreen::Dest(){}

//ロード
void CGameClearScreen::Load(){
	m_largefont = CreateFontToHandle("メイリオ", 50, -1, DX_FONTTYPE_ANTIALIASING);
	clear_BGM = LoadSoundMem("media\\mp3\\staffroll\\free_bgm12.mp3");
}

//初期化
void CGameClearScreen::Init(){
	m_lasttime = GetNowCount() &INT_MAX;
	for (int a = 0; a < 19; a++)
		scroll[a] = 730;
	m_rogoimage = LoadGraph("media\\img\\Title.png");
	m_count = 0;
	m_alpha = 255;
	m_alphatime = -170;
}

//実行処理
void CGameClearScreen::Update()
{
	if (m_count == 0){
		PlaySoundMem(clear_BGM, DX_PLAYTYPE_LOOP);
		m_count = 1;
	}
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMECLEAR_TIME){
		m_state = TITLE_SCREEN;//時間は調整
		StopSoundMem(clear_BGM);
	}

	scroll[0] -= 2;
	if (scroll[0] < 500)
		scroll[1] -= 2;
	if (scroll[1] < 550)
		scroll[2] -= 2;
	if (scroll[2] < 730)
		scroll[3] -= 2;
	if (scroll[3] < 550)
		scroll[4] -= 2;
	if (scroll[4] < 730)
		scroll[5] -= 2;
	if (scroll[5] < 650)
		scroll[6] -= 2;
	if (scroll[6] < 650)
		scroll[7] -= 2;
	if (scroll[7] < 550)
		scroll[8] -= 2;
	if (scroll[8] < 730)
		scroll[9] -= 2;
	if (scroll[9] < 650)
		scroll[10] -= 2;
	if (scroll[10] < 550)
		scroll[11] -= 2;
	if (scroll[11] < 730)
		scroll[12] -= 2;
	if (scroll[12] < 650)
		scroll[13] -= 2;
	if (scroll[13] < 650)
		scroll[14] -= 2;
	if (scroll[14] < 650)
		scroll[15] -= 2;
	if (scroll[15] < 650)
		scroll[16] -= 2;
	if (scroll[16] < 650)
		scroll[17] -= 2;
	if (scroll[17] < 200 && scroll[18] > 230)
		scroll[18] -= 2;
	else if (scroll[18] == 230){
		if (m_alphatime < 50)
			m_alphatime++;
		if (m_alphatime >= 0){
			m_alpha = 255 - (255 / 35)*m_alphatime;		//透明化処理
		}
	}
}

//描画
void CGameClearScreen::Draw()
{
	ClearDrawScreen();
	DrawStringToHandle(100, scroll[0], "学校法人穴吹学園", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[1], "制作スタッフ", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[2], "プランナー", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[3], "井織諒仁", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[4], "デザイナー", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[5], "釜内優多", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[6], "須崎　将", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[7], "大和卓生", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[8], "プログラマー", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[9], "清原一真", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[10], "宮田拓弥", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[11], "音楽提供", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[12], "魔王魂", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[13], "D.elf.com", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[14], "くらげ工匠", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[15], "ポケットサウンド", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[16], "On-Jin ～音人～", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[17], "ニコニコモンズ", GetColor(255, 255, 255), m_largefont, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
	DrawGraph(180, scroll[18], m_rogoimage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//次にステージ
SCREEN CGameClearScreen::GetNextScreen()
{
	return (m_state);
}