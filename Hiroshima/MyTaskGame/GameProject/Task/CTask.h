#ifndef TASK_GUARD
#define TASK_GUARD

#include "../Global.h"
#include "CTaskLinker.h"

class CObjectBase;

//更新順序
enum {
	eU_System,
	eU_Player,
	eU_Enemy,
	eU_Gimmick,
	eU_Item,
	eU_UI,
	eU_Effect,
	eU_Map,
	eU_Back,
	eU_Scene,
	eU_Null,
};
//描画順序
enum {
	eD_Back,
	eD_Cloud,
	eD_Bamboo,
	eD_Ground,
	eD_Object,
	eD_Effect,
	eD_UI,
	eD_Null,
};
//ID
enum {
	eID_UI,
	eID_Player,
	eID_Enemy,
	eID_Item,
	eID_Gimmick,
	eID_Flag,
	eID_Magatama,
	eID_Null,
};

class CTask
{
protected:
	bool m_destroy;	//trueなら、このタスクは削除される
	bool m_pause;	//trueなら更新停止
	int m_id;		//基本0

	CTaskLinker m_UPD_link;		// Update用のCTaskLinker 
	CTaskLinker m_DRW_link;		// Draw用のCTaskLinker 
public:
	CTask();	//デフォルトコンストラクタ。使わないけどいるらしい
	/*
	１番目の引数「id」は、基本0
	２番目の引数「UPD_prio」は、更新順位。enumで作ってる
	３番目の引数「DRW_prio」は、描画順位。enumで作ってる
	*/
	CTask(int id,int UPD_prio,int DRW_prio);
	virtual ~CTask();
	virtual void Update();
	virtual void Draw();
	virtual void HitCheck(CTask *t1, CTask *t2);
	virtual void Hit(CObjectBase *t);


	//更新順位取得関数
	int GetUpdatePrio() const;
	//描画順位取得関数
	int GetDrawPrio() const;
	//ID取得関数
	int GetID() const {
		return m_id;
	};

	//更新順位変更
	void ChangeUpdatePrio(int updatePrio);
	//描画順位変更
	void ChangeDrawPriority(int drawPrio);

	// 削除フラグを立てる 
	void SetKill()
	{
		m_destroy = true;
	}
	friend class CTaskManager;


};

#endif // !TASK_GUARD
