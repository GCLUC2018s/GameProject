#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

/*

制作者　宮﨑

*/
class CBB : public CObjectBase
{
public:
	//呼び出したら、画面が暗くなって、エンターキーを押したら消えるクラス
	//表示秒数（その間、プレイヤーは操作不能）,	trueなら「敵を倒せ！」表示
	CBB(const int time,const bool flag);
	~CBB();
	void Update();
private:
	int m_cnt;	//50％カウント
	int m_time;	//50％待機時間（引数で指定）
//	bool m_flag; //trueなら、「敵を倒せ！」表示
};
#endif // !BB_GUARD
