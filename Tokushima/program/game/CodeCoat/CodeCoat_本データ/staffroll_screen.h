#ifndef __SCREEN_CLEAR_H__
#define __SCREEN_CLEAR_H__

//ヘッダファイル
#include "myLib.h"
#include "Scene\SceneBase.h"

const int GAMECLEAR_TIME = (46 * 1000);
const int STRING_COUNT = 12;//流れる文字列の個数

//セレクトスクリーンクラス
class CStaffRollScreen : public CSceneBase
{
public:
	CStaffRollScreen();
	~CStaffRollScreen();
	SCREEN GetNextScreen();
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
	int scroll[STRING_COUNT];
	int m_rogoimage;
	int clear_BGM;
};
#endif __SCREEN_CLEAR_H__