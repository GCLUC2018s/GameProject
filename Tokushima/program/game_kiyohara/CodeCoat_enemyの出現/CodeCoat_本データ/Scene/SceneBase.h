/*!
	@brief	�V�[���x�[�X�N���X hpp
	@author	s.namizashi
**/

#ifndef __SCENE_BASE_HPP__
#define __SCENE_BASE_HPP__

#include "Include.h"

enum SCREEN{
	TITLE_SCREEN,
	SELECT_SCREEN,
	GAME_SCREEN,
	GAMECLEAR_SCREEN,
	GAMEOVER_SCREEN,
	GAMESCORE_SCREEN,
	GAMENEXT_SCREEN
};

class CSceneBase
{
public:
	virtual SCREEN GetNextScreen() = 0;
	/// �R���X�g���N�^
	CSceneBase(){}
		/// �f�X�g���N�^
		virtual ~CSceneBase(){}

		/*!
			@brief	����������
		**/
		virtual void Init(){}

		/*!
			@brief	�I������
		**/
		virtual void Dest(){}

		/*!
			@brief	���̃V�[��ID�ݒ�(�ݒ肷��Ƒ��ڍs)
			@param[in]	id	�ݒ肷��V�[��ID
		**/
		//static void SetNext(ESceneType id);

		/*!
			@brief	���̃V�[��ID�擾
			@return	�V�[��ID
		**/
		//static ESceneType GetNextID();

		/*!
			@brief	�X�V����(�p����p)
		**/
		//virtual void UpdateSub();

		/*!
			@brief	�X�V����
		**/
		virtual void Update(){}

		/*!
			@brief	�`�揈��(�p����p)
		**/
		//virtual void DrawSub();

		/*!
			@brief	�O�ʕ`�揈��(�p����p)
		**/
		//virtual void DrawFTSub();

		/*!
			@brief	�`�揈��
		**/
		virtual void Draw(){}
};

#endif	// #ifndef __SCENE_BASE_HPP__