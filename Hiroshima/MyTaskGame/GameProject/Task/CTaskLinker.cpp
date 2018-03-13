#include "CTaskLinker.h"
#include "CTask.h"

CTaskLinker::CTaskLinker() :
	m_priority(0),
	mp_prev(nullptr),
	mp_next(nullptr),
	mp_task(nullptr)
{
	//“Á‚É‚È‚µ
}

CTaskLinker::CTaskLinker(int prio, CTask * task):
	m_priority(prio),
	mp_prev(nullptr),
	mp_next(nullptr),
	mp_task(task)
{
}

CTaskLinker::~CTaskLinker()
{
}

void CTaskLinker::SetPriority(int prio)
{
	m_priority = prio;
}

int CTaskLinker::GetPriority() const
{
	return m_priority;
}
