#ifndef __SCREEN_BADCLEAR_H__
#define __SCREEN_BADCLEAR_H__

//ヘッダファイル
#include "myLib.h"
#include "screen.h"

const int BADGAMECLEAR_TIME = (7 * 1000);

//ゲームオーバースクリーンクラス
class CGameScoreScreen : public CScreen
{
public:
	CGameScoreScreen();
	~CGameScoreScreen();
	SCREEN GetNextScreen();
	void Load();
	void Init();
	void Update();
	void Draw();
	void Dest();
private:
	SCREEN m_state;
	int m_GoverSound;
	int m_BGclearImage;
	int m_lasttime;
};
#endif __SCREEN_BADCLEAR_H__