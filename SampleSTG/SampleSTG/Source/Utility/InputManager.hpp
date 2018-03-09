/*!
	@brief	���͔���N���X hpp
	@author	s.namizashi
**/

#ifndef __INPUT_MANAGER_HPP__
#define __INPUT_MANAGER_HPP__

#include "Source/Include.hpp"

class clInputManager
{
	private:
		static clInputManager* mp_Instance;

		bool	m_IsPushKey[IK_COUNT];	// �e�L�[�̉����t���O
		bool	m_IsJudgeKey[IK_COUNT];	// �L�[���肷�邩�ǂ���

		/// �R���X�g���N�^
		clInputManager();
	public:
		/// �f�X�g���N�^
		~clInputManager();

		static clInputManager* GetInstance();
		static void ClearInstance();

		void Init();

		/*!
			@brief	�w�肵���L�[�������Ă��邩�ǂ���
			@param[in]	type	�L�[�^�C�v
			@return	true�Ȃ�Ή����Ă���
		**/
		bool IsOnKey( enKeyType type ) const;

		/*!
			@brief	�w�肵���L�[���������u�Ԃ��ǂ���
			@param[in]	type	�L�[�^�C�v
			@retrun	true�Ȃ�Ή������u��
		**/
		bool IsPushKey( enKeyType type ) const;

		/*!
			@brief	�X�V����
		**/
		void Update();
};

#endif	// #ifndef __INPUT_HPP__