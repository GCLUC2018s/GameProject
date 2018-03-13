#ifndef NAGAO_H
#define NAGAO_H
#include "object\CManhole.h"
class Nagao : public C_Manhole{
public:
	C_Manhole* Manhole;
	//テスト用コンストラクタを作成
	Nagao();
private:
};
#endif