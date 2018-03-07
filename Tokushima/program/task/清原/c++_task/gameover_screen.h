#ifndef GAMEOVER_SCREEN_H
#define GAMEOVER_SCREEN_H

//ヘッダーファイル
#include "myLib.h"
#include "screen.h"
#include "game_data.h"

//プロトタイプ
struct GameData;

//セレクトスクリーンクラス
class CGameOverScreen : public CScreen
{
public:
	CGameOverScreen();
	~CGameOverScreen();
	SCREEN GetNextScreen();
	void Load();
	void Release();
	void Init();
	void Update();
	void Draw();
private:
	SCREEN m_state;
};
#endif GAMEOVER_SCREEN_H