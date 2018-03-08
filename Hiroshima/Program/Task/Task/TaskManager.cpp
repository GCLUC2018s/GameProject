#include "TaskManager.h"
#include "Task.h"

TaskManager* TaskManager::m_instance = nullptr;
TaskManager::TaskManager()
{
	m_TOP = nullptr;
	m_END = nullptr;
}

void TaskManager::Update()
{
	m_NOW = m_TOP;
	while (m_NOW != nullptr)
	{
		m_NOW->Update();
		if (m_NOW->GetKill()) {
			Delete(m_NOW);
		}
		m_NOW = m_NOW->m_next;
	}
	getchar();
}

void TaskManager::Add(Task* t)
{
	if (m_TOP == nullptr) {
		m_TOP = t;
		m_END = t;
	}
	else {
		t->m_prev = m_END;
		m_END->m_next = t;
		m_END = t;
	}
}

void TaskManager::Delete(Task* t)
{
	m_NOW = m_NOW->m_prev;
	t->m_prev->m_next = t->m_next;
	t->m_next->m_prev = t->m_prev;
	delete t;
}

void TaskManager::Swap(Task* t1, Task* t2)
{
	Task* w;
	w = t1;
	t1 = t2;
	t2 = w;

	/*
	t1->m_prev->m_next = t2;
	t1->m_next->m_prev = t2;
	t2->m_prev->m_next = t1;
	t2->m_next->m_prev = t1;*/
}
