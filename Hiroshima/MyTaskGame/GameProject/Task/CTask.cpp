#include "CTask.h"
#include "CTaskManager.h"

CTask::CTask() :
	m_id(0),
	m_destroy(false),
	m_pause(false),
	m_UPD_link(eU_Null, this),
	m_DRW_link(eD_Null, this)
{
	//���ɂȂ�
}

CTask::CTask(int id, int UPD_prio, int DRW_prio) :
	m_id(id),
	m_destroy(false),
	m_pause(false),
	m_UPD_link(UPD_prio, this),
	m_DRW_link(DRW_prio, this)
{
	//�^�X�N�쐬��A������Manager�ɓo�^
	CTaskManager::GetInstance()->Add(this);
}

CTask::~CTask()
{
	//�h����Œ�`
}

void CTask::Update()
{
	//�h����Œ�`
}

void CTask::Draw()
{
	//�h����Œ�`
}

void CTask::HitCheck(CTask * t1, CTask * t2)
{
	//�h����Œ�`
}

void CTask::Hit(CObjectBase * t)
{
	//�h����Œ�`
}

//�X�V���ʎ擾�֐�
int CTask::GetUpdatePrio() const
{
	return m_UPD_link.GetPriority();
}

//�`�揇�ʎ擾�֐�
int CTask::GetDrawPrio() const
{
	return m_DRW_link.GetPriority();
}


//�X�V���ʕύX
void CTask::ChangeUpdatePrio(int updatePrio)
{
	//����̓^�X�N�}�l�[�W���[�̊֐��ōs��
	CTaskManager::GetInstance()->ChangeUpdatePrio(this,updatePrio);
}

//�`�揇�ʕύX
void CTask::ChangeDrawPriority(int drawPrio)
{
	//����̓^�X�N�}�l�[�W���[�̊֐��ōs��
	CTaskManager::GetInstance()->ChangeDrawPrio(this, drawPrio);
}
