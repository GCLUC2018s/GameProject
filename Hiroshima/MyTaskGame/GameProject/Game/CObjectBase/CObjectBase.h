#ifndef CHARABASE_GUARD
#define CHARABASE_GUARD

#define GRAVITY 1.2f

#include "../GameProject/Task/CTask.h"
#include "../GameProject/Task/CTaskManager.h"
#include "../GameProject/stdafx.h"
#include "../GameProject/ImageResource.h"

/*

製作　宮﨑

*/


class CObjectBase : public CTask
{
protected:
	CAnimImage	m_img;		//画像オブジェクト
	CVector2D	m_pos2D;		//座標
	CVector2D	m_vec2D;		//移動量
	CVector3D	m_pos3D;		//座標
	CVector3D	m_vec3D;		//移動量
	CRect	m_rect_F;		//入れ替え判定用短形
	CRect	m_rect;			//当たり判定用短形
	bool	m_flipH;		//反転フラグ
	bool	m_move;
	int		m_type;	
	static CVector2D m_scroll;	//スクロール値
	static bool m_wave_flag;	//今wave中ならtrue。敵全滅させたらfalseにして、スクロール開始
	static 	bool m_sc_flag_x;	//プレイヤーが動いたことによるスクロールフラグ。trueならプレイヤーの動きは止まる
	int m_hp;  //体力
	int m_at;  //攻撃力
	int m_state; //状態
	CColorRGBA m_color;	//色
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
	//座標取得
	CVector3D GetPos() {
		return m_pos3D;
	};
	//ベクトル取得
	CVector3D GetVec() {
		return m_vec3D;
	};
	//ベクトルセット
	void SetVec(CVector3D &vec) {
		m_vec3D = vec;
	};
	//矩形取得
	CRect GetRect() {
		return m_rect;
	};
	////入れ替え用矩形取得
	//CRect *GetRect_F() {
	//	return &m_rect_F;
	//};

	//重なり確認
	void CheckOverlap() {
		if(m_pos3D.z <= 0){
			CTaskManager::GetInstance()->ChangeDrawPrio(this, SCREEN_HEIGHT + m_pos3D.z);
		}
	};
	//状態確認
	int GetState() {
		return m_state;
	};
	//スクロール値を取得

	////描画順位入れ替え
	//void SwapDrawPriority(CObjectBase *t);

	////描画順序チェック関数
	//void CheckOverlapAll();
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
	//描画命令
	virtual void Draw();
	//当たり判定
	void HitCheck(CTask * t1, CTask * t2);
	//当たった時の処理
	virtual void Hit(CObjectBase *t);
	////重なり確認
	//void CheckOverlap(CObjectBase *t1, CObjectBase *t2);
};


#endif // !CHARABASE_GUARD
