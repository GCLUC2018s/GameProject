/*!
	@brief	�e�����N���X hpp
	@author	s.namizashi
**/

#ifndef __BULLET_HPP__
#define __BULLET_HPP__

#include "Source/Include.hpp"
#include "Source/Utility/Font.hpp"
#include "Source/Utility/Image.hpp"

class clBullet : public CTask
{
	private:
		clImage		m_Image;
		VECTOR2F	m_Pos;
		VECTOR2F	m_Vec;
		bool		m_IsInitialized;
		bool		m_IsKill;
	public:
		/// �R���X�g���N�^
		clBullet();
		/// �f�X�g���N�^
		~clBullet();

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

#endif	// #ifndef __BULLET_HPP__