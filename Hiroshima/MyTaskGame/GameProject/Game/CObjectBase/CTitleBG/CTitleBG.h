#ifndef TITLE_BG_GUARD
#define TITLE_BG_GUARD

#include "../CObjectBase.h"

/*

制作者　宮﨑

*/
class CTitleBG : public CObjectBase
{
public:
	//タイトル画像
	CTitleBG();
	~CTitleBG();
	void Update();
private:
	bool m_end_flag;	//エンター押されたので終わりますよフラグ
};

#endif // !TITLE_BG_GUARD
