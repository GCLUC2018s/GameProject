#ifndef __MAIN_H__
#define __MAIN_H__

//ヘッダファイル
#include <DxLib.h>

//プロトタイプ
class CGame;

//メインクラス
class CMain			//stateパターン
{
public:
	CMain();
	~CMain();
	
	void Dest();	//読み込み
	void Update();  //更新
	void Draw();	//描画
private:
	CGame* m_pGame;
};
#endif __MAIN_H__