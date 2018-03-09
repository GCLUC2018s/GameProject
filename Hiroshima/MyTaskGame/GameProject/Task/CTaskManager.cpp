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
		//先頭がなかったら、追加されたタスクを先頭に
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
	//先頭が存在していれば
	else {
		//末尾に追加
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
		// 自身のリンクをクリア 
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
		// 自身のリンクをクリア 
		(*p)->mp_Drw_prev = nullptr;
		(*p)->mp_Drw_next = nullptr;
	}
}
CTaskManager::~CTaskManager()
{
}

void CTaskManager::Add(CTask * p)
{
	//Update用の線つなぎ
	AddTaskIn(&p, &mp_Upd_Top, &mp_Upd_End,eUpdate);
	//Draw用の線つなぎ
	AddTaskIn(&p, &mp_Drw_Top, &mp_Drw_End,eDraw);
}

CTask * CTaskManager::Kill(CTask * p)
{
	CTask *next = nullptr;
	if (p->mp_Upd_next != nullptr) next = mp_Upd_Top;

	// リストから外す 
	RemoveTask(&p, &mp_Upd_Top, &mp_Upd_End, eUpdate);
	RemoveTask(&p, &mp_Drw_Top, &mp_Drw_End, eDraw);

	// 削除 
	delete p;

	// 後続を返す 
	return next;
}

void CTaskManager::KillAppoint()
{
	//先頭から順に削除フラグが真のタスクを削除していく
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
	//先頭から順にタスクを更新していく
	CTask *p = mp_Upd_Top;
	while (p)
	{
		p->Update();
		p = p->mp_Upd_next;
	}
}

void CTaskManager::DrawAll()
{
	//先頭から順にタスクを描画していく
	CTask *p = mp_Drw_Top;
	while (p)
	{
		p->Draw();
		p = p->mp_Drw_next;
	}
}


CTaskManager * CTaskManager::GetInstance()
{
	//タスクマネージャーは一個しかいらないので、なかった時だけ作る
	if (mp_instance == nullptr) {
		mp_instance = new CTaskManager();
	}
	//それを返す
	return mp_instance;
}
