/*!
	@brief	’eŠÇ—ƒNƒ‰ƒX cpp
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

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
clBulletManager::clBulletManager()
{
}

// ƒfƒXƒgƒ‰ƒNƒ^
clBulletManager::~clBulletManager()
{
}


// ‰Šú‰»ˆ—
void clBulletManager::Init()
{
}

// I—¹ˆ—
void clBulletManager::Finish()
{
}

// ’e¶¬
void clBulletManager::Create(VECTOR2F start, VECTOR2F vec)
{
	// ¶¬
	clBullet* bullet = new clBullet();
	bullet->Init(start, vec);
	// ƒŠƒXƒg‚É’Ç‰Á
	m_BulletList.push_back(bullet);
}

// ’e‚ðƒŠƒXƒg‚©‚çœŠO
void clBulletManager::Remove(clBullet* bullet)
{
	auto itr = std::find(m_BulletList.begin(), m_BulletList.end(), bullet);
	m_BulletList.erase(itr);
}

// XVˆ—
void clBulletManager::Update()
{
	// ”­ŽË‚µ‚Ä‚¢‚é’e‚ª0ŒÂ‚Å‚ ‚ê‚Îˆ—‚µ‚È‚¢
	if (m_BulletList.size() == 0) return;

	// “G‚ÌƒŠƒXƒgŽæ“¾
	auto enemyList = clEnemyManager::GetInstance()->GetEnemyList();
	// “G‚Ì”‚ª0‘Ì‚Å‚ ‚ê‚Îˆ—‚µ‚È‚¢
	if (enemyList.size() == 0) return;

	// ’e‚Ì”‚¾‚¯‰ñ‚·
	auto bullet = m_BulletList.begin();
	while (bullet != m_BulletList.end())
	{
		// Ž€‚ñ‚Å‚é’e‚©‚Ç‚¤‚©
		if ((*bullet)->IsKill())
		{
			++bullet;
			continue;
		}

		// ’e‚ÌˆÊ’u
		auto bulletPos = (*bullet)->GetPos();

		// “G‚Ì”‚¾‚¯‰ñ‚µ‚Äƒqƒbƒgƒ`ƒFƒbƒN
		auto enemy = enemyList.begin();
		while (enemy != enemyList.end())
		{
			// Šù‚ÉŽ€‚ñ‚Å‚é“G‚©‚Ç‚¤‚©
			if ((*enemy)->IsKill())
			{
				++enemy;
				continue;
			}

			// “G‚ÌˆÊ’u
			auto enemyPos = (*enemy)->GetPos();

			// ’e‚Æ“G‚Ì‹——£ŒvŽZ
			auto dis = VECTOR2F(enemyPos.x - bulletPos.x, enemyPos.y - bulletPos.y);
			float dist = std::sqrt(dis.x * dis.x + dis.y * dis.y);
			// ˆê’è‹——£ˆÈ‰º‚Å‚ ‚ê‚Î
			if (dist <= 25.0f)
			{
				// ƒqƒbƒg‚µ‚½’e‚Æ“G‚Ìƒ^ƒXƒN‚ðŽE‚·
				(*bullet)->Kill();
				(*enemy)->Kill();
				break;
			}

			// ŽŸ‚Ì“G‚ð’²‚×‚é
			++enemy;
		}

		// ŽŸ‚Ì’e‚ð’²‚×‚é
		++bullet;
	}
}
