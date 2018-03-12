#include "CTask.h"
#include "CTaskManager.h"


CTask::CTask()
{
	m_death_flag = false;
	m_pause_flag = false;
	mp_Upd_next = nullptr;
	mp_Upd_prev = nullptr;
	mp_Drw_next = nullptr;
	mp_Drw_prev = nullptr;
	CTaskManager::GetInstance()->Add(this);
}

CTask::~CTask()
{
}

void CTask::Update()
{
}

void CTask::Draw()
{
}

int CTask::GetUpdatePrio() const
{
	return 0;
}

int CTask::GetDrawPrio() const
{
	return 0;
}

void CTask::ChangeUpdatePrio(int updatePrio)
{
}

void CTask::ChangeDrawPriority(int drawPrio)
{
}
