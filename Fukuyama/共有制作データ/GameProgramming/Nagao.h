#ifndef NAGAO_H
#define NAGAO_H
#include "object\CManhole.h"
class Nagao : public C_Manhole{
public:
	//描画処理
	void Draw();
	void Update();
	C_Manhole* Manhole;
	//テスト用コンストラクタを作成
	Nagao();
private:
};
#endif