#ifndef CBACKGROUND_H
#define CBACKGROUND_H
#include "object\C_Object.h"

//背景クラス
class C_BackGround : public C_Object{
public:
	//コンストラクタを設定
	C_BackGround();
	//更新処理
	void Update();
	//描画処理
	void Draw();
};

//雲クラス
class C_Cloud : public C_Object{
public:
	//コンストラクタを設定
	C_Cloud();
	//更新処理
	void Update();
	//描画処理
	void Draw();
};
#endif