#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

#define BB_COL_PA 0.7 //どの濃さで止めるか。
#define BB_COL_DOWN 0.02 //どれくらいずつ減らすか
/*

制作者　宮﨑

*/
class CBB : public CObjectBase
{
public:
	//呼び出したら、画面が暗くなって、しばらくたったら消えるクラス
	//表示秒数（その間、プレイヤーは操作不能）,	trueなら「敵を倒せ！」表示,trueならフェードイン
	CBB(const int time,const bool flag,const bool in_flag);
	~CBB();
	void Update();
	void Draw();
private:
	int m_cnt;	//50％カウント
	int m_time;	//50％待機時間（引数で指定）
	bool m_flag; //trueなら、「敵を倒せ！」表示
	bool m_in_flag; //trueならフェードイン
};
#endif // !BB_GUARD
