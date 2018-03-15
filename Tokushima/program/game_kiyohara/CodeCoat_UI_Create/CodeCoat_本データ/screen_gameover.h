#ifndef __SCREEN_OVER_H__
#define __SCREEN_OVER_H__

//ヘッダファイル
#include "myLib.h"
#include "screen.h"

const int GAMEOVER_TIME = (5 * 1000);

//ゲームオーバースクリーンクラス
class CGameOverScreen : public CScreen
{
public:
	CGameOverScreen();
	~CGameOverScreen();
	SCREEN GetNextScreen();
	void Load();
	void Init();
	void Update();
	void Draw();
	void Dest();
private:
	SCREEN m_state;
	int m_GoverSound;
	int m_GoverImage;
	int m_lasttime;
};
#endif __SCREEN_OVER_H__