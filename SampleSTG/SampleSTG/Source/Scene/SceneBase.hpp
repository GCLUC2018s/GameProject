/*!
	@brief	シーンベースクラス hpp
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
		static enSceneType		sm_NextID;	// 次のシーンID
	public:
		/// コンストラクタ
		clSceneBase();
		/// デストラクタ
		virtual ~clSceneBase();

		/*!
			@brief	初期化処理
		**/
		virtual void Init();

		/*!
			@brief	終了処理
		**/
		virtual void Finish();

		/*!
			@brief	次のシーンID設定(設定すると即移行)
			@param[in]	id	設定するシーンID
		**/
		static void SetNext( enSceneType id );

		/*!
			@brief	次のシーンID取得
			@return	シーンID
		**/
		static enSceneType GetNextID();

		/*!
			@brief	更新処理(継承先用)
		**/
		virtual void UpdateSub();

		/*!
			@brief	更新処理
		**/
		void Update();

		/*!
			@brief	描画処理(継承先用)
		**/
		virtual void DrawSub();

		/*!
			@brief	前面描画処理(継承先用)
		**/
		virtual void DrawFTSub();

		/*!
			@brief	描画処理
		**/
		void Draw();
};

#endif	// #ifndef __SCENE_BASE_HPP__