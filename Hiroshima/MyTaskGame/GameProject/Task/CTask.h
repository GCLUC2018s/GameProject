#ifndef TASK_GUARD
#define TASK_GUARD

#include "../Global.h"

//更新順序
enum E_UpdatePrio
{
	eUDP_Tutorial,
	eUDP_Gimmick,
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Item,
	eUDP_Map,
	eUDP_Null,
};
//描画順序
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_Gimmick,
	eDWP_Player,
	eDWP_Enemy,
	eDWP_Item,
	eDWP_Tutorial,
	eDWP_Null,
};

class CTask
{
protected:
	bool m_death_flag;				//削除フラグ
	bool m_pause_flag;				//更新停止フラグ
	//int m_id;

public:
	CTask(/*int id, int updateprio, int drawPrio*/);//CTaskクラスのコンストラクタ
	virtual ~CTask();				//CTaskクラスのデストラクタ
	virtual void Update();			//派生先クラスでの更新を行う関数
	virtual void Draw();			//派生先クラスでの描写を行う関数
	CTask*		mp_Upd_next;		// Update用のnext
	CTask*		mp_Upd_prev;		// Update用のprev
	CTask*		mp_Drw_next;		// Draw用のnext 
	CTask*		mp_Drw_prev;		// Draw用のprev

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
		m_death_flag = true;
	}
	friend class CTaskManager;
};


#endif // !TASK_GUARD
