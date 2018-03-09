/*!
	@brief	敵管理クラス cpp
	@author	s.namizashi
**/

#include "EnemyManager.hpp"

clEnemyManager* clEnemyManager::mp_Instance = nullptr;

clEnemyManager* clEnemyManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new clEnemyManager();
	}
	return mp_Instance;
}

void clEnemyManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
clEnemyManager::clEnemyManager()
	: m_Elapsed(0)
{
}

// デストラクタ
clEnemyManager::~clEnemyManager()
{
}


// 初期化処理
void clEnemyManager::Init()
{
}

// 終了処理
void clEnemyManager::Finish()
{
}

// 敵生成
void clEnemyManager::Create()
{
	// X座標をランダムで取得
	float x = rand() % WINDOW_WIDTH;
	VECTOR2F pos = VECTOR2F(x, 0.0f);
	VECTOR2F vec = VECTOR2F(0.0f, 0.5f);

	// 敵生成
	clEnemy* enemy = new clEnemy();
	enemy->Init(pos, vec);
	// リストに追加
	m_EnemyList.push_back(enemy);
}

// 敵をリストから除外
void clEnemyManager::Remove(clEnemy* enemy)
{
	auto itr = std::find(m_EnemyList.begin(), m_EnemyList.end(), enemy);
	m_EnemyList.erase(itr);
}

// 敵のリスト取得
std::vector<clEnemy*> clEnemyManager::GetEnemyList() const
{
	return m_EnemyList;
}

// 更新処理
void clEnemyManager::Update()
{
	// 一定フレームごとに敵を生成
	m_Elapsed++;
	if (m_Elapsed >= 60 * 1.5f)
	{
		Create();
		m_Elapsed = 0;
	}
}
