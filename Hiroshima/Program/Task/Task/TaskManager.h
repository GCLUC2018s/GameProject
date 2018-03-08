#ifndef TASK_MANAGER_GUARD
#define TASK_MANAGER_GUARD

class Task;

class TaskManager
{
public:
	TaskManager();
	void Update();
	void Add(Task* t);
	static TaskManager* m_instance;
private:
	Task* m_TOP;
	Task* m_END;
	Task* m_NOW;
};

#endif // !TASK_MANAGER_GUARD