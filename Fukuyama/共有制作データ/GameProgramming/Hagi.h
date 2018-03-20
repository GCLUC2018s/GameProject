#ifndef HAGI_H
#define HAGI_H
#include"task/CTask.h"
#include "chara/C_Player.h"
#include "task/CTaskManager.h"
#include "draw/CRectangle.h"

#define ICON_SIZE 90          //アイコンの一辺の長さ

class Hagi:public CTask{
public:
	Hagi()
	{
		//プレイヤーのインスタンスを作成
		Player = new C_Player();
		Test = new C_Test();
		i_iconShadow.SetVertex(-585, -495, -435, -345);
		i_Icon.SetVertex(-585, -495, -435, -345);
		Icon.Load("image/under/under_spray_icon.tga");
	}
protected:
	C_Test *Test;
	C_Player *Player;
	C_Rectangle i_iconShadow;
	C_Rectangle i_Icon;   //スプレーのアイコン
	CTexture Icon;      //スプレーアイコンのテクスチャー

	void Update();
	void Draw();
};
#endif