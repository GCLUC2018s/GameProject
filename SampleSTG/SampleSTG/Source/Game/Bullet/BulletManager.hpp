/*!
	@brief	弾管理クラス hpp
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
		/// コンストラクタ
		clBulletManager();
	public:
		/// デストラクタ
		~clBulletManager();

		static clBulletManager* GetInstance();
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
			@brief	弾生成
		**/
		void Create(VECTOR2F start, VECTOR2F vec);

		/*!
			@brief	弾をリストから除外
		**/
		void Remove(clBullet* bullet);

		/*!
			@brief	更新処理
		**/
		void Update();
};

#endif	// #ifndef __BULLET_MANAGER_HPP__