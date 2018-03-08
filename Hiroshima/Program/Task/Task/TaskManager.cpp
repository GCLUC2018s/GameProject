#include "TaskManager.h"
#include "Task.h"

TaskManager* m_instance = nullptr;
TaskManager::TaskManager()
{
	m_TOP = nullptr;
	m_END = nullptr;
}

void TaskManager::Update()
{
	m_NOW = m_TOP;
	while (m_NOW->m_next != nullptr)
	{
		m_NOW->Update();
		m_NOW = m_NOW->m_next;
	}
}

void TaskManager::Add(Task * t)
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
