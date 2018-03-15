#ifndef CMANHOLE_H
#define CMANHOLE_H
#include "C_Object.h"

class C_Manhole : public C_Object{
private:
	//ランダム発生確率
	int m_UorD_rand = rand() % 3;
public:
	//コンストラクタを設定
	C_Manhole();

	//更新処理
	void Update();

	//描画処理
	virtual void Draw();
};

#endif