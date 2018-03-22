/*!
@brief	敵管理クラス cpp
@author	s.namizashi
**/

#include "map_manager.h"

CMapManager* CMapManager::mp_Instance = nullptr;

CMapManager* CMapManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CMapManager();
	}
	return mp_Instance;
}

void CMapManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
CMapManager::CMapManager()
: m_Elapsed(0)
{
}

// デストラクタ
CMapManager::~CMapManager()
{
}


// 初期化処理
void CMapManager::Init(CMapControl* player)
{
	m_map = player;
}

// 終了処理
void CMapManager::Finish()
{
}

// アイテムのリスト取得
CMapControl* CMapManager::GetMapAdress() const
{
	return m_map;
}

// 更新処理
void CMapManager::Update()
{
	// 一定フレームごとに敵を生成
	/*m_Elapsed++;
	if (m_Elapsed >= 60 * 1.5f)
	{
	Create();
	m_Elapsed = 0;
	}*/
}
