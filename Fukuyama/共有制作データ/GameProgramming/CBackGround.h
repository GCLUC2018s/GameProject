#ifndef CBACKGROUND_H
#define CBACKGROUND_H
#include "object\C_Object.h"

class C_BackGround : public C_Object{
public:
	//コンストラクタを設定
	C_BackGround();
	//更新処理
	void Update();
	//描画処理
	void Draw();
};

class C_BackGround2 : public C_Object{
public:
	//コンストラクタを設定
	C_BackGround2();
	//更新処理
	void Update();
	//描画処理
	void Draw();
};
#endif