/*!
	@brief	���͔���N���X hpp
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

// �R���X�g���N�^
clInputManager::clInputManager()
{
	ZeroMemory(m_IsPushKey,sizeof(m_IsPushKey));
	ZeroMemory(m_IsJudgeKey,sizeof(m_IsJudgeKey));
}

// �f�X�g���N�^
clInputManager::~clInputManager()
{
}

void clInputManager::Init()
{
}

// �w�肵���L�[�������Ă��邩�ǂ���
bool clInputManager::IsOnKey(enKeyType type) const
{
	SN_ASSERT(IK_NONE < type && type < IK_COUNT);
	if(!(IK_NONE < type && type < IK_COUNT)) return false;

	return (CheckHitKey(KEY_TABLE[type]) != 0);
}

// �w�肵���L�[���������u�Ԃ��ǂ���
bool clInputManager::IsPushKey(enKeyType type) const
{
	SN_ASSERT(IK_NONE < type && type < IK_COUNT);
	if(!(IK_NONE < type && type < IK_COUNT)) return false;

	return m_IsPushKey[type];
}

// �X�V����
void clInputManager::Update()
{
	// �������u�Ԃ�1�t���[���̂ݔ��f���A�L�[�𗣂��܂ŃL�[������s��Ȃ�
	for(int i=0;i<IK_COUNT;i++)
	{
		m_IsPushKey[i] = false;
		// �L�[����t���O�������Ă���
		if(m_IsJudgeKey[i])
		{
			// �L�[��������Ă���
			if(CheckHitKey(KEY_TABLE[i]))
			{
				// ����
				m_IsPushKey[i] = true;
				m_IsJudgeKey[i] = false;
			}
		}
		// �L�[����t���O�������Ă��Ȃ�
		else
		{
			// �L�[��������Ă��Ȃ���΁A�L�[����t���O�𗧂Ă�
			if(!CheckHitKey(KEY_TABLE[i])) m_IsJudgeKey[i] = true;
		}
	}
}