#ifndef PUSH_START_BG_GUARD
#define PUSH_START_BG_GUARD

#include "../CObjectBase.h"

/*

制作者　宮﨑

*/
class CPushStart : public CObjectBase
{
public:
	//PushStart画像
	CPushStart();
	~CPushStart();
	void Update();
	void SetEnd() {
		m_end_flag = true;
	}
private:
	bool m_end_flag;	//終わりますよフラグ
};

#endif // !TITLE_BG_GUARD