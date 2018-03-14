#ifndef __GAME_H__
#define __GAME_H__

//ヘッダファイル
#include "myLib.h"

//プロトタイプ
enum SCREEN;
class CSceneBase;

//ゲームクラス
class CGame
{
public:
	CGame();
	~CGame();
	void Init();
	void Dest();
	void Update();
	void Draw();
private:
	CSceneBase* m_pScreen;
	SCREEN m_now_screen;
};
#endif __GAME_H__