/*!
	@brief	ゲームシーン cpp
	@author	s.namizashi
**/

#include "GameScene.hpp"
#include "Source/Game/Player/Player.hpp"

// コンストラクタ
clGameScene::clGameScene()
{
}

// デストラクタ
clGameScene::~clGameScene()
{
}

// 初期化処理
void clGameScene::Init()
{
	m_Player = new clPlayer();
}

// 終了処理
void clGameScene::Finish()
{
}

// 更新処理
void clGameScene::UpdateSub()
{
}

// 描画処理
void clGameScene::DrawSub()
{
}
