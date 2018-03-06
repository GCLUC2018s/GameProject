#ifndef MAIN_H
#define MAIN_H

//ヘッダーファイル
#include <stdio.h>
#include "Dxlib.h"

//プロトタイプ
class CGame;

//メインクラス
class CMain
{
public:
	CMain();
	~CMain();

	void Init();
	void Dest();
	void Update();
	void Draw();
private:
	CGame* m_pGame;
};
#endif MAIN_H