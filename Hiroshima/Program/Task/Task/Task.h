#ifndef TASK_GUARD
#define TASK_GUARD

#include <stdio.h>

//タスクヘッダー
class Task
{
public:
	Task();
	virtual void Update();
	bool GetKill() {
		return m_kill;
	};
	bool m_kill;
	Task* m_next;
	Task* m_prev;

};
#endif // !TASK_GUARD