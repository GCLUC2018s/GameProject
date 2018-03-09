#include "CTask.h"
#include "CTaskManager.h"
#include "CTask.h"

CTask::CTask()
{
	m_kill = false;
	m_next = nullptr;
	m_prev = nullptr;
	CTaskManager::m_instance->Add(this);
}

void CTask::Update() {
	printf("Task\n");

}
void CTask::Swap(CTask * t1, CTask * t2)
{
	CTask* w;
	w = t1;
	t1 = t2;
	t2 = w;
}


void CTask::HitCheck(CTask * t1, CTask * t2)
{
	if (t1->m_num == 2 && t2->m_num == 5) {
		Swap(t1, t2);
	}
}
