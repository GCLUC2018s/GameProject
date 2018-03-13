#ifndef TASK_LINKER_GUARD
#define TASK_LINKER_GUARD

class CTask;

class CTaskLinker
{
	friend class CTaskManager;
private:
	int		m_priority;		// �D��x 
	CTaskLinker	*mp_prev;		// �O�̃|�C���^
	CTaskLinker	*mp_next;		// ���̃|�C���^
	CTask		*mp_task;		// �������g
public:
	CTaskLinker();
	CTaskLinker(int prio,CTask *task);
	~CTaskLinker();

	// �D��x�ݒ� 
	void	SetPriority(int prio);
	// �D��x�擾 
	int		GetPriority() const;


};
#endif // !TASK_LINKER_GUARD

