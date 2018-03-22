/**
* @file		CTask.h
* @brief	タスクシステム元クラス
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include "CTaskLinker.h"
#include "windows.h"

#define ICON_SIZE 90          //アイコンの一辺の長さ

//ID
enum E_ID
{
	E_PLAYER,
	E_ENEMY,
	E_ATACK,
	E_BG,
	E_OBJ,
	E_UI,
	E_SCROLL,
};
//更新順序
enum E_UpdatePrio
{
	eUDP_Tutorial,
	eUDP_Player,
	eUDP_Object,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Map,
	eUDP_Null,
};
//描画順序
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_Object,
	eDWP_Player,
	eDWP_Enemy,
	eDWP_Tutorial,
	eDWP_Null,
};

class CTask
{
protected:
	bool m_destroyFlg;				//削除フラグ
	bool m_pauseFlg;				//更新停止フラグ

	CTaskLinker		m_updLinker;		// Update用のCTaskLinker 
	CTaskLinker		m_drwLinker;		// Draw用のCTaskLinker 

public:
	CTask();						//CTaskクラスのコンストラクタ
	CTask(int id, int updateprio, int drawPrio);
	virtual ~CTask();				//CTaskクラスのデストラクタ
	virtual void Update();			//派生先クラスでの更新を行う関数
	virtual void Draw();			//派生先クラスでの描写を行う関数
	virtual bool Collision(CTask*, CTask*){
		return false;
	}
	int m_id;

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