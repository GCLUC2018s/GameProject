#ifndef __SCREEN_GAME_H__
#define __SCRENE_GAME_H__

//ヘッダーファイル
#include "myLib.h"
#include "Scene\SceneBase.h"
#include "map.h"
#include "player.h"
#include "item.h"

const int CLEAR_TEXT_INI_X = 1280;
const int CLEAR_TEXT1_INI_Y = 200;
const int CLEAR_TEXT2_INI_Y = 310;
const int CLEAR_TEXT_X = 285;
const int CLEAR_TEXT_Y = 200;

//プロトタイプ
struct GameData;

//タイトルスクリーンクラス
class CGameScreen : public CSceneBase
{
public:
	CGameScreen();
	~CGameScreen();
	SCREEN GetNextScreen();
	void Update();
	void Draw();
	void Dest();
	void GoalMove();
private:
	SCREEN m_state;
	CVector3D m_cpos1;		//mission文字の座標
	CVector3D m_cpos2;		//complete文字の座標
	//CMapControl m_Mcnt;
	int m_gameclear_img[2];
	int m_count1;
	int m_bgm;
};
#endif __SCREEN_GAME_H__