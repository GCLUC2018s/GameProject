/*!
	@brief	シーンマネージャークラス cpp
	@author	s.namizashi
**/

#include "SceneManager.hpp"

#include "Source/Utility/Font.hpp"

#include "GameScene.hpp"

clSceneManager* clSceneManager::mp_Instance = nullptr;

clSceneManager* clSceneManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new clSceneManager();
	}
	return mp_Instance;
}

void clSceneManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
clSceneManager::clSceneManager()
	: m_Scene(nullptr)
{
}

// デストラクタ
clSceneManager::~clSceneManager()
{
}

// 次のシーンを動的に確保し、返す
clSceneBase* clSceneManager::GetNextScene()
{
	clSceneBase* pScene(nullptr);

	switch(clSceneBase::GetNextID())
	{
		case STYPE_GAME:	pScene = new clGameScene;	break;
	}

	SN_ASSERT(pScene);
	if (!pScene) return nullptr;
	else clSceneBase::SetNext(STYPE_NONE);

	return pScene;
}

// シーン切り替え
void clSceneManager::ChangeScene()
{
	// シーン読み込んでいれば、
	if(m_Scene)
	{
		// 終了処理
		m_Scene->Finish();
		// シーン解放
		SN_SAFE_DELETE(m_Scene);
	}

	// 次のシーン取得
	m_Scene = GetNextScene();
	// 初期化
	if(m_Scene) m_Scene->Init();
}

// 初期化処理
void clSceneManager::Init()
{
}

// 更新処理
void clSceneManager::Update()
{
	// 次のシーンが設定されていれば、
	if(clSceneBase::GetNextID() != STYPE_NONE)
	{
		// シーン切り替え
		ChangeScene();
	}
	// シーン更新
	if(m_Scene) m_Scene->Update();
}
