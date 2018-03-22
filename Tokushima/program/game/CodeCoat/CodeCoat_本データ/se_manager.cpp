/*!
@brief	弾丸管理クラス cpp
@author	s.namizashi
**/

#include "se_manager.h"

CSeManager* CSeManager::mp_Instance = nullptr;

CSeManager* CSeManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CSeManager();
	}
	return mp_Instance;
}

void CSeManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
CSeManager::CSeManager()
: m_Elapsed(0)
{
	char *item[] = { "BGM\\neorock52.mp3", "BGM\\kakenukeru.mp3", "BGM\\event40.mp3", 
		"SE\\clear.mp3", "SE\\failed.mp3","SE\\jump.mp3", "SE\\handgun.mp3", "SE\\shotgun.mp3",
		"SE\\tamagire.mp3", "SE\\kiru.wav", "SE\\pi.mp3", "SE\\damage.mp3", "SE\\get.mp3","SE\\purge.mp3" };
	char buf[256];
	for (int i = 0; i < SE_COUNT + BGM_COUNT; i++){
		sprintf_s(buf, "media\\music\\%s", item[i]);
		m_snd[i] = LoadSoundMem(buf);
	}
}

// デストラクタ
CSeManager::~CSeManager()
{
}


// 初期化処理
void CSeManager::Init()
{
}

// 終了処理
void CSeManager::Finish()
{
}

// 更新処理
void CSeManager::Update()
{
}
