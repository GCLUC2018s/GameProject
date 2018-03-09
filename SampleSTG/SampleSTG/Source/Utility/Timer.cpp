/*!
	@brief	高精度タイマー cpp
	@author	s.namizashi
**/

#include "Timer.hpp"

LARGE_INTEGER	clTimer::sm_fTime;
bool			clTimer::sm_IsInit(false);

// コンストラクタ
clTimer::clTimer()
	: m_IsStart(false)
{
	if(!sm_IsInit)
	{
		QueryPerformanceFrequency(&sm_fTime);
		sm_IsInit = true;
	}
}

// デストラクタ
clTimer::~clTimer()
{
}

// 時間計測開始
void clTimer::StartTimer()
{
	if(m_IsStart) return;

	QueryPerformanceCounter(&m_bTime);
	m_IsStart = true;
}

// 時間計測停止
void clTimer::StopTimer()
{
	if(!m_IsStart) return;

	QueryPerformanceCounter(&m_aTime);
	m_IsStart = false;
}

// 経過時間取得(秒)
double clTimer::GetTimeS() const
{
	LARGE_INTEGER aTime;
	if(m_IsStart) QueryPerformanceCounter(&aTime);
	else aTime = m_aTime;

	return (double)(aTime.QuadPart-m_bTime.QuadPart)/(double)sm_fTime.QuadPart;
}

// 経過時間取得(ミリ秒)
double clTimer::GetTimeMS() const
{
	LARGE_INTEGER aTime;
	if(m_IsStart) QueryPerformanceCounter(&aTime);
	else aTime = m_aTime;

	return (double)(aTime.QuadPart-m_bTime.QuadPart)/((double)sm_fTime.QuadPart/1000.0);
}

// 経過時間取得(マイクロ秒)
double clTimer::GetTimeMCS() const
{
	LARGE_INTEGER aTime;
	if(m_IsStart) QueryPerformanceCounter(&aTime);
	else aTime = m_aTime;

	return (double)(aTime.QuadPart-m_bTime.QuadPart)/((double)sm_fTime.QuadPart/1000000.0);
}
