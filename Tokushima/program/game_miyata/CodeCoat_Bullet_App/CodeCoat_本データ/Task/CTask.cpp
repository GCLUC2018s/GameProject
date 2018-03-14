#include "CTask.h"
#include "CTaskManager.h"

#include <stdio.h>

//�f�t�H���g�R���X�g���N�^
CTask::CTask() :
	m_destroyFlg(false),
	m_pauseFlg(false),
	m_id(0),
	m_updLinker(eUDP_Null,this),
	m_drwLinker(eDWP_Null,this)
{
	//Manager�ɓo�^����Ȃ�
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
	//�^�X�N�쐬��A������Manager�ɓo�^
	CTaskManager::GetInstance()->Add(this);
}
CTask::~CTask()
{
	
}
void CTask::Update()
{
	//�h����Œ�`
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


//�X�V���ʕύX
void CTask::ChangeUpdatePrio(int updatePrio)
{
	CTaskManager::GetInstance()->ChangeUpdatePrio(this, updatePrio);
}

//�`�揇�ʕύX
void CTask::ChangeDrawPriority(int drawPrio)
{
	CTaskManager::GetInstance()->ChangeDrawPrio(this, drawPrio);
}

//�X�V���ʎ擾�֐�
int CTask::GetUpdatePrio() const
{
	return m_updLinker.GetPriority();
}

//�`�揇�ʎ擾�֐�
int CTask::GetDrawPrio() const
{
	return m_drwLinker.GetPriority();
}
