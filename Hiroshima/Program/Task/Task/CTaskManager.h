#ifndef TASK_MANAGER_GUARD
#define TASK_MANAGER_GUARD

class CTask;

class CTaskManager
{
public:
	CTaskManager();
	void Update();
	void Add(CTask* t);
	void Delete(CTask* t);
	static CTaskManager* m_instance;
private:
	CTask* m_TOP;
	CTask* m_END;
	CTask* m_NOW;
	CTask* m_NOW_Hit;
};

#endif // !TASK_MANAGER_GUARD