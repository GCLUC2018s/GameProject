#pragma once
#include "../stdafx.h"
#include "../Global.h"
#include <list>

/*
ゲーム内のオブジェクトの
基本クラス
*/

enum {
	eTagPlayer,
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
	int		m_type;
	int		m_changeanim_num;//アニメーションナンバー
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
	//アニメーションナンバーを取得
	int GetAnimNum() {
		return m_changeanim_num;
	}

	//当たったときに呼ばれる関数
	virtual void HitCallback(CBase* b);


};

extern std::list<CBase*> g_list;
