/*!
	@brief	プレイヤー操作クラス hpp
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
		/// コンストラクタ
		clPlayer();
		/// デストラクタ
		~clPlayer();

		/*!
			@brief	初期化処理
		**/
		void Init();

		/*!
			@brief	終了処理
		**/
		void Finish();

		/*!
			@brief	更新処理
		**/
		void Update();

		/*!
			@brief	描画処理
		**/
		void Draw();
};

#endif	// #ifndef __PLAYER_HPP__