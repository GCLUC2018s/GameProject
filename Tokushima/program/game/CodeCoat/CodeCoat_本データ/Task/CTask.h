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
	eUDP_Tutorial = 0,
	eUDP_Npc,
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Item,
	eUDP_Map,
	eUDP_Bullet,
	eUDP_Null,
	eUDP_Ui,
	eUDP_Rank,
};
//描画順序
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_Npc,
	eDWP_Enemy,
	eDWP_BBullet,
	eDWP_BItem,
	eDWP_Player,
	eDWP_FEnemy,
	eDWP_Bullet,
	eDWP_Item,
	eDWP_Tutorial,
	eDWP_Null,
	eDWP_Ui,
	eDWP_Rank
};

class CTask
{
private:
	
protected:
	bool m_destroyFlg;				//削除フラグ
	bool m_pauseFlg;				//更新停止フラグ
	int m_id;

	CTaskLinker		m_updLinker;		// Update用のCTaskLinker 
	CTaskLinker		m_drwLinker;		// Draw用のCTaskLinker 
	CTask();
public:
					//CTaskクラスのコンストラクタ
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
	friend class CPlayerManager;
	friend class CItemManager;
	friend class CBulletManager;
	friend class CMapManager;
};

#endif