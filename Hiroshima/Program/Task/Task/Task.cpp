#include "Task.h"
#include "TaskManager.h"

Task::Task()
{
	m_next = nullptr;
	m_prev = nullptr;
	TaskManager::m_instance->Add(this);
}

void Task::Update() {
	printf("Task\n");
}
