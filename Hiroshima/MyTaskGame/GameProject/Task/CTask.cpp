#include "CTask.h"
#include "CTaskManager.h"

CTask::CTask() :
	m_id(0),
	m_destroy(false),
	m_pause(false),
	m_UPD_link(eU_Null, this),
	m_DRW_link(eD_Null, this)
{
	//特になし
}

CTask::CTask(int id, int UPD_prio, int DRW_prio) :
	m_id(id),
	m_destroy(false),
	m_pause(false),
	m_UPD_link(UPD_prio, this),
	m_DRW_link(DRW_prio, this)
{
	//タスク作成後、自動でManagerに登録
	CTaskManager::GetInstance()->Add(this);
}

CTask::~CTask()
{
	//派生先で定義
}

void CTask::Update()
{
	//派生先で定義
}

void CTask::Draw()
{
	//派生先で定義
}

void CTask::HitCheck(CTask * t1, CTask * t2)
{
	//派生先で定義
}

void CTask::Hit(CObjectBase * t)
{
	//派生先で定義
}

//更新順位取得関数
int CTask::GetUpdatePrio() const
{
	return m_UPD_link.GetPriority();
}

//描画順位取得関数
int CTask::GetDrawPrio() const
{
	return m_DRW_link.GetPriority();
}


//更新順位変更
void CTask::ChangeUpdatePrio(int updatePrio)
{
	//操作はタスクマネージャーの関数で行う
	CTaskManager::GetInstance()->ChangeUpdatePrio(this,updatePrio);
}

//描画順位変更
void CTask::ChangeDrawPriority(int drawPrio)
{
	//操作はタスクマネージャーの関数で行う
	CTaskManager::GetInstance()->ChangeDrawPrio(this, drawPrio);
}
