#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

#define BB_COL_PA 0.6 //どの濃さで止めるか。
#define BB_COL_DOWN 0.05 //どれくらいずつ減らすか
#define BB_COL_DOWN_2 0.01 //どれくらいずつ減らすか2
/*

制作者　宮�ｱ

*/
class CBB : public CObjectBase
{
public:
	//呼び出したらフェードアウトインする
	//表示秒数（その間、プレイヤーは操作不能）
	//1なら「敵を倒せ！」表示
	//2なら、Bossに移動
	//3なら、コンティニュー
	//trueなら、だんだん黒くなる
	CBB(const int &time, const int &flag, const bool &flagin);
	~CBB();
	void Update();
	void Draw();
private:
	int m_cnt;	//50％カウント
	int m_time;	//50％待機時間（引数で指定）
	//1なら、「敵を倒せ！」表示
	//2なら、Bossに移動
	//3なら、コンティニュー
	int m_flag; 
	bool m_in_flag; //trueなら、だんだん黒くなる
	CFont m_contn;	//コンティニュー表記
};
#endif // !BB_GUARD
