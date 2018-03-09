/*!
	@brief	�����x�^�C�}�[ cpp
	@author	s.namizashi
**/

#include "Timer.hpp"

LARGE_INTEGER	clTimer::sm_fTime;
bool			clTimer::sm_IsInit(false);

// �R���X�g���N�^
clTimer::clTimer()
	: m_IsStart(false)
{
	if(!sm_IsInit)
	{
		QueryPerformanceFrequency(&sm_fTime);
		sm_IsInit = true;
	}
}

// �f�X�g���N�^
clTimer::~clTimer()
{
}

// ���Ԍv���J�n
void clTimer::StartTimer()
{
	if(m_IsStart) return;

	QueryPerformanceCounter(&m_bTime);
	m_IsStart = true;
}

// ���Ԍv����~
void clTimer::StopTimer()
{
	if(!m_IsStart) return;

	QueryPerformanceCounter(&m_aTime);
	m_IsStart = false;
}

// �o�ߎ��Ԏ擾(�b)
double clTimer::GetTimeS() const
{
	LARGE_INTEGER aTime;
	if(m_IsStart) QueryPerformanceCounter(&aTime);
	else aTime = m_aTime;

	return (double)(aTime.QuadPart-m_bTime.QuadPart)/(double)sm_fTime.QuadPart;
}

// �o�ߎ��Ԏ擾(�~���b)
double clTimer::GetTimeMS() const
{
	LARGE_INTEGER aTime;
	if(m_IsStart) QueryPerformanceCounter(&aTime);
	else aTime = m_aTime;

	return (double)(aTime.QuadPart-m_bTime.QuadPart)/((double)sm_fTime.QuadPart/1000.0);
}

// �o�ߎ��Ԏ擾(�}�C�N���b)
double clTimer::GetTimeMCS() const
{
	LARGE_INTEGER aTime;
	if(m_IsStart) QueryPerformanceCounter(&aTime);
	else aTime = m_aTime;

	return (double)(aTime.QuadPart-m_bTime.QuadPart)/((double)sm_fTime.QuadPart/1000000.0);
}
