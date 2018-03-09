/*!
	@brief	プレイヤー操作クラス cpp
	@author	s.namizashi
**/

#include "Player.hpp"
#include "Source/Utility/InputManager.hpp"
#include "Source/Game/Bullet/BulletManager.hpp"

// コンストラクタ
clPlayer::clPlayer()
	: CTask(0, eUDP_Player, eDWP_Player)
	, m_Pos(400.0f, 500.0f)
	, m_Elapsed(0)
{
	m_Image.Load("Player.png");
}

// デストラクタ
clPlayer::~clPlayer()
{
}

// 初期化処理
void clPlayer::Init()
{
}

// 終了処理
void clPlayer::Finish()
{
}

// 更新処理
void clPlayer::Update()
{
	// 移動処理
	{
		float move = 10.0f;
		VECTOR2F vec(0.0f, 0.0f);
		bool isMove = false;

		// 十字キーで移動ベクトル設定
		if (clInputManager::GetInstance()->IsOnKey(IK_LEFT))
		{
			vec.x = -1.0f;
			isMove = true;
		}
		else if (clInputManager::GetInstance()->IsOnKey(IK_RIGHT))
		{
			vec.x = 1.0f;
			isMove = true;
		}
		if (clInputManager::GetInstance()->IsOnKey(IK_UP))
		{
			vec.y = -1.0f;
			isMove = true;
		}
		else if (clInputManager::GetInstance()->IsOnKey(IK_DOWN))
		{
			vec.y = 1.0f;
			isMove = true;
		}
		// 移動したか
		if (isMove)
		{
			vec.normalize();
			m_Pos.x += vec.x * move;
			m_Pos.y += vec.y * move;

			// 画面外には移動出来ない
			float width = WINDOW_WIDTH - m_Image.GetUV().ex;
			float height = WINDOW_HEIGHT - m_Image.GetUV().ey;
			if (m_Pos.x < 0.0f) m_Pos.x = 0.0f;
			if (m_Pos.x > width) m_Pos.x = width;
			if (m_Pos.y < 0.0f) m_Pos.y = 0.0f;
			if (m_Pos.y > height) m_Pos.y = height;
		}
	}

	clFont::DebugPrint(VECTOR2I(0, 0), "Pos:%f,%f", m_Pos.x, m_Pos.y);

	// 自機画像更新
	m_Image.SetPos(m_Pos.x, m_Pos.y);
	m_Image.Update();

	// Zキーで自弾発射
	if (clInputManager::GetInstance()->IsOnKey(IK_Z))
	{
		if (m_Elapsed == 0)
		{
			VECTOR2F pos = m_Pos;
			VECTOR2F vec = VECTOR2F(0.0f, -25.0f);
			clBulletManager::GetInstance()->Create(pos, vec);
		}

		m_Elapsed++;
		if (m_Elapsed > 60 * 0.125f)
		{
			m_Elapsed = 0;
		}
	}
	else
	{
		m_Elapsed = 0;
	}
}

// 描画処理
void clPlayer::Draw()
{
	m_Image.Draw();
}
