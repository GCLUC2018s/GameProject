/*!
@brief	敵管理クラス cpp
@author	s.namizashi
**/

#include "player_manager.h"

CPlayerManager* CPlayerManager::mp_Instance = nullptr;

CPlayerManager* CPlayerManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CPlayerManager();
	}
	return mp_Instance;
}

void CPlayerManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
CPlayerManager::CPlayerManager()
{
}

// デストラクタ
CPlayerManager::~CPlayerManager()
{
}


// 初期化処理
void CPlayerManager::Init(CPlayerControl* player)
{
	m_player = player;
}

// 終了処理
void CPlayerManager::Finish()
{
	delete m_player;
	delete mp_Instance;
}

//主人公のアドレス返却
CPlayerControl* CPlayerManager::GetPlayerAdress() const
{
	return m_player;
}

// 更新処理
void CPlayerManager::Update()
{
}
