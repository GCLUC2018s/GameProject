/*!
	@brief	�v���C���[����N���X hpp
	@author	s.namizashi
**/

#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Source/Include.hpp"
#include "Source/Utility/Font.hpp"
#include "Source/Utility/Image.hpp"

class clPlayer : CTask
{
	private:
		clImage		m_Image;
		VECTOR2F	m_Pos;
		int			m_Elapsed;
	public:
		/// �R���X�g���N�^
		clPlayer();
		/// �f�X�g���N�^
		~clPlayer();

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
		void Update();

		/*!
			@brief	�`�揈��
		**/
		void Draw();
};

#endif	// #ifndef __PLAYER_HPP__