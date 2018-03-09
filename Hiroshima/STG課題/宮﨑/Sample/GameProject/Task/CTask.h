/**
* @file		CTask.h
* @brief	タスクシステム元クラス
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include "CTaskLinker.h"
#include "CAnimImage.h"
#include "../Global.h"


//更新順序
enum E_UpdatePrio
{
	eUDP_Tutorial,
	eUDP_Bullet,
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Map,
	eUDP_Null,
};
//描画順序
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_Bullet,
	eDWP_Player,
	eDWP_Enemy,
	eDWP_Tutorial,
	eDWP_Null,
};
//ID
enum E_IDPrio
{
	eID_Map,
	eID_Bullet,
	eID_Player,
	eID_Enemy,
	eID_Tutorial,
	eID_Null,
};


class CTask
{
protected:
	bool m_destroyFlg;				//削除フラグ
	bool m_pauseFlg;				//更新停止フラグ
	int m_id;

	CTaskLinker		m_updLinker;		// Update用のCTaskLinker 
	CTaskLinker		m_drwLinker;		// Draw用のCTaskLinker 

public:
	CTask();						//CTaskクラスのコンストラクタ
	CTask(int id, int updateprio, int drawPrio);
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_old_pos;
	CVector2D m_vec;
	CRect m_rect;
	CRect m_BG_rect = CRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	bool m_activ;
	virtual ~CTask();				//CTaskクラスのデストラクタ
	virtual void Update();			//派生先クラスでの更新を行う関数
	virtual void Draw();			//派生先クラスでの描写を行う関数

	//当たり判定
	void Hit() {
	}

	//更新順位取得関数
	int GetUpdatePrio() const;
	//描画順位取得関数
	int GetDrawPrio() const;
	//更新順位変更
	void ChangeUpdatePrio(int updatePrio);
	//描画順位変更
	void ChangeDrawPriority(int drawPrio);

	// 削除フラグを立てる 
	void SetKill() 
	{
		m_destroyFlg = true;
	}
	friend class CTaskManager;
};

#endif