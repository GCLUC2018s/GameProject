#ifndef TASK_GUARD
#define TASK_GUARD

#include <stdio.h>

//�^�X�N�w�b�_�[
class Task
{
public:
	Task() {
		TaskManager::m_instan->Add(this);
	};
	virtual void Update() {
		printf("Task\n");
	};
	bool m_kill;

};
#endif // !TASK_GUARD