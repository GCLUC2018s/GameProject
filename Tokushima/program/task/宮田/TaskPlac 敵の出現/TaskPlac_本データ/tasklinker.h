/**
* @file		CTaskLinker.h
* @brief	タスクシステムのリストを形成するためのポインタクラス
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_LINKER_GUARD
#define TASK_LINKER_GUARD

class CTask;

class CTaskLinker
{
	friend class CTaskManager;

private:
	int			m_priority;			// 優先度 
	CTaskLinker	*mp_prev;			// 前のポインタ
	CTaskLinker	*mp_next;			// 次のポインタ
	CTask		*mp_task;			// 自身 

public:
	// コンストラクタ 
	CTaskLinker();
	// コンストラクタ 
	CTaskLinker(int priority, CTask *task);

	// デストラクタ 
	~CTaskLinker();

	// 優先度設定 
	void	SetPriority(int prio);
	// 優先度取得 
	int		GetPriority() const;

};

#endif