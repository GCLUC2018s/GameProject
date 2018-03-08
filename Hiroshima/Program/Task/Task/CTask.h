#ifndef TASK_GUARD
#define TASK_GUARD

#include <stdio.h>

//タスクヘッダー
class CTask
{
public:
	CTask();
	virtual void Update();
	bool GetKill() {
		return m_kill;
	};
	static void HitCheck(CTask* t1, CTask* t2);
	static void Swap(CTask* t1, CTask* t2);
	int GetMyNum() {
		return m_num;
	}
	bool m_kill;
	int m_num;
	CTask* m_next;
	CTask* m_prev;

};
#endif // !TASK_GUARD