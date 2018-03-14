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
	//先頭が存在しなければ
	if ((*pTop) == nullptr) {
		//追加されたタスクを先頭に
		*pTop = p;
		p->mp_prev = nullptr;
		p->mp_next = nullptr;
		*pEnd = p;
	}//先頭いたら
	else {
		CTaskLinker *t = (*pTop);
		while (t) {
			//指定した優先度のところにいれる
			if (p->GetPriority() < t->GetPriority()) {
				// 挿入
				CTaskLinker	*prev = t->mp_prev;
				if (prev != nullptr) prev->mp_next = p;
				t->mp_prev = p;
				p->mp_prev = prev;
				p->mp_next = t;
				// 先頭の場合 
				if (t == *pTop) *pTop = p;
				return;
			}
			// 次へ 
			t = t->mp_next;
		}
		//末尾に追加
		CTaskLinker* prev = *pEnd;
		if (prev != nullptr) prev->mp_next = p;
		p->mp_prev = prev;
		p->mp_next = nullptr;
		(*pEnd)->mp_next = p;
		(*pEnd) = p;
	}
}

// リストから外す
void CTaskManager::RemoveTask(CTaskLinker * p, CTaskLinker ** pTop, CTaskLinker ** pEnd)
{
	// 前後を繋ぎ直し 
	CTaskLinker *prev = p->mp_prev;
	CTaskLinker *next = p->mp_next;
	if (prev != nullptr) prev->mp_next = next;
	if (next != nullptr) next->mp_prev = prev;

	// 自身のリンクをクリア 
	p->mp_prev = nullptr;
	p->mp_next = nullptr;

	// 先頭を再設定 
	if (*pTop == p) *pTop = next;
	// 終端を再設定 
	if (*pEnd == p) *pEnd = prev;
}
void CTaskManager::Add(CTask * p)
{
	//Update用
	AddTask(&(p->m_UPD_link), &mp_U_Top, &mp_U_End);
	//Draw用
	AddTask(&(p->m_DRW_link), &mp_D_Top, &mp_D_End);
}

CTask * CTaskManager::Kill(CTask * p)
{
	//if (p->GetUpdatePrio() == eU_Scene)
	//	if (p->m_destroy == false)
	//		return p;
	//pが消えるので、リターンで返せるように残しとく
	CTask *next = nullptr;
	if (p->m_UPD_link.mp_next != nullptr)
		next = p->m_UPD_link.mp_next->mp_task;

	//リストから外す
	RemoveTask(&(p->m_UPD_link), &mp_U_Top, &mp_U_End);
	RemoveTask(&(p->m_DRW_link), &mp_D_Top, &mp_D_End);

	//削除
	delete p;

	return next;
}

void CTaskManager::KillAppoint()
{
	//先頭から順に、削除フラグを見て行って、trueになってるやつを消す
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
	//先頭からタスクを削除していく
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
	//先頭からタスクの削除フラグをtrueにしていく
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
	//先頭から順に確認していく
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
	//先頭から順にタスクを更新していく
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
	//先頭から順にタスクを描画していく
	CTaskLinker *p = mp_D_Top;
	while (p)
	{
		p->mp_task->Draw();
		p = p->mp_next;
	}
}

void CTaskManager::ChangeUpdatePrio(CTask * p, int prio)
{
	// リンクから除外する 
	RemoveTask(&(p->m_UPD_link), &mp_U_Top, &mp_U_End);

	// プライオリティーを設定 
	p->m_UPD_link.SetPriority(prio);

	// Update用リストに追加 
	AddTask(&(p->m_UPD_link), &mp_U_Top, &mp_U_End);

}

void CTaskManager::ChangeDrawPrio(CTask * p, int prio)
{
	// リンクから除外する 
	RemoveTask(&(p->m_DRW_link), &mp_D_Top, &mp_D_End);

	// プライオリティーを設定 
	p->m_DRW_link.SetPriority(prio);

	// Update用リストに追加 
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

	//ないならnullを返す
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

	//個数を返す
	return cnt;
}

CTaskManager * CTaskManager::GetInstance()
{
	//CTaskManagerを一度のみ（シングルトン）生成して格納
	if (mp_instance == nullptr)
	{
		mp_instance = new CTaskManager();
	}
	//それを返す
	return mp_instance;
}

void CTaskManager::ClearInstance()
{
	//メモリリーク回避
	if (mp_instance != nullptr) delete mp_instance;
}

