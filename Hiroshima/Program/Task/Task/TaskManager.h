#ifndef TASK_MANAGER_GUARD
#define TASK_MANAGER_GUARD
#include "Task.h"

class TaskManager
{
public:
	TaskManager() {

	}
	void Update() {

	}
	Task a;
	Task b;
	Task c;
	static TaskManager* m_instan;
	void Add(Task* t) {
		Task a = b;
		Task b = c;
		Task c = *t;
	}
};

#endif // !TASK_MANAGER_GUARD