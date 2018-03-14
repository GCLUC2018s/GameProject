/*!
@brief	�G�Ǘ��N���X cpp
@author	s.namizashi
**/

#include "player_manager.h"

CPlayerManager* CPlayerManager::mp_Instance = nullptr;

CPlayerManager* CPlayerManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CPlayerManager();
	}
	return mp_Instance;
}

void CPlayerManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// �R���X�g���N�^
CPlayerManager::CPlayerManager()
{
}

// �f�X�g���N�^
CPlayerManager::~CPlayerManager()
{
}


// ����������
void CPlayerManager::Init(CPlayerControl* player)
{
	m_player = player;
}

// �I������
void CPlayerManager::Finish()
{
	delete m_player;
	delete mp_Instance;
}

//��l���̃A�h���X�ԋp
CPlayerControl* CPlayerManager::GetPlayerAdress() const
{
	return m_player;
}

// �X�V����
void CPlayerManager::Update()
{
}
