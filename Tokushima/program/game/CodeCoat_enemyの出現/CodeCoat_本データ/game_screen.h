#ifndef __SCREEN_GAME_H__
#define __SCRENE_GAME_H__

//ヘッダーファイル
#include "myLib.h"
#include "Scene\SceneBase.h"
#include "map.h"
#include "player.h"
#include "timer.h"
#include "item.h"

//プロトタイプ
struct GameData;

//タイトルスクリーンクラス
class CGameScreen : public CSceneBase
{
public:
	CGameScreen();
	~CGameScreen();
	SCREEN GetNextScreen();
	void Load();
	void Init();
	void Update();
	void Draw();
	void Dest();
private:
	SCREEN m_state;
	//CMapControl m_Mcnt;
	CPlayerControl m_Pcnt;
	CTimeData m_Tcnt;
	//CIdata m_Icnt;
	int m_bgm;
};
#endif __SCREEN_GAME_H__