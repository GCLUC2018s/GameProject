/*!
	@brief	敵処理クラス cpp
	@author	s.namizashi
**/

#include "Enemy.hpp"
#include "EnemyManager.hpp"

// コンストラクタ
clEnemy::clEnemy()
	: CTask(0, eUDP_Enemy, eDWP_Enemy)
	, m_Pos(0.0f, 0.0f)
	, m_Vec(0.0f, 0.0f)
	, m_IsInitialized(false)
	, m_IsKill(false)
{
}

// デストラクタ
clEnemy::~clEnemy()
{
}

// 初期化処理
void clEnemy::Init(VECTOR2F start, VECTOR2F vec)
{
	m_Pos = start;
	m_Vec = vec;

	m_Image.Load("Enemy.png");

	m_IsInitialized = true;
}

// 終了処理
void clEnemy::Finish()
{
}

void clEnemy::Kill()
{
	m_IsKill = true;
}

// 更新処理
void clEnemy::Update()
{
	// 初期化終わったか
	if (m_IsInitialized)
	{
		// 移動
		m_Pos.x += m_Vec.x;
		m_Pos.y += m_Vec.y;

		// 死んでるか
		if (m_IsKill)
		{
			if (!m_destroyFlg)
			{
				// エネミーのリストから取り除く
				clEnemyManager::GetInstance()->Remove(this);
				// タスクキル
				SetKill();
			}
		}
		// 生きてる
		else
		{
			// 画面外判定
			UVI uv = m_Image.GetUV();
			if (m_Pos.x < -uv.ex || m_Pos.x > WINDOW_WIDTH ||
				m_Pos.y < -uv.ey || m_Pos.y > WINDOW_HEIGHT)
			{
				Kill();
			}
		}
	}

	m_Image.SetPos(m_Pos.x, m_Pos.y);
	m_Image.Update();
}

// 描画処理
void clEnemy::Draw()
{
	m_Image.Draw();
}
