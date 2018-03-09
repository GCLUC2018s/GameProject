/*!
	@brief	入力判定クラス hpp
	@author	s.namizashi
**/

#include "InputManager.hpp"
#include "InputTable.hpp"

clInputManager* clInputManager::mp_Instance = nullptr;

clInputManager* clInputManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new clInputManager();
	}
	return mp_Instance;
}

void clInputManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
clInputManager::clInputManager()
{
	ZeroMemory(m_IsPushKey,sizeof(m_IsPushKey));
	ZeroMemory(m_IsJudgeKey,sizeof(m_IsJudgeKey));
}

// デストラクタ
clInputManager::~clInputManager()
{
}

void clInputManager::Init()
{
}

// 指定したキーを押しているかどうか
bool clInputManager::IsOnKey(enKeyType type) const
{
	SN_ASSERT(IK_NONE < type && type < IK_COUNT);
	if(!(IK_NONE < type && type < IK_COUNT)) return false;

	return (CheckHitKey(KEY_TABLE[type]) != 0);
}

// 指定したキーを押した瞬間かどうか
bool clInputManager::IsPushKey(enKeyType type) const
{
	SN_ASSERT(IK_NONE < type && type < IK_COUNT);
	if(!(IK_NONE < type && type < IK_COUNT)) return false;

	return m_IsPushKey[type];
}

// 更新処理
void clInputManager::Update()
{
	// 押した瞬間の1フレームのみ反映し、キーを離すまでキー判定を行わない
	for(int i=0;i<IK_COUNT;i++)
	{
		m_IsPushKey[i] = false;
		// キー判定フラグが立っている
		if(m_IsJudgeKey[i])
		{
			// キーが押されている
			if(CheckHitKey(KEY_TABLE[i]))
			{
				// 押下
				m_IsPushKey[i] = true;
				m_IsJudgeKey[i] = false;
			}
		}
		// キー判定フラグが立っていない
		else
		{
			// キーが押されていなければ、キー判定フラグを立てる
			if(!CheckHitKey(KEY_TABLE[i])) m_IsJudgeKey[i] = true;
		}
	}
}