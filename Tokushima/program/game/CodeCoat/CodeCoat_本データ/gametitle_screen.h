#ifndef __SCREEN_TITLE_H__
#define __SCRENE_TITLE_H__

//ヘッダーファイル
#include "myLib.h"
#include "Scene\SceneBase.h"

const int TITLE_BG_F_X = 0;
const int TITLE_BG_F_Y = 250;
const int TITLE_BG_B_X = 0;
const int TITLE_BG_B_Y = 250;
const int TITLE_INIT_TEXT_X = 1280;		//初期地点
const int TITLE_TEXT_X = 270;
const int TITLE_TEXT_Y = 70;
const int TITLE_AKEY_X = 415;
const int TITLE_AKEY_Y = 500;
const int TITLE_M_TEXT_X = 10;
const float TITLE_M_AKEY_X = 8.6f;

//タイトルスクリーンクラス
class CTitleScreen : public CSceneBase
{
public:
	CTitleScreen();
	~CTitleScreen();
	SCREEN GetNextScreen();
	void Update();
	void Draw();
	void Dest();
private:
	SCREEN m_state;
	CVector3D m_titlename_pos;
	CVector3D m_title_akey_pos;
	int m_titleName_img;		//画像
	int m_titleBg_f_img;
	int m_titleBg_b_img;
	int m_titlePushA_img;
	int m_count;
	int m_drawtime;
	bool m_start;				//ボタン入力時移動し始める
	bool m_drawflag;
	int serect_SE;
};
#endif __SCREEN_TITLE_H__