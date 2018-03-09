#include "task.h"
#include "taskmanager.h"
#include "DxLib.h"
#include <stdio.h>

//�f�t�H���g�R���X�g���N�^
CTask::CTask() :
m_destroyFlg(false),
m_pauseFlg(false),
m_id(0),
m_updLinker(eUDP_Null, this),
m_drwLinker(eDWP_Null, this)
{
	//Manager�ɓo�^����Ȃ�
}
CTask::CTask(int id, int updatePrio, int drawPrio) :
m_destroyFlg(false),
m_pauseFlg(false),
m_id(id),
m_updLinker(updatePrio, this),
m_drwLinker(drawPrio, this)
{
	printfDx("CTask[ %5d ] Prio( %d / %d )\n", id, updatePrio, drawPrio);
	//�^�X�N�쐬��A������Manager�ɓo�^		return CTaskManager�Ȃ̂�add���g�p�\
	CTaskManager::GetInstance()->Add(this);
}
CTask::~CTask()
{

}
void CTask::Update()
{
	//�h����Œ�`
	printf("Update[%3d] PRIO:%6d\n", m_id, m_updLinker.GetPriority());
}
void CTask::Draw()
{
	printf("Draw[%3d] PRIO:%6d\n", m_id, m_drwLinker.GetPriority());
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
