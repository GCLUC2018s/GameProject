#ifndef CHARABASE_GUARD
#define CHARABASE_GUARD

#include "../GameProject/Task/CTask.h"
#include "../GameProject/stdafx.h"

class CObjectBase : public CTask
{
protected:
	CAnimImage	m_img;		//画像オブジェクト
	CVector2D	m_pos2D;		//座標
	CVector2D	m_vec2D;		//移動量
	CVector3D	m_pos3D;		//座標
	CVector3D	m_vec3D;		//移動量
	CRect	m_rect;			//当たり判定用短形
	bool	m_flipH;		//反転フラグ
	bool	m_move;
	int		m_type;
	float	m_color;		//色
	static CVector2D m_scroll;
	int m_hp;  //体力
	int m_at;  //攻撃力
	int m_state; //状態
	//状態
	enum {
		eIdol,			//待機
		eAttack,		//攻撃
		eKnockBack,    //ノックバック
		eFall,			//倒れる
		eMove,         //移動
	};
public:
	CObjectBase(int id, int updatePrio, int drawPrio);
	//~CCharaBase();

	/*!
	@brief	値を指定値まで、指定値分上昇させる
	@param	v_Price_UF	[in] 初期値
	@param	v_Price_UE	[in] 最大値
	@param	a			[in] 増値
	@retval	結果
	**/
	float Price_Up(float v_Price_UF, float v_Price_UE, float a)
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
	float Price_Down(float v_Price_DF, float v_Price_DE, float a)
	{
		if (v_Price_DF > v_Price_DE)
			v_Price_DF -= a;
		else v_Price_DF = v_Price_DE;

		return v_Price_DF;
	}

private:
	//描画命令
	virtual void Draw();
};


#endif // !CHARABASE_GUARD
