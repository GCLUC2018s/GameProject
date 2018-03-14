/*!
	@brief	�V�[���}�l�[�W���[�N���X hpp
	@author	s.namizashi
**/

#ifndef __SCENE_MANAGER_HPP__
#define __SCENE_MANAGER_HPP__

#include "SceneBase.h"

class CSceneManager
{
	private:
		static CSceneManager* mp_Instance;
		CSceneBase*	m_Scene;

		/// �R���X�g���N�^
		CSceneManager();

		/*!
			@brief	���̃V�[���𓮓I�Ɋm�ۂ��A�Ԃ�
			@return	���̃V�[��(NULL�Ȃ�΁A���݂��Ȃ�)
		**/
		CSceneBase* GetNextScene();

		/*!
			@brief	�V�[���؂�ւ�
		**/
		void ChangeScene();
	public:
		/// �f�X�g���N�^
		~CSceneManager();

		static CSceneManager* GetInstance();
		static void ClearInstance();

		/*!
			@brief	����������
		**/
		void Init();

		/*!
			@brief	�X�V����
		**/
		void Update();
};

#endif	// #ifndef __SCENE_MANAGER_HPP__