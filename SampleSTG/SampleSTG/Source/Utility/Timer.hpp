/*!
	@brief	高精度タイマー hpp
	@author	s.namizashi
**/

#ifndef __TIMER_HPP__
#define __TIMER_HPP__

#include <Windows.h>

class clTimer
{
	private:
		static LARGE_INTEGER	sm_fTime;
		static bool				sm_IsInit;

		LARGE_INTEGER			m_bTime;
		LARGE_INTEGER			m_aTime;

		bool					m_IsStart;
	public:
		/// コンストラクタ
		clTimer();
		/// デストラクタ
		~clTimer();

		/*!
			@brief	時間計測開始
		**/
		void StartTimer();
		/*!
			@brief	時間計測停止
		**/
		void StopTimer();

		/*!
			@brief	経過時間取得(秒)
			@return	経過時間
		**/
		double GetTimeS() const;
		/*!
			@brief	経過時間取得(ミリ秒)
			@return	経過時間
		**/
		double GetTimeMS() const;
		/*!
			@brief	経過時間取得(マイクロ秒)
			@return	経過時間
		**/
		double GetTimeMCS() const;
};

#endif	// #ifndef __TIMER_HPP__