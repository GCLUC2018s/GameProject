#ifndef CDRUM_H
#define CDRUM_H
#include "CManhole.h"

class C_Drum : public C_Manhole{
public:
	//更新処理
	void Update();

	//描画処理
	void Draw();

	//コンストラクタを設定
	C_Drum();
};

#endif