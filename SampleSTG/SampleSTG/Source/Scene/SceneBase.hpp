/*!
	@brief	�V�[���x�[�X�N���X hpp
	@author	s.namizashi
**/

#ifndef __SCENE_BASE_HPP__
#define __SCENE_BASE_HPP__

#include "Source/Include.hpp"
#include "Source/Utility/Font.hpp"
#include "Source/Utility/Image.hpp"

class clSceneBase
{
	private:
		static enSceneType		sm_NextID;	// ���̃V�[��ID
	public:
		/// �R���X�g���N�^
		clSceneBase();
		/// �f�X�g���N�^
		virtual ~clSceneBase();

		/*!
			@brief	����������
		**/
		virtual void Init();

		/*!
			@brief	�I������
		**/
		virtual void Finish();

		/*!
			@brief	���̃V�[��ID�ݒ�(�ݒ肷��Ƒ��ڍs)
			@param[in]	id	�ݒ肷��V�[��ID
		**/
		static void SetNext( enSceneType id );

		/*!
			@brief	���̃V�[��ID�擾
			@return	�V�[��ID
		**/
		static enSceneType GetNextID();

		/*!
			@brief	�X�V����(�p����p)
		**/
		virtual void UpdateSub();

		/*!
			@brief	�X�V����
		**/
		void Update();

		/*!
			@brief	�`�揈��(�p����p)
		**/
		virtual void DrawSub();

		/*!
			@brief	�O�ʕ`�揈��(�p����p)
		**/
		virtual void DrawFTSub();

		/*!
			@brief	�`�揈��
		**/
		void Draw();
};

#endif	// #ifndef __SCENE_BASE_HPP__