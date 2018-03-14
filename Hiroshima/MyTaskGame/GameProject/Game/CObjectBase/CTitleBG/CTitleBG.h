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
	void Draw();
private:
	bool m_end_flag;	//エンター押されたので終わりますよフラグ
	CAnimImage m_img_pika;
	bool m_pika_flag;	//falseならぴかが消える。trueならぴかが出る
};

#endif // !TITLE_BG_GUARD
