#ifndef ENDEING_GUARD
#define ENDEING_GUARD

#include "../CObjectBase.h"

#define ENDEING_SIZ_X 1000
#define ENDEING_SIZ_Y 6394

/*

制作者　宮﨑

*/
class CEnding : public CObjectBase
{
public:
	//タイトル画像
	CEnding();
	~CEnding();
	void Update();
	void Draw();
private:
	bool m_end_flag;	//終わりますよフラグ
	CFont font;
	int m_time;			//経過時間
	int m_taxt;			//表示場所
	bool m_ac;			//フェードタイミング　trueならプラス
};

#endif // !ENDEING_GUARD
