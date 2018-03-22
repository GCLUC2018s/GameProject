#include "score_manager.h"

CScoreManager* CScoreManager::mp_Instance = nullptr;

CScoreManager* CScoreManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CScoreManager();
	}
	return mp_Instance;
}

void CScoreManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
CScoreManager::CScoreManager()
: m_Elapsed(0)
{
}

// デストラクタ
CScoreManager::~CScoreManager()
{
}


// 初期化処理
void CScoreManager::Init(ScoreData* player)
{
	m_score = player;
}

// 終了処理
void CScoreManager::Finish()
{
}

// アイテムのリスト取得
ScoreData* CScoreManager::GetPlayerAdress() const
{
	return m_score;
}

// 更新処理
void CScoreManager::Update()
{
}