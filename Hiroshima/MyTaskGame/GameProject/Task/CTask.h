/**
* @file		CTask.h
* @brief	タスクシステム元クラス
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include "CTaskLinker.h"


//更新順序
enum E_UpdatePrio
{
	eUDP_Tutorial,
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Gimmick,
	eUDP_Map,
	eUDP_Null,
};
//描画順序
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_MapObject01,
	eDWP_Gimmick,
	eDWP_Player,
	eDWP_Enemy,
	eDWP_Tutorial,
	eDWP_MapObject02,
	eDWP_Null,
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
	virtual ~CTask();				//CTaskクラスのデストラクタ
	virtual void Update();			//派生先クラスでの更新を行う関数
	virtual void Draw();			//派生先クラスでの描写を行う関数

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