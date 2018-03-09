/*!
	@brief	�G�����N���X hpp
	@author	s.namizashi
**/

#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include "Source/Include.hpp"
#include "Source/Utility/Font.hpp"
#include "Source/Utility/Image.hpp"

class clEnemy : CTask
{
	private:
		clImage		m_Image;
		VECTOR2F	m_Pos;
		VECTOR2F	m_Vec;
		bool		m_IsInitialized;
		bool		m_IsKill;
	public:
		/// �R���X�g���N�^
		clEnemy();
		/// �f�X�g���N�^
		~clEnemy();

		/*!
			@brief	����������
		**/
		void Init(VECTOR2F start, VECTOR2F vec);

		/*!
			@brief	�I������
		**/
		void Finish();

		VECTOR2F GetPos() const
		{
			return m_Pos;
		}

		void Kill();
		bool IsKill() const
		{
			return m_IsKill;
		}

		/*!
			@brief	�X�V����
		**/
		void Update();

		/*!
			@brief	�`�揈��
		**/
		void Draw();
};

#endif	// #ifndef __ENEMY_HPP__