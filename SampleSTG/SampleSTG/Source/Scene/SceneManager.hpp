/*!
	@brief	シーンマネージャークラス hpp
	@author	s.namizashi
**/

#ifndef __SCENE_MANAGER_HPP__
#define __SCENE_MANAGER_HPP__

#include "SceneBase.hpp"

class clSceneManager
{
	private:
		static clSceneManager* mp_Instance;
		clSceneBase*	m_Scene;

		/// コンストラクタ
		clSceneManager();

		/*!
			@brief	次のシーンを動的に確保し、返す
			@return	次のシーン(NULLならば、存在しない)
		**/
		clSceneBase* GetNextScene();

		/*!
			@brief	シーン切り替え
		**/
		void ChangeScene();
	public:
		/// デストラクタ
		~clSceneManager();

		static clSceneManager* GetInstance();
		static void ClearInstance();

		/*!
			@brief	初期化処理
		**/
		void Init();

		/*!
			@brief	更新処理
		**/
		void Update();
};

#endif	// #ifndef __SCENE_MANAGER_HPP__