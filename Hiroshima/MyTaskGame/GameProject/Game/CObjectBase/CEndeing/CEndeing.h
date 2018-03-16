#ifndef ENDEING_GUARD
#define ENDEING_GUARD

#include "../CObjectBase.h"

#define ENDEING_SIZ_X 1000
#define ENDEING_SIZ_Y 5859

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
private:
	bool m_end_flag;	//終わりますよフラグ
	float m_vol;

};

#endif // !ENDEING_GUARD
