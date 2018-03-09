/**
* @file		CTaskLinker.h
* @brief	�^�X�N�V�X�e���̃��X�g���`�����邽�߂̃|�C���^�N���X
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_LINKER_GUARD
#define TASK_LINKER_GUARD

class CTask;

class CTaskLinker
{
	friend class CTaskManager;

private:
	int			m_priority;			// �D��x 
	CTaskLinker	*mp_prev;			// �O�̃|�C���^
	CTaskLinker	*mp_next;			// ���̃|�C���^
	CTask		*mp_task;			// ���g 

public:
	// �R���X�g���N�^ 
	CTaskLinker();
	// �R���X�g���N�^ 
	CTaskLinker(int priority, CTask *task);

	// �f�X�g���N�^ 
	~CTaskLinker();

	// �D��x�ݒ� 
	void	SetPriority(int prio);
	// �D��x�擾 
	int		GetPriority() const;

};

#endif