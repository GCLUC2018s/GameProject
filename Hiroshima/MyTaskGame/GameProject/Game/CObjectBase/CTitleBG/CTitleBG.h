#ifndef TITLE_BG_GUARD
#define TITLE_BG_GUARD

#define ROGO_SIZ_X 485
#define ROGO_SIZ_Y 735

#define START_SIZ_X 350
#define START_SIZ_Y 100

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
	CAnimImage m_img_start;		//スタート画像
	CAnimImage m_img_start_2;		//スタート画像
	CAnimImage m_img_huda;		//お札

	CColorRGBA m_col_rogo;			//ロゴ画像カラー
	CColorRGBA m_col_rogo_s;		//ロゴ画像差分カラー
	CColorRGBA m_col_start;			//スタート画像カラー
	CColorRGBA m_col_start_2;			//スタート画像カラー

	CVector2D m_st_siz;
	CVector2D m_logo_siz;

	bool m_end_flag;			//本当に終わりますよフラグ
	bool m_sabun_flag;			//falseなら差分が消える。trueなら差分が出る
	float m_f_time;					//(フェードアウト量参考)
	int   m_time;					//エンターキーを押してからの時間(フェードアウト量参考)

	int m_log_time;		//ロゴがバーンってなる時間
	float m_ohuda_time;	//お札回転用

	void RogoUpdate();			//ロゴ画像本体のアップデート
	void PushStartUpdate();		//PushStart画像本体のアップデート
	void FadeIn(float *a);				//フェードイン
	void FadeOut(float *a);				//フェードアウト

};

#endif // !TITLE_BG_GUARD
