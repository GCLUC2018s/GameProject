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
	CAnimImage m_img_rogo;		//ロゴ画像
	CAnimImage m_img_rogo_s;	//ロゴ画像差分
	CAnimImage m_img_start;	//ロゴ画像差分
	bool m_end_flag;			//エンター押されたので終わりますよフラグ
	bool m_pika_flag;			//falseならぴかが消える。trueならぴかが出る
	void BGUpdate();			//タイトル画像本体のアップデート
	void RogoUpdate();			//ロゴ画像本体のアップデート
	void PushStartUpdate();		//PushStart画像本体のアップデート

};

#endif // !TITLE_BG_GUARD
