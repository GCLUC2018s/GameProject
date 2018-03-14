#include "CTask.h"
#include "CTaskManager.h"

#include <stdio.h>

//デフォルトコンストラクタ
CTask::CTask() :
	m_destroyFlg(false),
	m_pauseFlg(false),
	m_id(0),
	m_updLinker(eUDP_Null,this),
	m_drwLinker(eDWP_Null,this)
{
	//Managerに登録されない
}
CTask::CTask(int id, int updatePrio, int drawPrio) :
	m_destroyFlg(false), 
	m_pauseFlg(false), 
	m_id(id),
	m_updLinker(updatePrio,this),
	m_drwLinker(drawPrio,this)
{
#if _DEBUG
	printf( "CTask[ %5d ] Prio( %d / %d )\n", id, updatePrio, drawPrio );
#endif
	//タスク作成後、自動でManagerに登録
	CTaskManager::GetInstance()->Add(this);
}
CTask::~CTask()
{
	
}
void CTask::Update()
{
	//派生先で定義
#if _DEBUG
	printf("Update[%3d] PRIO:%6d\n", m_id, m_updLinker.GetPriority());
#endif
}
void CTask::Draw()
{
#if _DEBUG
	printf("Draw[%3d] PRIO:%6d\n", m_id, m_drwLinker.GetPriority());
#endif
}


//更新順位変更
void CTask::ChangeUpdatePrio(int updatePrio)
{
	CTaskManager::GetInstance()->ChangeUpdatePrio(this, updatePrio);
}

//描画順位変更
void CTask::ChangeDrawPriority(int drawPrio)
{
	CTaskManager::GetInstance()->ChangeDrawPrio(this, drawPrio);
}

//更新順位取得関数
int CTask::GetUpdatePrio() const
{
	return m_updLinker.GetPriority();
}

//描画順位取得関数
int CTask::GetDrawPrio() const
{
	return m_drwLinker.GetPriority();
}
