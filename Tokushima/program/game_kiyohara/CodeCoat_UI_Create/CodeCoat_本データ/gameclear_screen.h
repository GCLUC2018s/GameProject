#ifndef __SCREEN_CLEAR_H__
#define __SCREEN_CLEAR_H__

//ヘッダファイル
#include "myLib.h"
#include "screen.h"

const int GAMECLEAR_TIME = (46 * 1000);

//セレクトスクリーンクラス
class CGameClearScreen : public CScreen
{
public:
	CGameClearScreen();
	~CGameClearScreen();
	SCREEN GetNextScreen();
	void Load();
	void Init();
	void Update();
	void Draw();
	void Dest();
private:
	SCREEN m_state;
	int m_alphatime;
	int m_alpha;
	int m_count;
	int m_largefont;
	int m_lasttime;
	int scroll[19];
	int m_rogoimage;
	int clear_BGM;
};
#endif __SCREEN_CLEAR_H__