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

// リスト追加内部処理 
void CTaskManager::AddTaskInner( CTaskLinker *p, CTaskLinker **pHead, CTaskLinker **pTail )
{
	//先頭が存在しなければ
	if ( (*pHead) == nullptr )
	{
		//追加されたタスクを先頭に
		*pHead = p;
		p->mp_prev = nullptr;
		p->mp_next = nullptr;
		*pTail = p;
	}
	//先頭が存在していれば
	else
	{
		CTaskLinker *t = (*pHead);

		while ( t != nullptr )
		{
			// 挿入すべき優先度を探す 
			if ( p->GetPriority() < t->GetPriority() ) {
				// 挿入 
				CTaskLinker	*prev = t->mp_prev;
				if ( prev != nullptr ) prev->mp_next = p;
				t->mp_prev = p;
				p->mp_prev = prev;
				p->mp_next = t;
				// 先頭の場合 
				if ( t == *pHead ) *pHead = p;
				return;
			}
			// 次へ 
			t = t->mp_next;
		}
		// 末尾に追加  
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
	// Update用リストに追加 
	AddTaskInner( &(p->m_updLinker), &mp_updHead, &mp_updTail );

	// Draw用リストに追加 
	AddTaskInner( &(p->m_drwLinker), &mp_drwHead, &mp_drwTail );

}


// リストから外す 
void CTaskManager::RemoveTaskLinker( CTaskLinker *p, CTaskLinker **pHead, CTaskLinker **pTail )
{
	// 前後を繋ぎ直し 
	CTaskLinker *prev = p->mp_prev;
	CTaskLinker *next = p->mp_next;
	if ( prev != nullptr ) prev->mp_next = next;
	if ( next != nullptr ) next->mp_prev = prev;

	// 自身のリンクをクリア 
	p->mp_prev = nullptr;
	p->mp_next = nullptr;

	// 先頭を再設定 
	if ( *pHead == p ) *pHead = next;
	// 終端を再設定 
	if ( *pTail == p ) *pTail = prev;
}



CTask* CTaskManager::Kill(CTask *p)
{
	CTask *next = nullptr;
	if ( p->m_updLinker.mp_next != nullptr ) next = p->m_updLinker.mp_next->mp_task;

	// リストから外す 
	RemoveTaskLinker( &(p->m_updLinker), &mp_updHead, &mp_updTail );
	RemoveTaskLinker( &(p->m_drwLinker), &mp_drwHead, &mp_drwTail );

	// 削除 
	delete p;

	// 後続を返す 
	return next;

}

void CTaskManager::KillAppoint()
{
	//先頭から順に削除フラグが真のタスクを削除していく
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
	//先頭からタスクを削除していく
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
	//先頭から順にタスクを更新していく
	CTaskLinker *p = mp_updHead;
	while ( p )
	{
		p->mp_task->Update();
		p = p->mp_next;
	}
}

void CTaskManager::DrawAll()
{
	//先頭から順にタスクを描画していく
	CTaskLinker *p = mp_drwHead;
	while ( p )
	{
		p->mp_task->Draw();
		p = p->mp_next;
	}
}


// 更新優先度を変更 
void CTaskManager::ChangeUpdatePrio(CTask *p, int prio)
{
	// リンクから除外する 
	RemoveTaskLinker( &(p->m_updLinker), &mp_updHead, &mp_updTail );

	// プライオリティーを設定 
	p->m_updLinker.SetPriority(prio);

	// Update用リストに追加 
	AddTaskInner( &(p->m_updLinker), &mp_updHead, &mp_updTail );

}

// 描画優先度を変更 
void CTaskManager::ChangeDrawPrio(CTask *p, int prio)
{
	// リンクから除外する 
	RemoveTaskLinker( &(p->m_drwLinker), &mp_drwHead, &mp_drwTail );

	// プライオリティーを設定 
	p->m_drwLinker.SetPriority(prio);

	// Update用リストに追加 
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

	//以外ならnullを返す
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

	//個数を返す
	return cnt;
}

CTaskManager* CTaskManager::GetInstance()
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
