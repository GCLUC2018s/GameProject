#ifndef C_SCORE_H
#define C_SCORE_H
#include "object\C_Object.h"
#include "CCollider.h"
class C_Score{
public:
	void DrawString(int s[], float lef, float bot, float size);
	//コンストラクタを設定
	C_Score();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//スコア加減算整数
	static int Score;
	//Texture貼り付け
	CTexture ScoreTexture;
	//Collision判定
	bool Collision(CTask*, CTask*);
};
#endif