#ifndef __SCREEN_OVER_H__
#define __SCREEN_OVER_H__

//ヘッダファイル
#include "myLib.h"
#include "Scene\SceneBase.h"

const int GAMEOVER_TIME = (5 * 1000);

//ゲームオーバースクリーンクラス
class CGameOverScreen : public CSceneBase
{
public:
	CGameOverScreen();
	~CGameOverScreen();
	SCREEN GetNextScreen();
	void Update();
	void Draw();
	void Dest();
private:
	SCREEN m_state;
	int m_goversound;
	int m_gover_bg_img;
	int m_gover_light_img;
	int m_gover_txt_img;
	int m_lasttime;
};
#endif __SCREEN_OVER_H__