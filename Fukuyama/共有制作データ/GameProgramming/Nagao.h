#ifndef NAGAO_H
#define NAGAO_H
#include "object\CManhole.h"
class Nagao{
public:
	//テスト用コンストラクタを作成
	Nagao(){
		Manhole = new C_Manhole();
	}
	C_Manhole* Manhole;
private:
};
#endif