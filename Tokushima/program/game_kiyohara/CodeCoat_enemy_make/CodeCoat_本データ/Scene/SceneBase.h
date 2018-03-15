/*!
	@brief	シーンベースクラス hpp
	@author	s.namizashi
**/

#ifndef __SCENE_BASE_HPP__
#define __SCENE_BASE_HPP__

#include "Include.h"

enum SCREEN{
	TITLE_SCREEN,
	SELECT_SCREEN,
	GAME_SCREEN,
	GAMECLEAR_SCREEN,
	GAMEOVER_SCREEN,
	GAMESCORE_SCREEN,
	GAMENEXT_SCREEN
};

class CSceneBase
{
public:
	virtual SCREEN GetNextScreen() = 0;
	/// コンストラクタ
	CSceneBase(){}
		/// デストラクタ
		virtual ~CSceneBase(){}

		/*!
			@brief	初期化処理
		**/
		virtual void Init(){}

		/*!
			@brief	終了処理
		**/
		virtual void Dest(){}

		/*!
			@brief	次のシーンID設定(設定すると即移行)
			@param[in]	id	設定するシーンID
		**/
		//static void SetNext(ESceneType id);

		/*!
			@brief	次のシーンID取得
			@return	シーンID
		**/
		//static ESceneType GetNextID();

		/*!
			@brief	更新処理(継承先用)
		**/
		//virtual void UpdateSub();

		/*!
			@brief	更新処理
		**/
		virtual void Update(){}

		/*!
			@brief	描画処理(継承先用)
		**/
		//virtual void DrawSub();

		/*!
			@brief	前面描画処理(継承先用)
		**/
		//virtual void DrawFTSub();

		/*!
			@brief	描画処理
		**/
		virtual void Draw(){}
};

#endif	// #ifndef __SCENE_BASE_HPP__