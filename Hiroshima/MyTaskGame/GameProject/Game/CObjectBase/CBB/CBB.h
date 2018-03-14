#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

/*

制作者　宮﨑
呼び出したら、画面が暗くなって、エンターキーを押したら消えるクラス

*/
class CBB : public CObjectBase
{
public:
	CBB(const int time);
	~CBB();
	void Update();
private:
	int m_cnt;	//50％カウント
	int m_time;	//50％待機時間（引数で指定）
};
#endif // !BB_GUARD
