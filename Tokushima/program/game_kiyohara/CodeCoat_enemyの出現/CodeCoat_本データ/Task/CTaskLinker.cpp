#include "CTaskLinker.h"
#include "CTaskManager.h"



// コンストラクタ 
CTaskLinker::CTaskLinker()
	:	m_priority(0)
	,	mp_prev(nullptr)
	,	mp_next(nullptr)
	,	mp_task(nullptr)
{
}

// コンストラクタ 
CTaskLinker::CTaskLinker(int priority,CTask *task)
	:	m_priority(priority)
	,	mp_prev(nullptr)
	,	mp_next(nullptr)
	,	mp_task(task)
{
}


// デストラクタ 
CTaskLinker::~CTaskLinker()
{
}

// 優先度設定 
void	CTaskLinker::SetPriority( int prio )
{
	m_priority = prio;
}

// 優先度取得 
int		CTaskLinker::GetPriority() const
{
	return m_priority;
}
