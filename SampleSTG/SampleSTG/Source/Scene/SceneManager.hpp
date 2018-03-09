/*!
	@brief	�V�[���}�l�[�W���[�N���X hpp
	@author	s.namizashi
**/

#ifndef __SCENE_MANAGER_HPP__
#define __SCENE_MANAGER_HPP__

#include "SceneBase.hpp"

class clSceneManager
{
	private:
		static clSceneManager* mp_Instance;
		clSceneBase*	m_Scene;

		/// �R���X�g���N�^
		clSceneManager();

		/*!
			@brief	���̃V�[���𓮓I�Ɋm�ۂ��A�Ԃ�
			@return	���̃V�[��(NULL�Ȃ�΁A���݂��Ȃ�)
		**/
		clSceneBase* GetNextScene();

		/*!
			@brief	�V�[���؂�ւ�
		**/
		void ChangeScene();
	public:
		/// �f�X�g���N�^
		~clSceneManager();

		static clSceneManager* GetInstance();
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