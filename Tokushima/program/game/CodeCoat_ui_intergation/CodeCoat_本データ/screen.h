#ifndef __SCREEN_H__
#define __SCREEN_H__

extern int g_stage;

//ゲームスクリーンの種類
enum SCREEN{
	TITLE_SCREEN,
	SELECT_SCREEN,
	GAME_SCREEN,
	GAMECLEAR_SCREEN,
	GAMEOVER_SCREEN,
	GAMESCORE_SCREEN,
	GAMENEXT_SCREEN
};

//このenumを使っている列挙体
//now_screen old_screen CSelectScreen.m_state GetNextScreen()


class CScreen
{
public:
	virtual SCREEN GetNextScreen() = 0;
	CScreen(){}
	virtual ~CScreen(){}
	virtual void Init(){}
	virtual void Load(){}
	virtual void Release(){}
	virtual void Update(){}
	virtual void Draw(){}
	virtual void Dest(){}
};

#endif __SCREEN_H__
	