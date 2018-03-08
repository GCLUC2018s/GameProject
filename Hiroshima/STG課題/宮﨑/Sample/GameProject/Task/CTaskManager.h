/**
* @file		CTaskManager.h
* @brief	�^�X�N�V�X�e���Ǘ��N���X
* @author	ryoji anzai,yuki yamaji 
*/

#ifndef TASKMANAGER_GUARD
#define TASKMANAGER_GUARD

//#include "CTask.h"

class CTaskLinker;
class CTask;


class CTaskManager
{
private:
	CTaskManager();
	static CTaskManager* mp_instance;	//�V���O���g�����̂��߂̃|�C���^
protected:
	CTaskLinker *mp_updHead;		// Update�p �擪�v�f���w���|�C���^
	CTaskLinker *mp_updTail;		// Update�p �����v�f���w���|�C���^

	CTaskLinker *mp_drwHead;		// Draw�p �擪�v�f���w���|�C���^
	CTaskLinker *mp_drwTail;		// Draw�p �����v�f���w���|�C���^

public:
	~CTaskManager();
	//���X�g�ǉ��֐�
	void Add(CTask *p);
	//���X�g���폜�֐�
	CTask* Kill(CTask *p);
	//���X�g���w��폜�֐�
	void KillAppoint();
	//���X�g���S�폜�֐�
	void KillAll();
	//���X�g�X�V�֐�
	void UpdateAll();
	//���X�g�`��֐�
	void DrawAll();
	//�����蔻��֐�
	void CollisionAll();

	// �X�V�D��x��ύX 
	void ChangeUpdatePrio(CTask *p, int prio);
	// �`��D��x��ύX 
	void ChangeDrawPrio(CTask *p, int prio);

	//�^�X�N�擾�֐�
	CTask* GetTask(int id);
	//�^�X�N�J�E���g�֐�
	int GetCount(int id);

	//CTaskManager�𐶐����ĕϐ��Ɋi�[
	static CTaskManager* GetInstance();
	//�i�[����Ă�����̂��폜
	static void ClearInstance();

private:
	// ���X�g�ǉ��������� 
	void AddTaskInner( CTaskLinker *p, CTaskLinker **pHead, CTaskLinker **pTail );

	// ���X�g����O�� 
	void RemoveTaskLinker( CTaskLinker *p, CTaskLinker **pHead, CTaskLinker **pTail );

};

#endif