/*!
@brief	�G�Ǘ��N���X cpp
@author	s.namizashi
**/

#include "npc_manager.h"
#include "bullet_manager.h"
#include "item_manager.h"
#include "enemy_manager.h"

CNpcManager* CNpcManager::mp_Instance = nullptr;

CNpcManager* CNpcManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CNpcManager();
	}
	return mp_Instance;
}

void CNpcManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// �R���X�g���N�^
CNpcManager::CNpcManager()
{
}

// �f�X�g���N�^
CNpcManager::~CNpcManager()
{
}


// ����������
void CNpcManager::Init(CNpc* npc)
{
	m_npc = npc;
}

// �I������
void CNpcManager::Finish()
{
	delete m_npc;
	delete mp_Instance;
}

//��l���̃A�h���X�ԋp
CNpc* CNpcManager::GetNpcAdress() const
{
	return m_npc;
}

// �X�V����
void CNpcManager::Update()
{
}
