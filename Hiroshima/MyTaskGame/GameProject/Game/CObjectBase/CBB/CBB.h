#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

/*

制作者　宮﨑

*/
class CBB : public CObjectBase
{
public:
	//呼び出したらフェードアウトインする
	//表示秒数（その間、プレイヤーは操作不能）,	trueなら「敵を倒せ！」表示,trueなら、だんだん黒くなる
	CBB(const int time, const int flag, const bool flagin);
	~CBB();
	void Update();
	void Draw();
private:
	int m_cnt;	//50％カウント
	int m_time;	//50％待機時間（引数で指定）
	//1なら、「敵を倒せ！」表示
	//2なら、Bossに移動
	int m_flag; 
	bool m_flag_In; //trueなら、だんだん黒くなる
};
#endif // !BB_GUARD
