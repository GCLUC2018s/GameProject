#ifndef SCREEN_H
#define SCREEN_H

//ゲームスクリーンの種類
enum SCREEN{
	TITLE_SCREEN,
	OPTION_SCREEN,
	GAME_SCREEN,
	GAMECLEAR_SCREEN,
	GAMEOVER_SCREEN,
};

class CScreen
{
public:
	virtual SCREEN GetNextScreen() = 0;		//次のスクリーンを示す
	virtual void Init(){}
	virtual void Load(){}
	virtual void Release(){}
	virtual void Update(){}
	virtual void Draw(){}
	virtual void Dest(){}
};

#endif SCREEN_H