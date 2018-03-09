/*!
	@brief	�e�Ǘ��N���X hpp
	@author	s.namizashi
**/

#ifndef __BULLET_MANAGER_HPP__
#define __BULLET_MANAGER_HPP__

#include "Source/Include.hpp"
#include "Source/Utility/Font.hpp"
#include "Source/Utility/Image.hpp"
#include "Bullet.hpp"

class clBulletManager
{
	private:
		static clBulletManager* mp_Instance;
		std::vector<clBullet*> m_BulletList;
		/// �R���X�g���N�^
		clBulletManager();
	public:
		/// �f�X�g���N�^
		~clBulletManager();

		static clBulletManager* GetInstance();
		static void ClearInstance();

		/*!
			@brief	����������
		**/
		void Init();

		/*!
			@brief	�I������
		**/
		void Finish();

		/*!
			@brief	�e����
		**/
		void Create(VECTOR2F start, VECTOR2F vec);

		/*!
			@brief	�e�����X�g���珜�O
		**/
		void Remove(clBullet* bullet);

		/*!
			@brief	�X�V����
		**/
		void Update();
};

#endif	// #ifndef __BULLET_MANAGER_HPP__