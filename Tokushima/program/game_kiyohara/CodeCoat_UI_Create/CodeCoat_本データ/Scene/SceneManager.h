/*!
	@brief	シーンマネージャークラス hpp
	@author	s.namizashi
**/

#ifndef __SCENE_MANAGER_HPP__
#define __SCENE_MANAGER_HPP__

#include "SceneBase.h"

class CSceneManager
{
	private:
		static CSceneManager* mp_Instance;
		CSceneBase*	m_Scene;

		/// コンストラクタ
		CSceneManager();

		/*!
			@brief	次のシーンを動的に確保し、返す
			@return	次のシーン(NULLならば、存在しない)
		**/
		CSceneBase* GetNextScene();

		/*!
			@brief	シーン切り替え
		**/
		void ChangeScene();
	public:
		/// デストラクタ
		~CSceneManager();

		static CSceneManager* GetInstance();
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