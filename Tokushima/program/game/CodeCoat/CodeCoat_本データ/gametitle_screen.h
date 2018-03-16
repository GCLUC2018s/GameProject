#ifndef __SCREEN_TITLE_H__
#define __SCRENE_TITLE_H__

//ヘッダーファイル
#include "myLib.h"
#include "Scene\SceneBase.h"

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
	int titleName;		//画像
	int titleBack;
	int titlePushA;
	int BrightTrance;
	int m_middlefont;
	int alpha;
	int alpha2;
	bool flagTurn;
	bool countstart;
	int count;
	int max_title;
	int serect_SE;
};
#endif __SCREEN_TITLE_H__