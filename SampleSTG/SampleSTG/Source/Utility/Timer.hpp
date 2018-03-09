/*!
	@brief	�����x�^�C�}�[ hpp
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
		/// �R���X�g���N�^
		clTimer();
		/// �f�X�g���N�^
		~clTimer();

		/*!
			@brief	���Ԍv���J�n
		**/
		void StartTimer();
		/*!
			@brief	���Ԍv����~
		**/
		void StopTimer();

		/*!
			@brief	�o�ߎ��Ԏ擾(�b)
			@return	�o�ߎ���
		**/
		double GetTimeS() const;
		/*!
			@brief	�o�ߎ��Ԏ擾(�~���b)
			@return	�o�ߎ���
		**/
		double GetTimeMS() const;
		/*!
			@brief	�o�ߎ��Ԏ擾(�}�C�N���b)
			@return	�o�ߎ���
		**/
		double GetTimeMCS() const;
};

#endif	// #ifndef __TIMER_HPP__