#ifndef CMANHOLE_H
#define CMANHOLE_H
#include "CRectangle.h"
#include "random"
#include "CMain.h"
#include "CKey.h"
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
	//空コンストラクタを設定
	C_Manhole();

	//更新処理
	void Update();

	//描画処理
	void Draw();
};

#endif