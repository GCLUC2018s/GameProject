/*!
@brief	敵管理クラス cpp
@author	s.namizashi
**/

#include "npc_manager.h"
#include "bullet_manager.h"
#include "item_manager.h"
#include "enemy_manager.h"

CNpcManager* CNpcManager::mp_Instance = nullptr;

CNpcManager* CNpcManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CNpcManager();
	}
	return mp_Instance;
}

void CNpcManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
CNpcManager::CNpcManager()
{
}

// デストラクタ
CNpcManager::~CNpcManager()
{
}


// 初期化処理
void CNpcManager::Init(CNpc* npc)
{
	m_npc = npc;
}

// 終了処理
void CNpcManager::Finish()
{
	delete m_npc;
	delete mp_Instance;
}

//主人公のアドレス返却
CNpc* CNpcManager::GetNpcAdress() const
{
	return m_npc;
}

// 更新処理
void CNpcManager::Update()
{
}
