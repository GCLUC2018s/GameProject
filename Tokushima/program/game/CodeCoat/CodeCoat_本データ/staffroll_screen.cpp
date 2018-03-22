#include "staffroll_screen.h"

//コンストラクタ
CStaffRollScreen::CStaffRollScreen()
{
	m_state = STAFFROLL_SCREEN;
	//初期化
	m_lasttime = GetNowCount() &INT_MAX;
	for (int a = 0; a < STRING_COUNT; a++)
		scroll[a] = 730;
	m_rogoimage = LoadGraph("media\\img\\title_02.png");
	m_count = 0;
	m_alpha = 255;
	m_alphatime = -170;
	//ロード
	m_largefont = CreateFontToHandle("メイリオ", 50, -1, DX_FONTTYPE_ANTIALIASING);
}

//デストラクタ
CStaffRollScreen::~CStaffRollScreen(){

}

void CStaffRollScreen::Dest(){}

//実行処理
void CStaffRollScreen::Update()
{
	/*if (m_count == 0){
		PlaySoundMem(clear_BGM, DX_PLAYTYPE_LOOP);
		m_count = 1;
	}*/
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMECLEAR_TIME){
		m_state = TITLE_SCREEN;//時間は調整
	}

	scroll[0] -= 2;
	if (scroll[0] < 500)
		scroll[1] -= 2;
	if (scroll[1] < 730)
		scroll[2] -= 2;
	if (scroll[2] < 550)
		scroll[3] -= 2;
	if (scroll[3] < 550)
		scroll[4] -= 2;
	if (scroll[4] < 730)
		scroll[5] -= 2;
	if (scroll[5] < 550)
		scroll[6] -= 2;
	if (scroll[6] < 550)
		scroll[7] -= 2;
	if (scroll[7] < 730)
		scroll[8] -= 2;
	if (scroll[8] < 650)
		scroll[9] -= 2;
	if (scroll[9] < 650)
		scroll[10] -= 2;
	if (scroll[10] < 650)
		scroll[11] -= 2;
	else if (scroll[11] == 230){
		if (m_alphatime < 50)
			m_alphatime++;
		if (m_alphatime >= 0){
			m_alpha = 255 - (255 / 35)*m_alphatime;		//透明化処理
		}
	}
}

//描画
void CStaffRollScreen::Draw()
{
	ClearDrawScreen();
	DrawStringToHandle(100, scroll[0], "制作スタッフ", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[1], "プログラマー", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[2], "清原一真", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[3], "宮田拓弥", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[4], "デザイナー", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[5], "小濵瑠生", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[6], "須崎　将", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[7], "音楽提供", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[8], "魔王魂", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[9], "ポケットサウンド", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[10], "On-Jin ～音人～", GetColor(255, 255, 255), m_largefont, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
	DrawGraph(180, scroll[11], m_rogoimage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//次にステージ
SCREEN CStaffRollScreen::GetNextScreen()
{
	return (m_state);
}