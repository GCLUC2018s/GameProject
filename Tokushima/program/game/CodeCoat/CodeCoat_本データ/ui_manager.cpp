/*!
@brief	敵管理クラス cpp
@author	s.namizashi
**/

#include "ui_manager.h"

CUiManager* CUiManager::mp_Instance = nullptr;

CUiManager* CUiManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CUiManager();
	}
	return mp_Instance;
}

void CUiManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
CUiManager::CUiManager()
{
}

// デストラクタ
CUiManager::~CUiManager()
{
}


// 初期化処理
void CUiManager::Init(Ui* ui)
{
	m_ui = ui;
}

// 終了処理
void CUiManager::Finish()
{
	delete m_ui;
	delete mp_Instance;
}

//主人公のアドレス返却
Ui* CUiManager::GetPlayerAdress() const
{
	return m_ui;
}

// 更新処理
void CUiManager::Update()
{
}