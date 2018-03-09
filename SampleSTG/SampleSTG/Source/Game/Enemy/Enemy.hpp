/*!
	@brief	敵処理クラス hpp
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
		/// コンストラクタ
		clEnemy();
		/// デストラクタ
		~clEnemy();

		/*!
			@brief	初期化処理
		**/
		void Init(VECTOR2F start, VECTOR2F vec);

		/*!
			@brief	終了処理
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
			@brief	更新処理
		**/
		void Update();

		/*!
			@brief	描画処理
		**/
		void Draw();
};

#endif	// #ifndef __ENEMY_HPP__