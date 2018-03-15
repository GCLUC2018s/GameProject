/*!
@brief	�G�Ǘ��N���X cpp
@author	s.namizashi
**/

#include "ui_manager.h"

CUiManager* CUiManager::mp_Instance = nullptr;

CUiManager* CUiManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CUiManager();
	}
	return mp_Instance;
}

void CUiManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// �R���X�g���N�^
CUiManager::CUiManager()
{
}

// �f�X�g���N�^
CUiManager::~CUiManager()
{
}


// ����������
void CUiManager::Init(Ui* ui)
{
	m_ui = ui;
}

// �I������
void CUiManager::Finish()
{
	delete m_ui;
	delete mp_Instance;
}

//��l���̃A�h���X�ԋp
Ui* CUiManager::GetPlayerAdress() const
{
	return m_ui;
}

// �X�V����
void CUiManager::Update()
{
}