#include "CTaskManager.h"
#include "CTask.h"
#include "CTaskLinker.h"


CTaskManager* CTaskManager::mp_instance = nullptr;

CTaskManager::CTaskManager()
		:	mp_updHead(nullptr)
		,	mp_updTail(nullptr)
		,	mp_drwHead(nullptr)
		,	mp_drwTail(nullptr)
{
}
CTaskManager::~CTaskManager()
{
}

// ���X�g�ǉ��������� 
void CTaskManager::AddTaskInner( CTaskLinker *p, CTaskLinker **pHead, CTaskLinker **pTail )
{
	//�擪�����݂��Ȃ����
	if ( (*pHead) == nullptr )
	{
		//�ǉ����ꂽ�^�X�N��擪��
		*pHead = p;
		p->mp_prev = nullptr;
		p->mp_next = nullptr;
		*pTail = p;
	}
	//�擪�����݂��Ă����
	else
	{
		CTaskLinker *t = (*pHead);

		while ( t != nullptr )
		{
			// �}�����ׂ��D��x��T�� 
			if ( p->GetPriority() < t->GetPriority() ) {
				// �}�� 
				CTaskLinker	*prev = t->mp_prev;
				if ( prev != nullptr ) prev->mp_next = p;
				t->mp_prev = p;
				p->mp_prev = prev;
				p->mp_next = t;
				// �擪�̏ꍇ 
				if ( t == *pHead ) *pHead = p;
				return;
			}
			// ���� 
			t = t->mp_next;
		}
		// �����ɒǉ�  
		CTaskLinker* prev = *pTail;
		if ( prev != nullptr ) prev->mp_next = p;
		p->mp_prev = prev;
		p->mp_next = nullptr;
		(*pTail)->mp_next = p;
		(*pTail) = p;
	}
}


void CTaskManager::Add(CTask *p)
{
	// Update�p���X�g�ɒǉ� 
	AddTaskInner( &(p->m_updLinker), &mp_updHead, &mp_updTail );

	// Draw�p���X�g�ɒǉ� 
	AddTaskInner( &(p->m_drwLinker), &mp_drwHead, &mp_drwTail );

}


// ���X�g����O�� 
void CTaskManager::RemoveTaskLinker( CTaskLinker *p, CTaskLinker **pHead, CTaskLinker **pTail )
{
	// �O����q������ 
	CTaskLinker *prev = p->mp_prev;
	CTaskLinker *next = p->mp_next;
	if ( prev != nullptr ) prev->mp_next = next;
	if ( next != nullptr ) next->mp_prev = prev;

	// ���g�̃����N���N���A 
	p->mp_prev = nullptr;
	p->mp_next = nullptr;

	// �擪���Đݒ� 
	if ( *pHead == p ) *pHead = next;
	// �I�[���Đݒ� 
	if ( *pTail == p ) *pTail = prev;
}



CTask* CTaskManager::Kill(CTask *p)
{
	CTask *next = nullptr;
	if ( p->m_updLinker.mp_next != nullptr ) next = p->m_updLinker.mp_next->mp_task;

	// ���X�g����O�� 
	RemoveTaskLinker( &(p->m_updLinker), &mp_updHead, &mp_updTail );
	RemoveTaskLinker( &(p->m_drwLinker), &mp_drwHead, &mp_drwTail );

	// �폜 
	delete p;

	// �㑱��Ԃ� 
	return next;

}

void CTaskManager::KillAppoint()
{
	//�擪���珇�ɍ폜�t���O���^�̃^�X�N���폜���Ă���
	CTaskLinker *p = mp_updHead;
	while (p)
	{
		CTaskLinker	*next = p->mp_next;
		if ( p->mp_task->m_destroyFlg ) Kill(p->mp_task);
		p = next;
	}

}

void CTaskManager::KillAll()
{
	//�擪����^�X�N���폜���Ă���
	CTaskLinker *p = mp_updHead;
	while ( p )
	{
		CTaskLinker *next = p->mp_next;
		Kill( p->mp_task );
		p = next;
	}
}

void CTaskManager::UpdateAll()
{
	//�擪���珇�Ƀ^�X�N���X�V���Ă���
	CTaskLinker *p = mp_updHead;
	while ( p )
	{
		p->mp_task->Update();
		p = p->mp_next;
	}
}

void CTaskManager::DrawAll()
{
	//�擪���珇�Ƀ^�X�N��`�悵�Ă���
	CTaskLinker *p = mp_drwHead;
	while ( p )
	{
		p->mp_task->Draw();
		p = p->mp_next;
	}
}


// �X�V�D��x��ύX 
void CTaskManager::ChangeUpdatePrio(CTask *p, int prio)
{
	// �����N���珜�O���� 
	RemoveTaskLinker( &(p->m_updLinker), &mp_updHead, &mp_updTail );

	// �v���C�I���e�B�[��ݒ� 
	p->m_updLinker.SetPriority(prio);

	// Update�p���X�g�ɒǉ� 
	AddTaskInner( &(p->m_updLinker), &mp_updHead, &mp_updTail );

}

// �`��D��x��ύX 
void CTaskManager::ChangeDrawPrio(CTask *p, int prio)
{
	// �����N���珜�O���� 
	RemoveTaskLinker( &(p->m_drwLinker), &mp_drwHead, &mp_drwTail );

	// �v���C�I���e�B�[��ݒ� 
	p->m_drwLinker.SetPriority(prio);

	// Update�p���X�g�ɒǉ� 
	AddTaskInner( &(p->m_drwLinker), &mp_drwHead, &mp_drwTail );
}




CTask* CTaskManager::GetTask(int id)
{
	CTaskLinker *p = mp_updHead;
	while ( p )
	{
		if ( p->mp_task->m_id == id ) return p->mp_task;
		p = p->mp_next;
	}

	//�ȊO�Ȃ�null��Ԃ�
	return nullptr;
}

int CTaskManager::GetCount(int id)
{
	int cnt = 0;

	CTaskLinker *p = mp_updHead;
	while ( p )
	{
		if ( p->mp_task->m_id == id ) cnt ++;
		p = p->mp_next;
	}

	//����Ԃ�
	return cnt;
}

CTaskManager* CTaskManager::GetInstance()
{
	//CTaskManager����x�̂݁i�V���O���g���j�������Ċi�[
	if (mp_instance == nullptr)
	{
		mp_instance = new CTaskManager();
	}
	//�����Ԃ�
	return mp_instance;
}

void CTaskManager::ClearInstance()
{
	//���������[�N���
	if (mp_instance != nullptr) delete mp_instance;
}
