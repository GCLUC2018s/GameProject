/*!
	@brief	�Q�[���V�[�� hpp
	@author	s.namizashi
**/

#ifndef __GAME_SCENE_HPP__
#define __GAME_SCENE_HPP__

#include "SceneBase.h"

class clPlayer;

class clGameScene : public CSceneBase
{
	private:
		clPlayer*	m_Player;
	public:
		/// �R���X�g���N�^
		clGameScene();
		/// �f�X�g���N�^
		~clGameScene();

		/*!
			@brief	����������
		**/
		void Init();

		/*!
			@brief	�I������
		**/
		void Finish();

		/*!
			@brief	�X�V����
		**/
		void UpdateSub();

		/*!
			@brief	�`�揈��
		**/
		void DrawSub();
};

#endif	// #ifndef __GAME_SCENE_HPP__