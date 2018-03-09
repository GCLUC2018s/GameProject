#include "CTask.h"
	//m_Update_next(updatePrio, this),
	//m_Draw_next(drawPrio, this)
	//m_Update_prev(updatePrio, this),
	//m_Draw_prev(drawPrio, this)

CTask::CTask(int id, int updatePrio, int drawPrio)
{
	m_death_flag = false;
	m_pause_flag = false;
	m_id = id;
	m_Update_num = updatePrio;
	m_Draw_num = drawPrio;
}

CTask::~CTask()
{
}

void CTask::Update()
{
}

void CTask::Draw()
{
}

void CTask::HitCheck(CTask * t1, CTask * t2)
{
}

void CTask::Swap_Draw(CTask * t1, CTask * t2)
{
}

void CTask::Swap_Update(CTask * t1, CTask * t2)
{
}
