#include "CTaskManager.h"
#include "CTask.h"
#include "CTaskLinker.h"

CTaskManager* CTaskManager::mp_instance = nullptr;

CTaskManager::CTaskManager():
	mp_U_Top(nullptr),
	mp_U_End(nullptr),
	mp_D_Top(nullptr),
	mp_D_End(nullptr)
{
}

CTaskManager::~CTaskManager()
{
}

void CTaskManager::AddTask(CTaskLinker * p, CTaskLinker ** pTop, CTaskLinker ** pEnd)
{
	//�擪�����݂��Ȃ����
	if ((*pTop) == nullptr) {
		//�ǉ����ꂽ�^�X�N��擪��
		*pTop = p;
		p->mp_prev = nullptr;
		p->mp_next = nullptr;
		*pEnd = p;
	}//�擪������
	else {
		CTaskLinker *t = (*pTop);
		while (t) {
			//�w�肵���D��x�̂Ƃ���ɂ����
			if (p->GetPriority() < t->GetPriority()) {
				// �}��
				CTaskLinker	*prev = t->mp_prev;
				if (prev != nullptr) prev->mp_next = p;
				t->mp_prev = p;
				p->mp_prev = prev;
				p->mp_next = t;
				// �擪�̏ꍇ 
				if (t == *pTop) *pTop = p;
				return;
			}
			// ���� 
			t = t->mp_next;
		}
		//�����ɒǉ�
		CTaskLinker* prev = *pEnd;
		if (prev != nullptr) prev->mp_next = p;
		p->mp_prev = prev;
		p->mp_next = nullptr;
		(*pEnd)->mp_next = p;
		(*pEnd) = p;
	}
}

// ���X�g����O��
void CTaskManager::RemoveTask(CTaskLinker * p, CTaskLinker ** pTop, CTaskLinker ** pEnd)
{
	// �O����q������ 
	CTaskLinker *prev = p->mp_prev;
	CTaskLinker *next = p->mp_next;
	if (prev != nullptr) prev->mp_next = next;
	if (next != nullptr) next->mp_prev = prev;

	// ���g�̃����N���N���A 
	p->mp_prev = nullptr;
	p->mp_next = nullptr;

	// �擪���Đݒ� 
	if (*pTop == p) *pTop = next;
	// �I�[���Đݒ� 
	if (*pEnd == p) *pEnd = prev;
}
void CTaskManager::Add(CTask * p)
{
	//Update�p
	AddTask(&(p->m_UPD_link), &mp_U_Top, &mp_U_End);
	//Draw�p
	AddTask(&(p->m_DRW_link), &mp_D_Top, &mp_D_End);
}

CTask * CTaskManager::Kill(CTask * p)
{
	//if (p->GetUpdatePrio() == eU_Scene)
	//	if (p->m_destroy == false)
	//		return p;
	//p��������̂ŁA���^�[���ŕԂ���悤�Ɏc���Ƃ�
	CTask *next = nullptr;
	if (p->m_UPD_link.mp_next != nullptr)
		next = p->m_UPD_link.mp_next->mp_task;

	//���X�g����O��
	RemoveTask(&(p->m_UPD_link), &mp_U_Top, &mp_U_End);
	RemoveTask(&(p->m_DRW_link), &mp_D_Top, &mp_D_End);

	//�폜
	delete p;

	return next;
}

void CTaskManager::KillAppoint()
{
	//�擪���珇�ɁA�폜�t���O�����čs���āAtrue�ɂȂ��Ă�������
	CTaskLinker *p = mp_U_Top;
	while (p)
	{
		CTaskLinker	*next = p->mp_next;
		if (p->mp_task->m_destroy)
			Kill(p->mp_task);
		p = next;
	}
}

void CTaskManager::KillAll()
{
	//�擪����^�X�N���폜���Ă���
	CTaskLinker *p = mp_U_Top;
	while (p)
	{
		CTaskLinker *next = p->mp_next;
		Kill(p->mp_task);
		p = next;
	}
}

void CTaskManager::SetKillAll()
{
	//�擪����^�X�N�̍폜�t���O��true�ɂ��Ă���
	CTaskLinker *p = mp_U_Top;
	while (p)
	{
		CTaskLinker *next = p->mp_next;
		p->mp_task->SetKill();
		p = next;
	}
}

void CTaskManager::SetPause(int ID, bool flag)
{
	//�擪���珇�Ɋm�F���Ă���
	CTaskLinker *p = mp_U_Top;
	while (p)
	{
		if (p->mp_task->m_id == ID) {
			p->mp_task->m_pause = flag;
		}
		p = p->mp_next;
	}
}

void CTaskManager::UpdateAll()
{
	//�擪���珇�Ƀ^�X�N���X�V���Ă���
	CTaskLinker *p = mp_U_Top;
	while (p)
	{
		if (p->mp_task->m_pause == false)
			p->mp_task->Update();
		p = p->mp_next;
	}
}

void CTaskManager::DrawAll()
{
	//�擪���珇�Ƀ^�X�N��`�悵�Ă���
	CTaskLinker *p = mp_D_Top;
	while (p)
	{
		p->mp_task->Draw();
		p = p->mp_next;
	}
}

void CTaskManager::ChangeUpdatePrio(CTask * p, int prio)
{
	// �����N���珜�O���� 
	RemoveTask(&(p->m_UPD_link), &mp_U_Top, &mp_U_End);

	// �v���C�I���e�B�[��ݒ� 
	p->m_UPD_link.SetPriority(prio);

	// Update�p���X�g�ɒǉ� 
	AddTask(&(p->m_UPD_link), &mp_U_Top, &mp_U_End);

}

void CTaskManager::ChangeDrawPrio(CTask * p, int prio)
{
	// �����N���珜�O���� 
	RemoveTask(&(p->m_DRW_link), &mp_D_Top, &mp_D_End);

	// �v���C�I���e�B�[��ݒ� 
	p->m_DRW_link.SetPriority(prio);

	// Update�p���X�g�ɒǉ� 
	AddTask(&(p->m_DRW_link), &mp_D_Top, &mp_D_End);
}

CTask * CTaskManager::GetTask(int id)
{
	CTaskLinker *p = mp_U_Top;
	while (p)
	{
		if (p->mp_task->m_id == id) return p->mp_task;
		p = p->mp_next;
	}

	//�Ȃ��Ȃ�null��Ԃ�
	return nullptr;
}

int CTaskManager::GetCount(int id)
{
	int cnt = 0;

	CTaskLinker *p = mp_U_Top;
	while (p)
	{
		if (p->mp_task->m_id == id) cnt++;
		p = p->mp_next;
	}

	//����Ԃ�
	return cnt;
}

CTaskManager * CTaskManager::GetInstance()
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

