/*!
@brief	�G�Ǘ��N���X cpp
@author	s.namizashi
**/

#include "map_manager.h"

CMapManager* CMapManager::mp_Instance = nullptr;

CMapManager* CMapManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CMapManager();
	}
	return mp_Instance;
}

void CMapManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// �R���X�g���N�^
CMapManager::CMapManager()
: m_Elapsed(0)
{
}

// �f�X�g���N�^
CMapManager::~CMapManager()
{
}


// ����������
void CMapManager::Init(CMapControl* player)
{
	m_map = player;
}

// �I������
void CMapManager::Finish()
{
}

// �A�C�e���̃��X�g�擾
CMapControl* CMapManager::GetMapAdress() const
{
	return m_map;
}

// �X�V����
void CMapManager::Update()
{
	// ���t���[�����ƂɓG�𐶐�
	/*m_Elapsed++;
	if (m_Elapsed >= 60 * 1.5f)
	{
	Create();
	m_Elapsed = 0;
	}*/
}
