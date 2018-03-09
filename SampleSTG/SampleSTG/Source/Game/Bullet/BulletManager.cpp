/*!
	@brief	弾管理クラス cpp
	@author	s.namizashi
**/

#include "BulletManager.hpp"
#include "Source/Game/Enemy/EnemyManager.hpp"

clBulletManager* clBulletManager::mp_Instance = nullptr;

clBulletManager* clBulletManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new clBulletManager();
	}
	return mp_Instance;
}

void clBulletManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
clBulletManager::clBulletManager()
{
}

// デストラクタ
clBulletManager::~clBulletManager()
{
}


// 初期化処理
void clBulletManager::Init()
{
}

// 終了処理
void clBulletManager::Finish()
{
}

// 弾生成
void clBulletManager::Create(VECTOR2F start, VECTOR2F vec)
{
	// 生成
	clBullet* bullet = new clBullet();
	bullet->Init(start, vec);
	// リストに追加
	m_BulletList.push_back(bullet);
}

// 弾をリストから除外
void clBulletManager::Remove(clBullet* bullet)
{
	auto itr = std::find(m_BulletList.begin(), m_BulletList.end(), bullet);
	m_BulletList.erase(itr);
}

// 更新処理
void clBulletManager::Update()
{
	// 発射している弾が0個であれば処理しない
	if (m_BulletList.size() == 0) return;

	// 敵のリスト取得
	auto enemyList = clEnemyManager::GetInstance()->GetEnemyList();
	// 敵の数が0体であれば処理しない
	if (enemyList.size() == 0) return;

	// 弾の数だけ回す
	auto bullet = m_BulletList.begin();
	while (bullet != m_BulletList.end())
	{
		// 死んでる弾かどうか
		if ((*bullet)->IsKill())
		{
			++bullet;
			continue;
		}

		// 弾の位置
		auto bulletPos = (*bullet)->GetPos();

		// 敵の数だけ回してヒットチェック
		auto enemy = enemyList.begin();
		while (enemy != enemyList.end())
		{
			// 既に死んでる敵かどうか
			if ((*enemy)->IsKill())
			{
				++enemy;
				continue;
			}

			// 敵の位置
			auto enemyPos = (*enemy)->GetPos();

			// 弾と敵の距離計算
			auto dis = VECTOR2F(enemyPos.x - bulletPos.x, enemyPos.y - bulletPos.y);
			float dist = std::sqrt(dis.x * dis.x + dis.y * dis.y);
			// 一定距離以下であれば
			if (dist <= 25.0f)
			{
				// ヒットした弾と敵のタスクを殺す
				(*bullet)->Kill();
				(*enemy)->Kill();
				break;
			}

			// 次の敵を調べる
			++enemy;
		}

		// 次の弾を調べる
		++bullet;
	}
}
