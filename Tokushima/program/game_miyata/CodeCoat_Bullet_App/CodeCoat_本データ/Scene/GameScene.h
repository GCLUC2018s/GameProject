/*!
	@brief	ゲームシーン hpp
	@author	s.namizashi
**/

#ifndef __GAME_SCENE_HPP__
#define __GAME_SCENE_HPP__

#include "SceneBase.h"

class clPlayer;

class clGameScene : public CSceneBase
{
	private:
		clPlayer*	m_Player;
	public:
		/// コンストラクタ
		clGameScene();
		/// デストラクタ
		~clGameScene();

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
		void UpdateSub();

		/*!
			@brief	描画処理
		**/
		void DrawSub();
};

#endif	// #ifndef __GAME_SCENE_HPP__