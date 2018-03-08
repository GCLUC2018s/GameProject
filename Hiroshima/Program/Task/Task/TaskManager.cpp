#include "CTaskManager.h"
#include "CTask.h"

CTaskManager* CTaskManager::m_instance = nullptr;
CTaskManager::CTaskManager()
{
	m_TOP = nullptr;
	m_END = nullptr;
}

void CTaskManager::Update()
{
	m_NOW = m_TOP;
	m_NOW_Hit = m_TOP;
	while (m_NOW != nullptr)
	{
		m_NOW->Update();
		if (m_NOW->GetKill()) {
			Delete(m_NOW);
		}
		while (m_NOW_Hit != nullptr)
		{
			m_NOW->HitCheck(m_NOW, m_NOW_Hit);
			m_NOW_Hit = m_NOW_Hit->m_next;
		}
		m_NOW_Hit = m_TOP;
		m_NOW = m_NOW->m_next;
	}
	getchar();
}

void CTaskManager::Add(CTask* t)
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

void CTaskManager::Delete(CTask* t)
{
	m_NOW = m_NOW->m_prev;
	t->m_prev->m_next = t->m_next;
	t->m_next->m_prev = t->m_prev;
	delete t;
}