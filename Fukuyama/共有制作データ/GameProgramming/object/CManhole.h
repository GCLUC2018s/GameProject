#ifndef CMANHOLE_H
#define CMANHOLE_H
#include "../draw/CRectangle.h"
#include "random"
#include "stdio.h"
#include "time.h"

class C_Manhole : public C_Rectangle{
protected:
	//ランダム発生確率
	int m_UorD_rand=rand()%2;
	//マンホール左右ポジション
	float m_PotisionX(float m_H);

	//マンホール上下ポジション
	float m_PotisionY(float m_V);

public:
	//コンストラクタを設定
	C_Manhole();

	//更新処理
	void Update();

	//描画処理
	virtual void Draw();
};

#endif