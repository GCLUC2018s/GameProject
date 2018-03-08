#ifndef BASE_GUARD
#define BASE_GUARD

#include "../stdafx.h"
#include "../Global.h"
#include "../ImageResource.h"
#include <list>

/*
ゲーム内のオブジェクトの
基本クラス
*/

enum {
	eTagPlayer,
	eTagEnemy,
	eTagUI,
};

class CBase {
protected:
	CAnimImage	m_img;		//画像オブジェクト
	CVector2D	m_pos;		//座標
	CVector2D	m_vec;		//移動量
	CRect	m_rect;			//当たり判定用短形
	bool	m_flipH;		//反転フラグ
	bool	m_active;		//生存フラグ
	int		m_cnt;			//時間
	int		m_state;
	bool	m_move;
	bool	m_squat;
	int		m_type;
	float	m_color;		//色
	static CVector2D m_scroll;


public:
	CBase(int tag);
	virtual ~CBase();
	//更新命令
	virtual void Update();
	//描画命令
	virtual void Draw();
	//生存フラグの取得
	bool GetActive() {
		return m_active;
	}

	//生存フラグの設定
	void SetActive(bool f) {
		m_active = f;
	}
	CVector2D GetPos() {
		return m_pos;
	}

	//当たったときに呼ばれる関数
	virtual void HitCallback(CBase* b);

	/*!
	@brief	値を指定値まで、指定値分上昇させる
	@param	v_Price_UF	[in] 初期値
	@param	v_Price_UE	[in] 最大値
	@param	a			[in] 増値
	@retval	結果
	**/
	float CBase::Price_Up(float v_Price_UF, float v_Price_UE, float a)
	{
		if (v_Price_UF < v_Price_UE)
			v_Price_UF += a;
		else v_Price_UF = v_Price_UE;

		return v_Price_UF;
	}
	/*!
	@brief	値を指定値まで、指定値分下降させる
	@param	v_Price_DF	[in] 初期値
	@param	v_Price_DE	[in] 最小値
	@param	a			[in] 減値
	@retval	結果
	**/
	float CBase::Price_Down(float v_Price_DF, float v_Price_DE, float a)
	{
		if (v_Price_DF > v_Price_DE)
			v_Price_DF -= a;
		else v_Price_DF = v_Price_DE;

		return v_Price_DF;
	}

};

extern std::list<CBase*> g_list;

#endif // !BASE_GUARD