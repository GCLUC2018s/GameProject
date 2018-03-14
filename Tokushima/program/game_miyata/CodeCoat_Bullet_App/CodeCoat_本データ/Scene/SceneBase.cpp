/*!
	@brief	シーンベースクラス cpp
	@author	s.namizashi
**/

#include "SceneBase.hpp"

namespace
{
	// 開始シーンタイプ
	const enSceneType	START_SCENE(STYPE_GAME);
}

enSceneType clSceneBase::sm_NextID(START_SCENE);

// コンストラクタ
clSceneBase::clSceneBase()
{
}

// デストラクタ
clSceneBase::~clSceneBase()
{
}

// 初期化処理
void clSceneBase::Init()
{
}

// 終了処理
void clSceneBase::Finish()
{
}

// 次のシーンID設定
void clSceneBase::SetNext( enSceneType id )
{
	SN_ASSERT(STYPE_NONE <= id && id < STYPE_COUNT);
	if(!(STYPE_NONE <= id && id < STYPE_COUNT)) return;

	sm_NextID = id;
}

// 次のシーンID取得
enSceneType clSceneBase::GetNextID()
{
	return sm_NextID;
}

// 更新処理(継承先用)
void clSceneBase::UpdateSub()
{
}

// 更新処理
void clSceneBase::Update()
{
	// 継承先更新
	UpdateSub();
}

// 描画処理(継承先用)
void clSceneBase::DrawSub()
{
}

// 前面描画処理(継承先用)
void clSceneBase::DrawFTSub()
{
}

// 描画処理
void clSceneBase::Draw()
{
	// 継承先描画
	DrawSub();

	// 継承先前方描画
	DrawFTSub();
}