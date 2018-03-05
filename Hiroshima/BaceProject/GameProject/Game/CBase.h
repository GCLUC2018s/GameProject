#pragma once
#include "../stdafx.h"
#include "../imageResource.h"
#include <list>

#define MASK_PLAYER		1
#define MASK_ENEMY		2
#define MASK_BULLET_P	4
#define MASK_BULLET_E	8

/*
	ゲーム内のオブジェクトの
	基本クラス
*/

enum {
	eTagPlayer,
	eTagEnemy,
	eTagBullet,
	eTagEffect,
	eTagSlash,
	eTagBomb,
	eTagBlood,
	eTagShotHit,
	eTagSmoke,
	eTagItem,
	eTagMap,
	eTagUI
};

class CBase {
protected:
	CAnimImage	m_img;		//画像オブジェクト
	CVector2D	m_pos;		//座標
	CVector2D	m_old_pos;	//座標	
	CVector2D	m_vec;		//移動量
	CRect	m_rect;			//当たり判定用短形
	bool	m_flipH;		//反転フラグ
	bool	m_active;		//生存フラグ
	int		m_body;			//衝突マスク
	int		m_mask;			//衝突マスク
	int		m_tag;			//オブジェクトの種類
	static CVector2D m_scroll;

public:
	CBase(int tag);
	virtual ~CBase();
	//更新命令
	virtual void Update();
	//描画命令
	virtual void Draw();
	//生存フラグの取得
	bool GetActive(){
		return m_active;
	}

	int GetTag() {
		return m_tag;
	}

	//オブジェクトどうしの当たり判定
	static void HitCheck(CBase* b1, CBase* b2);
	//当たったときに呼ばれる関数
	virtual void HitCallback(CBase* b);

	//マップとの衝突
	int WallCheck(int *bx = nullptr);
	int FloorCheck(int *by = nullptr);

};

extern std::list<CBase*> g_list;