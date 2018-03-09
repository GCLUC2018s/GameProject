/*!
	@brief	�G�Ǘ��N���X hpp
	@author	s.namizashi
**/

#ifndef __ENEMY_MANAGER_HPP__
#define __ENEMY_MANAGER_HPP__

#include "Source/Include.hpp"
#include "Source/Utility/Font.hpp"
#include "Source/Utility/Image.hpp"
#include "Source/Game/Enemy/Enemy.hpp"

class clEnemyManager
{
	private:
		static clEnemyManager* mp_Instance;
		std::vector<clEnemy*> m_EnemyList;
		int			m_Elapsed;

		/// �R���X�g���N�^
		clEnemyManager();
	public:
		/// �f�X�g���N�^
		~clEnemyManager();

		static clEnemyManager* GetInstance();
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
			@brief	�G����
		**/
		void Create();

		/*!
			@brief �G�����X�g���珜�O
		**/
		void Remove(clEnemy* enemy);

		/*!
			@brief	�G�̃��X�g�擾
		**/
		std::vector<clEnemy*> GetEnemyList() const;

		/*!
			@brief	�X�V����
		**/
		void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__