#include "CTaskManager.h"
#include "CTask.h"

CTaskManager* CTaskManager::mp_instance = nullptr;

CTaskManager::CTaskManager()
{
	mp_Upd_Top = nullptr;
	mp_Upd_End = nullptr;
	mp_Drw_Top = nullptr;
	mp_Drw_End = nullptr;
}
void CTaskManager::AddTaskIn(CTask **p, CTask **pTop, CTask **pEnd, bool flag)
{
	if ((*pTop) == nullptr) {
		//�擪���Ȃ�������A�ǉ����ꂽ�^�X�N��擪��
		*pTop = *p;
		if (flag == eUpdate) {
			(*p)->mp_Upd_next = nullptr;
			(*p)->mp_Upd_prev = nullptr;
		}
		else {
			(*p)->mp_Drw_next = nullptr;
			(*p)->mp_Drw_prev = nullptr;
		}
		*pEnd = *p;
	}
	//�擪�����݂��Ă����
	else {
		//�����ɒǉ�
		if (flag == eUpdate) {
			(*p)->mp_Upd_prev = *pEnd;
			(*pEnd)->mp_Upd_next = *p;
		}
		else {
			(*p)->mp_Drw_prev = *pEnd;
			(*pEnd)->mp_Drw_next = *p;
		}
		*pEnd = *p;
	}
}
void CTaskManager::RemoveTask(CTask **p, CTask **pTop, CTask **pEnd, bool flag)
{
	if (flag == eUpdate) {
		if ((*p) == (*pTop)) {
			*pTop = (*p)->mp_Upd_next;
		}
		if ((*p) == (*pEnd)) {
			*pEnd = (*p)->mp_Upd_prev;
		}
		(*p)->mp_Upd_prev->mp_Upd_next = (*p)->mp_Upd_next;
		// ���g�̃����N���N���A 
		(*p)->mp_Upd_prev = nullptr;
		(*p)->mp_Upd_next = nullptr;
	}
	else {
		if ((*p) == (*pTop)) {
			*pTop = (*p)->mp_Drw_next;
		}
		if ((*p) == (*pEnd)) {
			*pEnd = (*p)->mp_Drw_prev;
		}
		(*p)->mp_Drw_prev->mp_Drw_next = (*p)->mp_Drw_next;
		// ���g�̃����N���N���A 
		(*p)->mp_Drw_prev = nullptr;
		(*p)->mp_Drw_next = nullptr;
	}
}
CTaskManager::~CTaskManager()
{
}

void CTaskManager::Add(CTask * p)
{
	//Update�p�̐��Ȃ�
	AddTaskIn(&p, &mp_Upd_Top, &mp_Upd_End,eUpdate);
	//Draw�p�̐��Ȃ�
	AddTaskIn(&p, &mp_Drw_Top, &mp_Drw_End,eDraw);
}

CTask * CTaskManager::Kill(CTask * p)
{
	CTask *next = nullptr;
	if (p->mp_Upd_next != nullptr) next = mp_Upd_Top;

	// ���X�g����O�� 
	RemoveTask(&p, &mp_Upd_Top, &mp_Upd_End, eUpdate);
	RemoveTask(&p, &mp_Drw_Top, &mp_Drw_End, eDraw);

	// �폜 
	delete p;

	// �㑱��Ԃ� 
	return next;
}

void CTaskManager::KillAppoint()
{
	//�擪���珇�ɍ폜�t���O���^�̃^�X�N���폜���Ă���
	CTask *p = mp_Upd_Top;
	while (p)
	{
		CTask	*next = p->mp_Upd_next;
		if (p->m_death_flag) Kill(p);
		p = next;
	}
}

void CTaskManager::UpdateAll()
{
	//�擪���珇�Ƀ^�X�N���X�V���Ă���
	CTask *p = mp_Upd_Top;
	while (p)
	{
		p->Update();
		p = p->mp_Upd_next;
	}
}

void CTaskManager::DrawAll()
{
	//�擪���珇�Ƀ^�X�N��`�悵�Ă���
	CTask *p = mp_Drw_Top;
	while (p)
	{
		p->Draw();
		p = p->mp_Drw_next;
	}
}


CTaskManager * CTaskManager::GetInstance()
{
	//�^�X�N�}�l�[�W���[�͈��������Ȃ��̂ŁA�Ȃ��������������
	if (mp_instance == nullptr) {
		mp_instance = new CTaskManager();
	}
	//�����Ԃ�
	return mp_instance;
}
