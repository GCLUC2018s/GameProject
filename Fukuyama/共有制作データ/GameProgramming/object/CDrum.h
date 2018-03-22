#ifndef CDRUM_H
#define CDRUM_H
#include "../draw/CRectangle.h"
#include "C_Object.h"

class C_Drum : public  C_Object{
private:
	int m_DrumPos_Random = rand() % 3;
	void Dmain();
	void Drum_Rect(C_Rectangle* image, const C_Vector3* pos);  //ポジションの場所にC_Rectangle表示(ドラム専用)
public:
	//更新処理
	void Update();

	//描画処理
	void Draw();

	//コンストラクタを設定
	C_Drum();

	//衝突判定
	bool Collision(CTask*, CTask*);
};

#endif