#ifndef __SCREEN_SELECT_H__
#define __SCREEN_SELECT_H__

//ヘッダファイル
#include "myLib.h"
#include "screen.h"

//プロトタイプ
struct GameData;

//セレクトスクリーンクラス
class CSelectScreen : public CScreen
{
public:
	CSelectScreen();
	~CSelectScreen();
	SCREEN GetNextScreen();
	void Load();
	void Release();
	void Init();
	void Update();
	void Draw();
private:
	SCREEN m_state;
};
#endif __SCREEN_SELECT_H__