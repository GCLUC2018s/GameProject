#include "CTaskLinker.h"
#include "CTaskManager.h"



// �R���X�g���N�^ 
CTaskLinker::CTaskLinker()
	:	m_priority(0)
	,	mp_prev(nullptr)
	,	mp_next(nullptr)
	,	mp_task(nullptr)
{
}

// �R���X�g���N�^ 
CTaskLinker::CTaskLinker(int priority,CTask *task)
	:	m_priority(priority)
	,	mp_prev(nullptr)
	,	mp_next(nullptr)
	,	mp_task(task)
{
}


// �f�X�g���N�^ 
CTaskLinker::~CTaskLinker()
{
}

// �D��x�ݒ� 
void	CTaskLinker::SetPriority( int prio )
{
	m_priority = prio;
}

// �D��x�擾 
int		CTaskLinker::GetPriority() const
{
	return m_priority;
}
