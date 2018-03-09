/*!
	@brief	敵管理クラス hpp
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

		/// コンストラクタ
		clEnemyManager();
	public:
		/// デストラクタ
		~clEnemyManager();

		static clEnemyManager* GetInstance();
		static void ClearInstance();

		/*!
			@brief	初期化処理
		**/
		void Init();

		/*!
			@brief	終了処理
		**/
		void Finish();

		/*!
			@brief	敵生成
		**/
		void Create();

		/*!
			@brief 敵をリストから除外
		**/
		void Remove(clEnemy* enemy);

		/*!
			@brief	敵のリスト取得
		**/
		std::vector<clEnemy*> GetEnemyList() const;

		/*!
			@brief	更新処理
		**/
		void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__