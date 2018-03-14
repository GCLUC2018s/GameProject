#ifndef CDRUM_H
#define CDRUM_H
#include "../draw/CRectangle.h"
#include "C_Object.h"

class C_Drum : public  C_Object{
private:
	int m_DrumPos_Random = rand() % 3;
public:
	//更新処理
	void Update();

	//描画処理
	void Draw();

	//コンストラクタを設定
	C_Drum();
};

#endif